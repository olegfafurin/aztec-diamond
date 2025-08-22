#include "gtest/gtest.h"
#include "AztecTilingCounter.h"
#include <boost/multiprecision/cpp_int.hpp>

// Function to calculate the expected number of tilings: 2^(n*(n+1)/2)
BigInt expectedTilings(int n) {
    if (n == 0) {
        return 1;
    }
    BigInt base = 2;
    int exponent = n * (n + 1) / 2;
    BigInt result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

TEST(AztecTilingCounterTest, HandlesSmallValues) {
    AztecTilingCounter counter;
    EXPECT_EQ(counter.countTilings(0), 1);
    EXPECT_EQ(counter.countTilings(1), 2);
    EXPECT_EQ(counter.countTilings(2), 8);
    EXPECT_EQ(counter.countTilings(3), 64);
    EXPECT_EQ(counter.countTilings(4), 1024);
    EXPECT_EQ(counter.countTilings(5), 32768);
    EXPECT_EQ(counter.countTilings(6), expectedTilings(6));
    EXPECT_EQ(counter.countTilings(7), expectedTilings(7));
    EXPECT_EQ(counter.countTilings(8), expectedTilings(8));
    EXPECT_EQ(counter.countTilings(9), expectedTilings(9));
    EXPECT_EQ(counter.countTilings(10), expectedTilings(10));
}
