//
// Created by afox on 10/28/23.
//

#include <vector>
#include "MuteTask.h"
#include "../../wav/WavUtils.h"
#include <utility>

MuteTask::MuteTask(std::string file_p, int s, int e) {
    file_path = std::move(file_p);
    start = s;
    end = e;
}

void MuteTask::process() {
    std::ifstream input(file_path, std::ios::binary);
    std::ofstream tmp(TEMPORARY_FILE_PATH, std::ios::binary);

    if (!input || !tmp) {
        throw IOException();
    }

    WavHeader header{};
    WavUtils::read_header(&header, input);

    if (WavUtils::is_not_valid(header)) {
        throw std::exception();
    }

    WavUtils::write_header(&header, tmp);

    int bytes_per_sample = header.bitsPerSample / 8;
    std::vector<char> buffer(bytes_per_sample * header.sampleRate);
    std::vector<char> muted(bytes_per_sample * header.sampleRate);
    std::fill(muted.begin(), muted.end(), 0);

    unsigned start_interval = start == -1
                         ? 0
                         : start * header.sampleRate;

    unsigned end_interval = end == -1
                       ? header.subchunk2Size / bytes_per_sample
                       : end * header.sampleRate;

    for (unsigned int i = 0;
         i < header.subchunk2Size / bytes_per_sample;
         i += header.sampleRate) {

        input.read(buffer.data(), bytes_per_sample * header.sampleRate);
        tmp.write(
                (i < start_interval || i > end_interval)
                ? (buffer.data())
                : muted.data(),
                (long) buffer.size()
        );
    }

    input.close();
    tmp.close();

    copy_file(TEMPORARY_FILE_PATH, file_path);
}
