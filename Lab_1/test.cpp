#include <gtest/gtest.h>

#include "task.h"

using namespace std;

TEST(test1, count_ones) {
    int a = 1, b = 1;
    ASSERT_TRUE(toBinary(a, b) == 1);
}

TEST(test2, count_ones) {
    int a = 1, b = 2;
    ASSERT_TRUE(toBinary(a, b) == 2);
}

TEST(test3, count_ones) {
    int a = 2, b = 7;
    ASSERT_TRUE(toBinary(a, b) == 11);
}

TEST(test4, count_ones) {
    int a = 7, b = 2;
    ASSERT_TRUE(toBinary(a, b) == -1);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}