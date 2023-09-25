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
    ASSERT_TRUE(bitArray.to_string() == "111110000000000000000000");
}

TEST(BitArrayTests, CopyConstructor) {
    BitArray bitArray = BitArray(3, 31);
    BitArray bitArray_copy = BitArray(bitArray);
    ASSERT_EQ(bitArray_copy.size(), 3 * CELL_SIZE);
    ASSERT_TRUE(bitArray_copy.to_string() == "111110000000000000000000");
}

TEST(BitArrayTests, Swap) {
    BitArray bitArray1 = BitArray(3, 31);
    BitArray bitArray2 = BitArray(1, 8);
    bitArray1.swap(bitArray2);

    ASSERT_EQ(bitArray1.size(), 1 * CELL_SIZE);
    ASSERT_EQ(bitArray2.size(), 3 * CELL_SIZE);
    ASSERT_TRUE(bitArray1.to_string() == "00010000");
    ASSERT_TRUE(bitArray2.to_string() == "111110000000000000000000");
}

TEST(BitArrayTests, Operator_eq) {
    BitArray bitArray1 = BitArray(1, 8);
    BitArray bitArray2 = bitArray1;
    bitArray1.push_back(true);
    ASSERT_NE(bitArray1.size(), bitArray2.size());
    ASSERT_FALSE(bitArray1.to_string() == bitArray2.to_string());
}

TEST(BitArrayTests, Clear) {
    BitArray bitArray = BitArray(1, 8);
    bitArray.clear();
    ASSERT_EQ(bitArray.size(), 0);
    ASSERT_TRUE(bitArray.to_string().empty());
}

TEST(BitArrayTests, PushBack) {
    BitArray bitArray = BitArray(2, 8);
    bitArray.push_back(true);
    bitArray.push_back(false);
    bitArray.push_back(true);
    ASSERT_EQ(bitArray.size(), 3 + 2 * CELL_SIZE);
    ASSERT_TRUE(bitArray.to_string() == "0001000000000000101");
}

TEST(BitArrayTests, SetAllTrue) {
    BitArray bitArray = BitArray(2, 8);
    bitArray.set();
    ASSERT_EQ(bitArray.size(), 2 * CELL_SIZE);
    ASSERT_TRUE(bitArray.to_string() == "1111111111111111");
}

TEST(BitArrayTests, SetBit) {
    BitArray bitArray = BitArray(1, 8);
    bitArray.set(6, true);
    ASSERT_EQ(bitArray.size(), 1 * CELL_SIZE);
    ASSERT_TRUE(bitArray.to_string() == "00010010");
}

TEST(BitArrayTests, Reset) {
    BitArray bitArray = BitArray(1, 63);
    bitArray.reset();
    ASSERT_EQ(bitArray.size(), 1 * CELL_SIZE);
    ASSERT_TRUE(bitArray.to_string() == "00000000");
}

TEST(BitArrayTests, ResetBit) {
    BitArray bitArray = BitArray(1, 8);
    bitArray.reset(3);
    ASSERT_EQ(bitArray.size(), 1 * CELL_SIZE);
    ASSERT_TRUE(bitArray.to_string() == "00000000");
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
