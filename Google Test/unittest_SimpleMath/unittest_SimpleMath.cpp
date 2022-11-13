#include "gtest/gtest.h"
#include "simplemath.h"
#include <limits.h>

namespace {

    TEST(FactorialTest, Negative) {
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-1));
        EXPECT_GT(Factorial(-10), 0);
    }

    TEST(FactorialTest, Zero) { EXPECT_EQ(1, Factorial(0)); }

    TEST(FactorialTest, Positive) {
        EXPECT_EQ(1, Factorial(1));
        EXPECT_EQ(2, Factorial(2));
        EXPECT_EQ(6, Factorial(3));
        EXPECT_EQ(40320, Factorial(8));
    }

    TEST(IsPrimeTest, Negative) {

        EXPECT_FALSE(IsPrime(-1));
        EXPECT_FALSE(IsPrime(-2));
        EXPECT_FALSE(IsPrime(INT_MIN));
    }

    TEST(IsPrimeTest, Trivial) {
        EXPECT_FALSE(IsPrime(0));
        EXPECT_FALSE(IsPrime(1));
        EXPECT_TRUE(IsPrime(2));
        EXPECT_TRUE(IsPrime(3));
    }

    TEST(IsPrimeTest, Positive) {
        EXPECT_FALSE(IsPrime(4));
        EXPECT_TRUE(IsPrime(5));
        EXPECT_FALSE(IsPrime(6));
        EXPECT_TRUE(IsPrime(23));
    }

    //

    TEST(MyString, DefaultConstructor) {
        const MyString s;

        EXPECT_STREQ(nullptr, s.c_string());

        EXPECT_EQ(0u, s.Length());
    }

    const char kHelloString[] = "Hello, world!";

    TEST(MyString, ConstructorFromCString) {
        const MyString s(kHelloString);
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));
        EXPECT_EQ(sizeof(kHelloString) / sizeof(kHelloString[0]) - 1, s.Length());
    }

    TEST(MyString, CopyConstructor) {
        const MyString s1(kHelloString);
        const MyString s2 = s1;
        EXPECT_EQ(0, strcmp(s2.c_string(), kHelloString));
    }

    TEST(MyString, Set) {
        MyString s;

        s.Set(kHelloString);
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

        s.Set(s.c_string());
        EXPECT_EQ(0, strcmp(s.c_string(), kHelloString));

        s.Set(nullptr);
        EXPECT_STREQ(nullptr, s.c_string());
    }



    // 
    TEST(testMath, myCubeTest)
    {
        EXPECT_EQ(1000, cubic(10));
    }
}

int main() {
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
}
