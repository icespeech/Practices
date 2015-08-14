#include "Solution.h"
#include "gtest\gtest.h"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    // pause to show the results
    getchar();
    return 0;
}

TEST(EmptyTest, EmptyTest)
{
    Solution sol;

    EXPECT_STREQ("", sol.addBinary("", "").c_str());
    EXPECT_STREQ("1", sol.addBinary("1", "").c_str());
    EXPECT_STREQ("0", sol.addBinary("", "0").c_str());
}

TEST(SingleBitTest, SingleBitTest)
{
    Solution sol;

    EXPECT_STREQ("0", sol.addBinary("0", "0").c_str());
    EXPECT_STREQ("1", sol.addBinary("1", "0").c_str());
    EXPECT_STREQ("1", sol.addBinary("0", "1").c_str());
    EXPECT_STREQ("10", sol.addBinary("1", "1").c_str());
}

TEST(ManyBitsTest, ManyBitsTest)
{
    Solution sol;

    EXPECT_STREQ("0", sol.addBinary("000", "000").c_str());
    EXPECT_STREQ("110", sol.addBinary("110", "0").c_str());
    EXPECT_STREQ("111", sol.addBinary("110", "1").c_str());
    EXPECT_STREQ("11000", sol.addBinary("1011", "1101").c_str());
    EXPECT_STREQ("1111111011", sol.addBinary("1010110", "1110100101").c_str());
}

TEST(LeetcodeExampleTest, LeetcodeExampleTest)
{
    Solution sol;

    EXPECT_STREQ("110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000",
        sol.addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
                      "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011").c_str());
}