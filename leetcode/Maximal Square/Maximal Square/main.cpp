#include "Solution.h"
#include "gtest\gtest.h"
using std::vector;

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
    vector<vector<char>> matrix;

    EXPECT_EQ(0, sol.maximalSquare(matrix));
}

TEST(OneRowTest, OneRowTest)
{
    Solution sol;
    vector<vector<char>> matrix{ { '0', '1', '1', '0', '1', '0' } };
    EXPECT_EQ(1, sol.maximalSquare(matrix));

    vector<vector<char>> matrix2{ { '0', '0', '0', '0', '0', '0' } };
    EXPECT_EQ(0, sol.maximalSquare(matrix2));
}

TEST(OneColTest, OneColTest)
{
    Solution sol;
    vector<vector<char>> matrix{ { '0' }, { '1' }, { '1' }, { '0' }, { '1' }, { '0' } };
    EXPECT_EQ(1, sol.maximalSquare(matrix));
    vector<vector<char>> matrix2{ { '0' }, { '0' }, { '0' }, { '0' }, { '0' }, { '0' } };
    EXPECT_EQ(0, sol.maximalSquare(matrix2));
}

TEST(LeetCodeExampleTest, LeetCodeExampleTest)
{
    Solution sol;
    vector<vector<char>> matrix
    {
        { '1', '0', '1', '0', '0' },
        { '1', '0', '1', '1', '1' },
        { '1', '1', '1', '1', '1' },
        { '1', '0', '0', '1', '0' }
    };
    EXPECT_EQ(4, sol.maximalSquare(matrix));
}

TEST(LeetCodeTestcaseTest, LeetCodeTestcaseTest)
{
    Solution sol;
    vector<vector<char>> matrix
    {
        { '0', '1' },
        { '1', '0' },
    };
    EXPECT_EQ(1, sol.maximalSquare(matrix));
}