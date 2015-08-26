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
    vector<vector<int>> matrix;
    sol.rotate(matrix);

    EXPECT_EQ(0, matrix.size());
}

TEST(OneElementTest, OneElementTest)
{
    Solution sol;
    vector<vector<int>> matrix{ { 1 } };
    sol.rotate(matrix);

    EXPECT_EQ(1, matrix.size());
    EXPECT_EQ(1, matrix[0].size());
    EXPECT_EQ(1, matrix[0][0]);
}

TEST(TwoTwoTest, TwoTwoTest)
{
    Solution sol;
    vector<vector<int>> matrix{ { 1, 2 }, { 3, 4 } };
    vector<vector<int>> answer{ { 3, 1 }, { 4, 2 } };

    sol.rotate(matrix);

    EXPECT_EQ(2, matrix.size());
    
    for (int i = 0; i < 2; ++i)
    {
        EXPECT_EQ(2, matrix[i].size());
        for (int j = 0; j < 2; ++j)
            EXPECT_EQ(answer[i][j], matrix[i][j]);
    }
}

TEST(ThreeThreeTest, ThreeThreeTest)
{
    Solution sol;
    vector<vector<int>> matrix{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    vector<vector<int>> answer{ { 7, 4, 1 }, { 8, 5, 2 }, { 9, 6, 3 } };

    sol.rotate(matrix);

    EXPECT_EQ(3, matrix.size());

    for (int i = 0; i < 3; ++i)
    {
        EXPECT_EQ(3, matrix[i].size());
        for (int j = 0; j < 2; ++j)
            EXPECT_EQ(answer[i][j], matrix[i][j]);
    }
}

TEST(MultipleTests, MultipleTests)
{
    Solution sol;

    int sizes[] = { 4 ,5, 6, 7, 8, 9 };

    for (int size : sizes)
    {
        vector<vector<int>> matrix;
        vector<vector<int>> answer;
        for (int i = 0; i < size; ++i)
        {
            matrix.push_back(vector<int>(size));
            answer.push_back(vector<int>(size));
        }

        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                answer[j][(size - 1) - i] = matrix[i][j] = i * size + j + 1;

        sol.rotate(matrix);

        EXPECT_EQ(size, matrix.size());

        for (int i = 0; i < size; ++i)
        {
            EXPECT_EQ(size, matrix[i].size());
            for (int j = 0; j < size; ++j)
                EXPECT_EQ(answer[i][j], matrix[i][j]);
        }
    }
}
