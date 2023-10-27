//
// Created by afox on 9/25/23.
//

#include <gtest/gtest.h>
#include "../src/BitArray.h"

TEST(BitArrayTests, EmptyConstructor) {
    BitArray bitArray;
    ASSERT_EQ(bitArray.size(), 0);
    ASSERT_TRUE(bitArray.to_string().empty());
}

TEST(BitArrayTests, ByValueConstructor) {
    BitArray bitArray = BitArray(3, 31);
    ASSERT_EQ(bitArray.size(), 3 * CELL_SIZE);
    ASSERT_EQ(bitArray.to_string(), "111110000000000000000000");
}

TEST(BitArrayTests, CopyConstructor) {
    BitArray bitArray = BitArray(3, 31);
    BitArray bitArray_copy = BitArray(bitArray);
    ASSERT_EQ(bitArray_copy.size(), 3 * CELL_SIZE);
    ASSERT_EQ(bitArray_copy.to_string(), "111110000000000000000000");
}

TEST(BitArrayTests, Swap) {
    BitArray bitArray1 = BitArray(3, 31);
    BitArray bitArray2 = BitArray(1, 8);
    bitArray1.swap(bitArray2);

    ASSERT_EQ(bitArray1.size(), 1 * CELL_SIZE);
    ASSERT_EQ(bitArray2.size(), 3 * CELL_SIZE);
    ASSERT_EQ(bitArray1.to_string(), "00010000");
    ASSERT_EQ(bitArray2.to_string(), "111110000000000000000000");
}

TEST(BitArrayTests, Operator_eq) {
    BitArray bitArray1 = BitArray(1, 8);
    BitArray bitArray2 = bitArray1;
    bitArray1.push_back(true);
    ASSERT_NE(bitArray1.size(), bitArray2.size());
    ASSERT_NE(bitArray1.to_string(), bitArray2.to_string());
}

TEST(BitArrayTests, Clear) {
    BitArray bitArray = BitArray(1, 8);
    bitArray.clear();
    ASSERT_EQ(bitArray.size(), 0);
    ASSERT_TRUE(bitArray.to_string().empty());
}

TEST(BitArrayTests, PushBack_and_Size_and_ToString) {
    BitArray bitArray = BitArray(2, 8);
    bitArray.push_back(true);
    bitArray.push_back(false);
    bitArray.push_back(true);
    ASSERT_EQ(bitArray.size(), 3 + 2 * CELL_SIZE);
    ASSERT_EQ(bitArray.to_string(), "0001000000000000101");
}

TEST(BitArrayTests, SetAllTrue) {
    BitArray bitArray = BitArray(2, 8);
    bitArray.set();
    ASSERT_EQ(bitArray.size(), 2 * CELL_SIZE);
    ASSERT_EQ(bitArray.to_string(), "1111111111111111");
}

TEST(BitArrayTests, SetBit) {
    BitArray bitArray = BitArray(1, 8);
    bitArray.set(6, true);
    ASSERT_EQ(bitArray.size(), 1 * CELL_SIZE);
    ASSERT_EQ(bitArray.to_string(), "00010010");
}

TEST(BitArrayTests, Reset) {
    BitArray bitArray = BitArray(1, 63);
    bitArray.reset();
    ASSERT_EQ(bitArray.size(), 1 * CELL_SIZE);
    ASSERT_EQ(bitArray.to_string(), "00000000");
}

TEST(BitArrayTests, ResetBit) {
    BitArray bitArray = BitArray(1, 8);
    bitArray.reset(3);
    ASSERT_EQ(bitArray.size(), 1 * CELL_SIZE);
    ASSERT_EQ(bitArray.to_string(), "00000000");
}

TEST(BitArrayTests, Any) {
    BitArray bitArray = BitArray(1, 8);
    ASSERT_TRUE(bitArray.any());
    bitArray = BitArray(4, 0);
    ASSERT_FALSE(bitArray.any());
}

TEST(BitArrayTests, None) {
    BitArray bitArray = BitArray(1, 44);
    ASSERT_FALSE(bitArray.none());
    bitArray = BitArray(2, 0);
    ASSERT_TRUE(bitArray.none());
}

TEST(BitArrayTests, Count) {
    BitArray bitArray = BitArray(1, 31);
    ASSERT_EQ(bitArray.count(), 5);
    bitArray = BitArray(4, 255);
    ASSERT_EQ(bitArray.count(), 8);
}

TEST(BitArrayTests, Inversion) {
    BitArray bitArray = BitArray(2, 1023);
    BitArray bitArray_inv = ~bitArray;
    ASSERT_EQ(bitArray_inv.to_string(), "0000000000111111");
}

