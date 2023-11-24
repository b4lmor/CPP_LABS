//
// Created by afox on 10/29/23.
//

#include <vector>
#include "CompressTask.h"
#include "../../wav/WavUtils.h"
#include "../../../exception/BadInputException.h"

CompressTask::CompressTask(
        std::string file_path,
        int percentage) {
    this->file_path = std::move(file_path);
    this->percentage = percentage;
}

void CompressTask::process() {
    std::ifstream input(file_path, std::ios::binary);
    std::ofstream tmp(TEMPORARY_FILE_PATH, std::ios::binary);

    if (!input || !tmp) {
        throw IOException();
    }

    WavHeader header{};
    WavUtils::read_header(&header, input);

    if (WavUtils::is_not_valid(header)) {
        throw BadInputException();
    }

    double k = 100.0 / percentage;
    double cur_k = k;

    WavUtils::write_header(&header, tmp);

    int bytes_per_sample = header.bitsPerSample / 8;
    std::vector<char> buffer(bytes_per_sample);

    for (unsigned int i = 0; i < header.subchunk2Size / bytes_per_sample; i++) {
        input.read(buffer.data(), bytes_per_sample);

        if (i > cur_k) {
            short sample = *reinterpret_cast<short *>(buffer.data());
            cur_k += k;
            tmp.write(
                    reinterpret_cast<char *>(&sample),
                    bytes_per_sample
            );
        }
    }

    input.close();
    tmp.close();

    copy_file(TEMPORARY_FILE_PATH, file_path);
}
