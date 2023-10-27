//
// Created by afox on 9/10/23.
//

#include "BitArray.h"

#include "exception/BadBitPositionException.h"
#include "exception/BadCellIndexException.h"
#include "exception/AssignmentToOwnerException.h"
#include "exception/DifferentSizeException.h"

#include <utility>

#define MIN(a, b) ((a < b) ? a : b)

static BitArray use_bit_operator(const BitArray & b1,
                                 const BitArray & b2,
                                 Operation_t operation) {
    if (b1.size() != b2.size()) {
        throw DifferentSizeException();
    }

    BitArray result = BitArray();

    for (int i = 0; i < b1.size(); i++) {
        bool to_push;

        switch (operation) {
            case Operation_t::CONJUNCTION:
                to_push = b1[i] && b2[i];
                break;
            case Operation_t::DISJUNCTION:
                to_push = b1[i] || b2[i];
                break;
            case Operation_t::XOR:
                to_push = b1[i] != b2[i];
                break;
        }

        result.push_back(to_push);
    }

    return result;
}

static void use_bit_operator_for_itself(BitArray * b1,
                                 const BitArray & b2,
                                 Operation_t operation) {
    if (b1->size() != b2.size()) {
        throw DifferentSizeException();
    }

    for (int i = 0; i < b1->size(); i++) {
        bool to_set;

        switch (operation) {
            case Operation_t::CONJUNCTION:
                to_set = (*b1)[i] && b2[i];
                break;
            case Operation_t::DISJUNCTION:
                to_set = (*b1)[i] || b2[i];
                break;
            case Operation_t::XOR:
                to_set = (*b1)[i] != b2[i];
                break;
        }

        b1->set(i, to_set);
    }
}

CELL_TYPE BitArray::set_bit_in_cell(CELL_TYPE cell, uint8_t pos, bool value) {
    return value ? (cell | (1 << pos)) : (cell & ~(1 << pos));
}

void BitArray::set_bit(uint8_t cell_ind, uint8_t pos, bool value) {
    if (pos >= CELL_SIZE) {
        throw BadBitPositionException();
    }

    if (cell_ind >= bits.bit_vector.size()) {
        throw BadCellIndexException();
    }

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
    b.bits.last_bit
}) {
}

void BitArray::swap(BitArray & b) {
    bits_t tmp = this->bits;
    this->bits = b.bits;
    b.bits = tmp;
}

BitArray & BitArray::operator=(const BitArray & b) {
    if (this == &b) {
        throw AssignmentToOwnerException();
    }

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
            bits.last_bit % CELL_SIZE,
            bit);

    bits.last_bit++;
}

bool BitArray::any() const {
    return std::any_of(bits.bit_vector.begin(),
                       bits.bit_vector.end(),
                       [](CELL_TYPE i){ return i != 0; });
}

bool BitArray::none() const {
    return std::all_of(bits.bit_vector.begin(),
                       bits.bit_vector.end(),
                       [](CELL_TYPE i){ return i == 0; });
}

