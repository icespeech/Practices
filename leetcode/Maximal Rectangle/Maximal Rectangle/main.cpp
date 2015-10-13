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

    EXPECT_EQ(0, sol.maximalRectangle(matrix));
}

TEST(OneRowTest, OneRowTest)
{
    Solution sol;
    vector<vector<char>> matrix{ { '0', '1', '1', '0', '1', '0' } };
    EXPECT_EQ(2, sol.maximalRectangle(matrix));

    vector<vector<char>> matrix2{ { '0', '0', '0', '0', '0', '0' } };
    EXPECT_EQ(0, sol.maximalRectangle(matrix2));
}

TEST(OneColTest, OneColTest)
{
    Solution sol;
    vector<vector<char>> matrix{ { '0' }, { '1' }, { '1' }, { '0' }, { '1' }, { '0' } };
    EXPECT_EQ(2, sol.maximalRectangle(matrix));
    vector<vector<char>> matrix2{ { '0' }, { '0' }, { '0' }, { '0' }, { '0' }, { '0' } };
    EXPECT_EQ(0, sol.maximalRectangle(matrix2));
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
    EXPECT_EQ(6, sol.maximalRectangle(matrix));
}

TEST(LeetCodeTestcaseTest, LeetCodeTestcaseTest)
{
    Solution sol;
    vector<vector<char>> matrix
    {
        { '0', '1' },
        { '1', '0' },
    };
    EXPECT_EQ(1, sol.maximalRectangle(matrix));

    vector<vector<char>> matrix2
    {
        { '0', '1' },
        { '0', '1' },
    };
    EXPECT_EQ(2, sol.maximalRectangle(matrix2));

    vector<vector<char>> matrix3
    {
        { '1', '1' },
        { '0', '0' },
    };
    EXPECT_EQ(2, sol.maximalRectangle(matrix3));

    vector<vector<char>> matrix4
    {
        { '1', '1' },
        { '1', '0' },
    };
    EXPECT_EQ(2, sol.maximalRectangle(matrix4));

    vector<vector<char>> matrix5
    {
        { '0', '1' },
        { '1', '1' },
    };
    EXPECT_EQ(2, sol.maximalRectangle(matrix5));

    vector<vector<char>> matrix6
    {
        { '1', '0' },
        { '1', '1' },
    };
    EXPECT_EQ(2, sol.maximalRectangle(matrix6));

    vector<vector<char>> matrix7
    {
        { '1', '1' },
        { '1', '1' },
    };
    EXPECT_EQ(4, sol.maximalRectangle(matrix7));
}

TEST(LeetCodeTestcaseTest, LeetCodeTestcaseTest2)
{
    Solution sol;
    vector<std::string> matrix_s
    {
        "0110010101",
        "0010101010",
        "1000010110",
        "0111111010",
        "0011111110",
        "1101011110",
        "0001100010",
        "1101100111",
        "0101101011"
    };

    vector<vector<char>> matrix;
    for (auto s : matrix_s)
    {
        vector<char> v(s.begin(), s.end());
        matrix.push_back(v);
    }

    EXPECT_EQ(10, sol.maximalRectangle(matrix));
}

TEST(LeetCodeTestcaseTest, LeetCodeTestcaseTest3)
{
    Solution sol;
    vector<std::string> matrix_s
    {
        "101101",
        "111111",
        "011011",
        "111010",
        "011111",
        "110111"
    };

    vector<vector<char>> matrix;
    for (auto s : matrix_s)
    {
        vector<char> v(s.begin(), s.end());
        matrix.push_back(v);
    }

    EXPECT_EQ(8, sol.maximalRectangle(matrix));
}

TEST(LeetCodeTestcaseTest, LeetCodeTestcaseTest4)
{
    Solution sol;
    vector<std::string> matrix_s
    {
        "0001010",
        "0100000",
        "0101001",
        "0011001",
        "1111110",
        "1001011",
        "0100101",
        "1101110",
        "1010101",
        "1110000"
    };

    vector<vector<char>> matrix;
    for (auto s : matrix_s)
    {
        vector<char> v(s.begin(), s.end());
        matrix.push_back(v);
    }

    EXPECT_EQ(6, sol.maximalRectangle(matrix));
    
    vector<std::string> matrix_s2
    {
        "0001010",
        "0100000",
        "0101001",
        "0011001",
        "1101110",
        "1001011",
        "0100101",
        "1101110",
        "1010101",
        "1110000"
    };

    vector<vector<char>> matrix2;
    for (auto s : matrix_s2)
    {
        vector<char> v(s.begin(), s.end());
        matrix2.push_back(v);
    }

    EXPECT_EQ(4, sol.maximalRectangle(matrix2));
}