TEST(BitArrayTests, SqBrackets) {
    BitArray bitArray = BitArray(1, 31);
    ASSERT_EQ(bitArray[0], true);
    ASSERT_EQ(bitArray[1], true);
    ASSERT_EQ(bitArray[2], true);
    ASSERT_EQ(bitArray[3], true);
    ASSERT_EQ(bitArray[4], true);
    ASSERT_EQ(bitArray[5], false);
    ASSERT_EQ(bitArray[6], false);
    ASSERT_EQ(bitArray[7], false);
}

TEST(BitArrayTests, Equals) {
    BitArray bitArray1 = BitArray(2, 1023);
    BitArray bitArray2 = BitArray(2, 1023);
    ASSERT_TRUE(bitArray1 == bitArray2);
}

TEST(BitArrayTests, NotEquals) {
    BitArray bitArray1 = BitArray(2, 1022);
    BitArray bitArray2 = BitArray(2, 1023);
    ASSERT_TRUE(bitArray1 != bitArray2);
}

TEST(BitArrayTests, Conjunction) {
    BitArray bitArray1 = BitArray(1, 63);
    BitArray bitArray2 = BitArray(1, 31);
    ASSERT_TRUE((bitArray1 & bitArray2) == bitArray2);
}

TEST(BitArrayTests, Disjunction) {
    BitArray bitArray1 = BitArray(1, 63);
    BitArray bitArray2 = BitArray(1, 31);
    ASSERT_TRUE((bitArray1 | bitArray2) == bitArray1);
}

TEST(BitArrayTests, XOR) {
    BitArray bitArray1 = BitArray(1, 63);
    BitArray bitArray2 = BitArray(1, 31);
    ASSERT_EQ((bitArray1 ^ bitArray2).to_string(), "00000100");
}

TEST(BitArrayTests, EqConjunction) {
    BitArray bitArray1 = BitArray(1, 63);
    BitArray bitArray2 = BitArray(1, 31);
    bitArray1 &= bitArray2;
    ASSERT_EQ(bitArray1, bitArray2);
}

TEST(BitArrayTests, EqDisjunction) {
    BitArray bitArray1 = BitArray(1, 63);
    BitArray bitArray2 = BitArray(1, 31);
    bitArray2 |= bitArray1;
    ASSERT_EQ(bitArray1, bitArray2);
}

TEST(BitArrayTests, EqXOR) {
    BitArray bitArray1 = BitArray(1, 63);
    BitArray bitArray2 = BitArray(1, 31);
    bitArray2 ^= bitArray1;
    ASSERT_EQ(bitArray2.to_string(), "00000100");
}

TEST(BitArrayTests, LeftShift) {
    BitArray bitArray1 = BitArray(1, 31);
    BitArray bitArray2 = bitArray1 << 3;
    ASSERT_EQ(bitArray2.to_string(), "11000000");

    bitArray2 = bitArray1 << 100;
    ASSERT_EQ(bitArray2.to_string(), "00000000");
}

TEST(BitArrayTests, RightShift) {
    BitArray bitArray1 = BitArray(1, 31);
    BitArray bitArray2 = bitArray1 >> 3;
    ASSERT_EQ(bitArray2.to_string(), "00011111");

    bitArray2 = bitArray1 >> 100;
    ASSERT_EQ(bitArray2.to_string(), "00000000");
}

TEST(BitArrayTests, EqLeftShift) {
    BitArray bitArray = BitArray(1, 31);
    bitArray <<= 4;
    ASSERT_EQ(bitArray.to_string(), "10000000");
}

TEST(BitArrayTests, EqRightShift) {
    BitArray bitArray = BitArray(1, 31);
    bitArray >>= 4;
    ASSERT_EQ(bitArray.to_string(), "00001111");
}

TEST(BitArrayTests, Resize) {
    BitArray bitArray1 = BitArray(1, 31);
    bitArray1.resize(11, true);
    ASSERT_EQ(bitArray1.size(), 11);
    ASSERT_EQ(bitArray1.to_string(), "11111000111");

    BitArray bitArray2 = BitArray(1, 31);
    bitArray2.resize(5);
    ASSERT_EQ(bitArray2.size(), 5);
    ASSERT_EQ(bitArray2.to_string(), "11111");
}

TEST(BitArrayTests, Empty) {
    BitArray bitArray1 = BitArray(1, 31);
    ASSERT_EQ(bitArray1.empty(), false);

    BitArray bitArray2 = BitArray();
    ASSERT_EQ(bitArray2.empty(), true);
}
