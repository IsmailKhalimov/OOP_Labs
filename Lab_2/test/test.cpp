#include <gtest/gtest.h>
#include<iostream>
#include "src/Six.hpp"

TEST(test01, Six) {
    Six a("5");
    Six b("2");

    ASSERT_TRUE((a + b) == Six("11"));
}

TEST(test02, Six) {
    Six a("5");
    Six b("5");
    ASSERT_TRUE((a + b) != Six("13"));
}

TEST(test03, Six) {
    Six a("11");
    Six b("3");
    
    std::cout << a - b << '\n';
    ASSERT_TRUE((a - b) == Six("4"));
}

TEST(test04, Six) {
    Six a("5");
    Six b("3");
    ASSERT_TRUE((a - b) == Six("2"));
}

TEST(test05, Six) {
    Six a("5");
    Six b("4");
    ASSERT_TRUE((a - b) != Six("4"));
}

TEST(test06, Six) {
    Six a("5");
    Six b("4");
    ASSERT_TRUE(a != b);
}

TEST(test07, Six) {
    Six a("3");
    Six b("3");
    ASSERT_TRUE(a == b);
}

TEST(test08, Six) {
    Six a("4");
    Six b("2");
    ASSERT_TRUE(a > b);
}

TEST(test09, Six) {
    Six a("3");
    Six b("5");
    ASSERT_TRUE(a < b);
}

TEST(test10, Six) {
    Six a("4");
    Six b("3");
    ASSERT_TRUE(a >= b);
}

TEST(test11, Six) {
    Six a("4");
    Six b("4");
    ASSERT_TRUE(a >= b);
}

TEST(test12, Six) {
    Six a("2");
    Six b("3");
    ASSERT_TRUE(a <= b);
}

TEST(test13, Six) {
    Six a("2");
    Six b("2");
    ASSERT_TRUE(a <= b);
}

TEST(test14, Six) {
    Six a("134");
    Six b({'1', '3', '4'});
    ASSERT_TRUE(a == b);
}

TEST(test15, Six) {
    Six a("1341");
    Six b({'1', '3', '4'});
    ASSERT_TRUE(a != b);
}

TEST(test16, Six) {
    Six a("1341");
    Six b(3, '7');
    ASSERT_TRUE(a != b);
}

TEST(test17, Six) {
    Six a("1111");
    Six b(4, '1');
    ASSERT_TRUE(a == b);
}

TEST(test18, Six) {
    Six a({'1'});
    Six b({'2'});
    ASSERT_TRUE(a < b);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
