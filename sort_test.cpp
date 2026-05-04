#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

#include "sorting.h"

// ========== BUBBLE SORT TESTS ==========
TEST(BubbleSortTests, EmptyVector)
{
    std::vector<int> v;
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(BubbleSortTests, SingleElement)
{
    std::vector<int> v;
    v.push_back(42);
    bubble_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(BubbleSortTests, TwoElements)
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(1);
    bubble_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(BubbleSortTests, AlreadySorted)
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(BubbleSortTests, ReverseSorted)
{
    int arr[] = {5, 4, 3, 2, 1};
    std::vector<int> v(arr, arr + 5);
    bubble_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(BubbleSortTests, Duplicates)
{
    int arr[] = {3, 1, 2, 1, 3, 2};
    std::vector<int> v(arr, arr + 6);
    int exp[] = {1, 1, 2, 2, 3, 3};
    std::vector<int> expected(exp, exp + 6);
    bubble_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BubbleSortTests, LargeArray)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    std::vector<int> v(arr, arr + 10);
    std::vector<int> expected = v;
    std::sort(expected.begin(), expected.end());
    bubble_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(BubbleSortTests, NegativeNumbers)
{
    int arr[] = {-5, 3, -1, 0, -10, 2};
    std::vector<int> v(arr, arr + 6);
    std::vector<int> expected = v;
    std::sort(expected.begin(), expected.end());
    bubble_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

// ========== QUICK SORT TESTS ==========
TEST(QuickSortTests, EmptyVector)
{
    std::vector<int> v;
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(QuickSortTests, SingleElement)
{
    std::vector<int> v;
    v.push_back(42);
    quick_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 42);
}

TEST(QuickSortTests, TwoElements)
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(1);
    quick_sort(v.begin(), v.end());
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
}

TEST(QuickSortTests, AlreadySorted)
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTests, ReverseSorted)
{
    int arr[] = {5, 4, 3, 2, 1};
    std::vector<int> v(arr, arr + 5);
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
}

TEST(QuickSortTests, Duplicates)
{
    int arr[] = {3, 1, 2, 1, 3, 2};
    std::vector<int> v(arr, arr + 6);
    int exp[] = {1, 1, 2, 2, 3, 3};
    std::vector<int> expected(exp, exp + 6);
    quick_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTests, LargeArray)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    std::vector<int> v(arr, arr + 10);
    std::vector<int> expected = v;
    std::sort(expected.begin(), expected.end());
    quick_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTests, NegativeNumbers)
{
    int arr[] = {-5, 3, -1, 0, -10, 2};
    std::vector<int> v(arr, arr + 6);
    std::vector<int> expected = v;
    std::sort(expected.begin(), expected.end());
    quick_sort(v.begin(), v.end());
    EXPECT_EQ(v, expected);
}

TEST(QuickSortTests, AllSame)
{
    std::vector<int> v;
    for (int i = 0; i < 5; ++i)
        v.push_back(5);
    quick_sort(v.begin(), v.end());
    EXPECT_TRUE(std::is_sorted(v.begin(), v.end()));
    EXPECT_EQ(v[0], 5);
}
