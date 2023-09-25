//
// Created by afox on 9/10/23.
//

#include "BitArray.h"

#include <exception>
#include <utility>

CELL_TYPE BitArray::set_bit_in_cell(CELL_TYPE cell, uint8_t pos, bool value) {
    return value ? (cell | (1 << pos)) : (cell & ~(1 << pos));
}

void BitArray::set_bit(uint8_t cell_ind, uint8_t pos, bool value) {
    if (pos >= CELL_SIZE) { throw std::exception(); }
    if (cell_ind >= bits.bit_vector.size()) { throw std::exception(); }
    // if ( (cell_ind + 1) * CELL_SIZE + (pos + 1) > this->bits.last_bit) { throw std::exception(); }
    bits.bit_vector[cell_ind] = set_bit_in_cell(
            bits.bit_vector[cell_ind],
            pos,
            value
            );
}

BitArray::BitArray(bits_t bits_copy) : bits{std::move(bits_copy)} {
}

BitArray::BitArray(const BitArray & b) : BitArray({
    std::vector<CELL_TYPE>(b.bits.bit_vector),
    b.bits.last_bit}) {
}

void BitArray::swap(BitArray & b) {
    bits_t tmp = this->bits;
    this->bits = b.bits;
    b.bits = tmp;
}

BitArray & BitArray::operator=(const BitArray & b) {
    if (this == &b) { throw std::exception(); }
    this->bits = {std::vector<CELL_TYPE>(b.bits.bit_vector),
            bits.last_bit};
    return *this;
}

void BitArray::create_empty_cell() {
    this->bits.bit_vector.push_back((CELL_TYPE) 0);
}

void BitArray::clear() {
    this->bits.last_bit = 0;
    this->bits.bit_vector = std::vector<CELL_TYPE>();
}

void BitArray::push_back(bool bit) {
    while (bits.last_bit >= bits.bit_vector.size() * CELL_SIZE) {
        create_empty_cell();
    }
    set_bit(bits.last_bit / CELL_SIZE,
            bits.last_bit % CELL_SIZE, // + 1?
            bit);
    bits.last_bit++;
}

bool BitArray::any() const {
    return std::any_of(bits.bit_vector.begin(),
                       bits.bit_vector.end(),
                       [](CELL_TYPE i){return i != 0;});
}

bool BitArray::none() const {
    return std::all_of(bits.bit_vector.begin(),
                       bits.bit_vector.end(),
                       [](CELL_TYPE i){return i == 0;});
}

int BitArray::count() const {
    int count = 0;
    for (CELL_TYPE cell : bits.bit_vector) {
        for(int i = 0; i < CELL_SIZE; i++) {
            count += (cell >> i) & 0x01;
        }
    }
    return count;
}

int BitArray::size() const {
    return bits.last_bit;
}

bool BitArray::empty() const {
    return bits.last_bit == 0;
}

std::string BitArray::to_string() const {
    std::string str_bits;
    for (int j = 0; j < bits.bit_vector.size(); j++) {
        CELL_TYPE cell = bits.bit_vector[j];
        for(int i = 0; i < CELL_SIZE; i++) {
            if (j * CELL_SIZE + i == bits.last_bit) {
                return str_bits;
            }
            str_bits += std::to_string((cell >> i) & 0x01);
        }
    }
}

BitArray::BitArray(int num_bits, unsigned long value) {
    for (int i = 0; i < num_bits / CELL_SIZE + 1; i++) {
        create_empty_cell();
    }
    if (value != 0) {
        for (int i = 0; i < MIN(sizeof(long), num_bits) * 8; i++) {
            this->push_back((value >> i) & 0x01);
        }
    }
}

BitArray &BitArray::set() {
    for (int j = 0; j < bits.bit_vector.size(); j++) {
        for(int i = 0; i < CELL_SIZE; i++) {
            if (j * CELL_SIZE + i == bits.last_bit) {
                return *this;
            }
            this->set_bit(j, i, true);
        }
    }
}

BitArray &BitArray::set(int n, bool val) {
    if (n >= bits.last_bit) {
        throw std::exception();
    }
    this->set_bit(n / CELL_SIZE, n % CELL_SIZE, val);
    return *this;
}

BitArray &BitArray::reset() {
    for (int j = 0; j < bits.bit_vector.size(); j++) {
        for(int i = 0; i < CELL_SIZE; i++) {
            if (j * CELL_SIZE + i == bits.last_bit) {
                return *this;
            }
            this->set_bit(j, i, false);
        }
    }
}

BitArray &BitArray::reset(int n) {
    return this->set(n, false);
}

bool BitArray::operator[](int i) const {
    if (i >= bits.last_bit) { throw std::exception(); }
    return bool((1 << i % CELL_SIZE) & bits.bit_vector[i / CELL_SIZE]);
}

BitArray BitArray::operator~() const {
    BitArray inv_bitArray = BitArray(*this);
    for (int j = 0; j < bits.bit_vector.size(); j++) {
        for(int i = 0; i < CELL_SIZE; i++) {
            if (j * CELL_SIZE + i == bits.last_bit) {
                return inv_bitArray;
            }
            bool source_bit = bool((*this)[j * CELL_SIZE + i]);
            inv_bitArray.set_bit(j,
                                 i,
                                 !source_bit
                                 );
        }
    }
}

BitArray &BitArray::operator&=(const BitArray &b) {
    BitArray conj_bitArray = *this & b;
    this->swap(conj_bitArray);
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    BitArray conj_bitArray = *this | b;
    this->swap(conj_bitArray);
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    BitArray conj_bitArray = *this ^ b;
    this->swap(conj_bitArray);
    return *this;
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) { return false; }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) { return false; }
    }
    return true;
}

bool operator!=(const BitArray & a, const BitArray & b) {
    return !operator==(a, b);
}

BitArray operator&(const BitArray & b1, const BitArray & b2) {
    BitArray conj_bitArray = BitArray();
    if (b1.size() != b2.size()) { throw std::exception(); }
    for (int i = 0; i < b1.size(); i++) {
        conj_bitArray.push_back(bool(b1[i] && b2[i]));
    }
    return conj_bitArray;
}

BitArray operator|(const BitArray & b1, const BitArray & b2) {
    BitArray conj_bitArray = BitArray();
    if (b1.size() != b2.size()) { throw std::exception(); }
    for (int i = 0; i < b1.size(); i++) {
        conj_bitArray.push_back(bool(b1[i] || b2[i]));
    }
    return conj_bitArray;
}

BitArray operator^(const BitArray & b1, const BitArray & b2) {
    BitArray conj_bitArray = BitArray();
    if (b1.size() != b2.size()) { throw std::exception(); }
    for (int i = 0; i < b1.size(); i++) {
        conj_bitArray.push_back(bool(b1[i] != b2[i]));
    }
    return conj_bitArray;
}
