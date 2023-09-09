//
// Created by afox on 9/9/23.
//

#include "word_counter.h"
#include "utils.h"
#include <iostream>
#include <map>
#include <string>
#include <set>

struct comp {
    template <typename T>

    // Comparator function
    bool operator()(const T& l, const T& r) const {
        if (l.second != r.second) {
            return l.second > r.second;
        }
        return l.first > r.first;
    }
};

static set<pair<string, int>, comp> map_to_sorted_set(map<string, int>& M) {

    // Declare set of pairs and insert
    // pairs according to the comparator
    // function comp()
    set<pair<string, int>, comp> S(M.begin(), M.end());

    return S;
}

void count_words(ifstream & in_file, ofstream & out_file) {
    int word_counter = 0;
    map<string, int> freq_map;
    string buf;
    while (!in_file.eof()) {
        getline(in_file, buf);
        list<string> words;
        split(buf, words);
        for (const auto & word : words) {
            word_counter++;
            if (freq_map.count(word) == 0) {
                freq_map[word] = 1;
            } else {
                freq_map[word]++;
            }
        }
    }

    set<pair<string, int>, comp> sorted_pairs = map_to_sorted_set(freq_map);
    for (const auto& p : sorted_pairs) {
        out_file << p.first
            << ','
            << p.second
            << ','
            << get_percentage(word_counter, p.second)
            << endl;
    }
}
