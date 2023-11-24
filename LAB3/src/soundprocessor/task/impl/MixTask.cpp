//
// Created by afox on 10/28/23.
//

#include <vector>
#include "MixTask.h"
#include "../../wav/WavUtils.h"
#include "../../../exception/BadInputException.h"
#include <utility>

#define MIN(a, b) (a < b ? a :b)

static std::vector<char> sum_vectors(
        const std::vector<char> &vec1,
        const std::vector<char> &vec2) {
    std::vector<char> result;
    if (vec1.size() != vec2.size()) {
        return result;
    }
    for (size_t i = 0; i < vec1.size(); i++) {
        result.push_back(vec1[i] + vec2[i]);
    }
    return result;
}

MixTask::MixTask(
        std::string file_p,
        int s, int e,
        std::string mix_file_p) {
    file_path = std::move(file_p);
    start = s;
    end = e;
    mix_file_path = std::move(mix_file_p);
}

void MixTask::process() {
    std::ifstream input(file_path, std::ios::binary);
    std::ifstream mix_input(mix_file_path, std::ios::binary);
    std::ofstream tmp(TEMPORARY_FILE_PATH, std::ios::binary);

    if (!input || !tmp || !mix_input) {
        throw IOException();
    }

    WavHeader header{};
    WavUtils::read_header(&header, input);
    WavHeader mix_header{};
    WavUtils::read_header(&mix_header, mix_input);

    if (WavUtils::is_not_valid(header) || WavUtils::is_not_valid(mix_header)) {
        throw BadInputException();
    }

    WavUtils::write_header(&header, tmp);

    int bytes_per_sample = header.bitsPerSample / 8;
    std::vector<char> buffer(bytes_per_sample * header.sampleRate);
    std::vector<char> mix_buffer(bytes_per_sample * header.sampleRate);

    unsigned start_interval = start == -1
                              ? 0
                              : start * header.sampleRate;

    unsigned end_interval = end == -1
                            ? MIN(header.subchunk2Size,
                                  mix_header.subchunk2Size) / bytes_per_sample
                            : end * header.sampleRate;

    for (unsigned int i = 0;
         i < MIN(header.subchunk2Size,
                  mix_header.subchunk2Size) / bytes_per_sample;
         i += header.sampleRate) {

        input.read(buffer.data(), bytes_per_sample * header.sampleRate);
        mix_input.read(mix_buffer.data(), bytes_per_sample * header.sampleRate);
        tmp.write(
                (i < start_interval || i > end_interval)
                ? (buffer.data())
                : sum_vectors(buffer, mix_buffer).data(),
                (long) buffer.size()
        );
    }

    input.close();
    tmp.close();

    copy_file(TEMPORARY_FILE_PATH, file_path);
}
