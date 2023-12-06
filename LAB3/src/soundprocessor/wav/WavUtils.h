//
// Created by afox on 10/29/23.
//

#ifndef LAB3_WAVUTILS_H
#define LAB3_WAVUTILS_H

struct WavHeader {
    char chunkId[4];
    unsigned int chunkSize;
    char format[4];
    char subchunk1Id[4];
    unsigned int subchunk1Size;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned int sampleRate;
    unsigned int byteRate;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char subchunk2Id[4];
    unsigned int subchunk2Size;
};

struct List {
    char list[4];
    unsigned int list_size;
};

#include <fstream>

class WavUtils { // TODO распределить логику
public:
    static void read_header(WavHeader *header, std::ifstream &input) {
        input.read(reinterpret_cast<char *>(header), sizeof(WavHeader) - 8);

        char data[4];
        input.read(reinterpret_cast<char *>(data), 4);

        if (std::string(data, 4) == "LIST") {
            std::vector<char> buffer(4);
            input.read(buffer.data(), 4);
            unsigned int list_size = *reinterpret_cast<unsigned *>(buffer.data());
            input.seekg(list_size, std::ios::cur);
            input.read(reinterpret_cast<char *>(header) + (sizeof(WavHeader) - 8), 8);
        } else {
            header->subchunk2Id[0] = 'd';
            header->subchunk2Id[1] = 'a';
            header->subchunk2Id[2] = 't';
            header->subchunk2Id[3] = 'a';
            input.read(reinterpret_cast<char *>(header) + (sizeof(WavHeader) - 4), 4);
        }

    }

    static void write_header(WavHeader *header, std::ofstream &output) {
        output.write(reinterpret_cast<char *>(header), sizeof(WavHeader));
    }

    static bool is_not_valid(WavHeader header) {
        return std::string(header.chunkId, 4) != "RIFF"
               || std::string(header.format, 4) != "WAVE"
               || header.audioFormat != 1
               || header.numChannels != 1
               || header.bitsPerSample != 16
               || std::string(header.subchunk1Id, 4) != "fmt "
               || std::string(header.subchunk2Id, 4) != "data";
    }

};

#endif //LAB3_WAVUTILS_H
