#include "../src/vector.h"
#include <gtest/gtest.h>

TEST(VectorTest, AddingSingleElement) {
    Vector<int> v;

    int value = 10;
    int expectedSize = 1;

    v.push_back(value);
    EXPECT_EQ(v.size(), expectedSize);
    EXPECT_EQ(v.back(), value);
}

TEST(VectorTest, AddingMultipleElements) {
    Vector<char> v;

    char value1 = 'a';
    char value2 = 'b';
    char value3 = 'c';
    int expectedSize = 3;

    v.push_back(value1);
    v.push_back(value2);
    v.push_back(value3);
    EXPECT_EQ(v.size(), expectedSize);
    EXPECT_EQ(v.back(), value3);
    EXPECT_EQ(v[0], value1);
    EXPECT_EQ(v[1], value2);
    EXPECT_EQ(v[2], value3);
}

TEST(VectorTest, PopBack) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    EXPECT_EQ(v.pop_back(), 3);
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.pop_back(), 2);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.pop_back(), 1);
    EXPECT_EQ(v.size(), 0);
    EXPECT_TRUE(v.empty());
}

TEST(VectorTest, CopyConstructor) {
    Vector<int> original;

    int value1 = 1;
    int value2 = 2;
    int value3 = 3;

    original.push_back(value1);
    original.push_back(value2);
    original.push_back(value3);

    Vector<int> copied(original);

    EXPECT_EQ(original.size(), copied.size());
    EXPECT_EQ(original[0], copied[0]);
    EXPECT_EQ(original[1], copied[1]);
    EXPECT_EQ(original[2], copied[2]);
}

TEST(VectorTest, AssignmentOperator) {
    Vector<int> original;
    original.push_back(10);
    original.push_back(20);

    Vector<int> assigned;
    assigned = original;

    EXPECT_EQ(original.size(), assigned.size());
    EXPECT_EQ(original[0], assigned[0]);
    EXPECT_EQ(original[1], assigned[1]);
}

TEST(VectorTest, EmptyVector) {
    Vector<int> v;
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
}

TEST(VectorTest, Clear) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.clear();
    EXPECT_TRUE(v.empty());
    EXPECT_EQ(v.size(), 0);
}