int BitArray::count() const {
    int count = 0;

    for (int n = 0; n < bits.last_bit; n++) {
        count += (int) (*this)[n];
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

    for (int n = 0; n < bits.last_bit; n++) {
        str_bits += std::to_string((*this)[n]);
    }

    return str_bits;
}

BitArray::BitArray(int num_bytes, unsigned long value) {
    for (int i = 0; i < num_bytes; i++) {
        create_empty_cell();
    }

    if (value != 0) {
        for (int i = 0; i < MIN(sizeof(long), num_bytes) * CELL_SIZE; i++) {
            this->push_back((value >> i) & 0x01);
        }
    }
}

//BitArray::BitArray(int num_bits, unsigned long value) {
//    for (int i = 0; i < num_bits / CELL_SIZE + 1; i++) {
//        create_empty_cell();
//    }
//
//    if (value != 0) {
//        for (int i = 0; i < MIN(sizeof(long) * (int) CELL_SIZE, num_bits); i++) {
//            this->push_back((value >> i) & 0x01);
//        }
//    }
//}

BitArray & BitArray::set() {
    for (int n = 0; n < bits.last_bit; n++) {
        this->set(n, true);
    }

    return *this;
}

BitArray &BitArray::set(int n, bool val) {
    if (n >= bits.last_bit || n < 0) {
        throw BadBitPositionException();
    }

    this->set_bit(n / CELL_SIZE, n % CELL_SIZE, val);
    return *this;
}

BitArray &BitArray::reset() {
    for (unsigned char & j : bits.bit_vector) {
        j = 0;
    }

    return *this;
}

BitArray &BitArray::reset(int n) {
    if (n >= bits.last_bit || n < 0) {
        throw BadBitPositionException();
    }

    return this->set(n, false);
}

bool BitArray::operator[](int i) const {
    if (i >= bits.last_bit || i < 0) {
        throw BadBitPositionException();
    }

    return bool((1 << i % CELL_SIZE) & bits.bit_vector[i / CELL_SIZE]);
}

BitArray BitArray::operator~() {
    for (int n = 0; n < bits.last_bit; n++) {
        this->set(n, !(*this)[n]);
    }

    return *this;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    use_bit_operator_for_itself(this,
                                b,
                                Operation_t::CONJUNCTION);
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    use_bit_operator_for_itself(this,
                                b,
                                Operation_t::DISJUNCTION);
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    use_bit_operator_for_itself(this,
                                b,
                                Operation_t::XOR);
    return *this;
}

BitArray BitArray::operator<<(int n) const {
    BitArray shifted_bitArray = BitArray();

    for (int i = n; i < this->size(); i++) {
        shifted_bitArray.push_back((*this)[i]);
    }

    for (int i = 0; i < n; i++) {
        shifted_bitArray.push_back(false);
    }

    return shifted_bitArray;
}

BitArray BitArray::operator>>(int n) const {
    BitArray shifted_bitArray = BitArray();

    for (int i = 0; i < n; i++) {
        shifted_bitArray.push_back(false);
    }

    for (int i = 0; i < this->size() - n; i++) {
        shifted_bitArray.push_back((*this)[i]);
    }

    return shifted_bitArray;
}

BitArray &BitArray::operator<<=(int n) {
    int index = 0;

    for (int i = n; i < this->size(); i++) {
        this->set(index++, (*this)[i]);
    }

    for (int i = 0; i < n; i++) {
        this->set(index++, false);
    }

    return *this;
}

BitArray &BitArray::operator>>=(int n) {
    int index = this->size() - n;

    if (n < 0) {
        reset();
        return *this;
    }

    for (int i = 0; i < this->size() - n; i++) {
        this->set(index++, (*this)[i]);
    }

    index = 0;

    for (int i = 0; i < n; i++) {
        this->set(index++, false);
    }

    return *this;
}

void BitArray::resize(int num_bits, bool value) {
    if (num_bits > this->size()) {

        while (num_bits > this->size()) {
            this->push_back(value);
        }

    } else {

        while (num_bits < this->size()) {
            this->set(bits.last_bit - 1, false);
            bits.last_bit--;
        }

        int cell_number = num_bits / (int) CELL_SIZE + 1;

        while (cell_number < bits.bit_vector.size()) {
            bits.bit_vector.pop_back();
        }
    }
}

bool operator==(const BitArray & a, const BitArray & b) {
    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const BitArray & a, const BitArray & b) {
    return !operator==(a, b);
}

BitArray operator&(const BitArray & b1, const BitArray & b2) {
    return use_bit_operator(b1, b2, Operation_t::CONJUNCTION);
}

BitArray operator|(const BitArray & b1, const BitArray & b2) {
    return use_bit_operator(b1, b2, Operation_t::DISJUNCTION);
}

BitArray operator^(const BitArray & b1, const BitArray & b2) {
    return use_bit_operator(b1, b2, Operation_t::XOR);
}
