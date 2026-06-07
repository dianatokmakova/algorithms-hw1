#include <gtest/gtest.h>
#include <vector>
#include <cstdint>
#include <string>
#include "base85ed.h"

using namespace std;

vector<uint8_t> f1(string s)
{
    return vector<uint8_t>(s.begin(), s.end());
}

string f2(vector<uint8_t> v)
{
    return string(v.begin(), v.end());
}

TEST(Base85, PodlyeEncode)
{
    EXPECT_EQ(f2(base85::encode(f1(""))), "");
    EXPECT_EQ(f2(base85::encode(f1(string("\x00\x00\x00\x00", 4)))), "00000");
    EXPECT_EQ(f2(base85::encode(f1(string("\xFF\xFF\xFF\xFF", 4)))), "|NsC0");
    EXPECT_EQ(f2(base85::encode(f1("A"))), "K>");
    EXPECT_EQ(f2(base85::encode(f1("AB"))), "K|%");
    EXPECT_EQ(f2(base85::encode(f1("ABC"))), "K|(_");
    EXPECT_EQ(f2(base85::encode(f1("ABCD"))), "K|(`B");
    EXPECT_EQ(f2(base85::encode(f1("ABCDE"))), "K|(`BMF");
}

TEST(Base85, PodlyeDecode)
{
    EXPECT_EQ(f2(base85::decode(f1(""))), "");
    EXPECT_EQ(f2(base85::decode(f1("00000"))), string("\x00\x00\x00\x00", 4));
    EXPECT_EQ(f2(base85::decode(f1("|NsC0"))), string("\xFF\xFF\xFF\xFF", 4));
    EXPECT_EQ(f2(base85::decode(f1("K>"))), "A");
    EXPECT_EQ(f2(base85::decode(f1("K|%"))), "AB");
    EXPECT_EQ(f2(base85::decode(f1("K|(_"))), "ABC");
    EXPECT_EQ(f2(base85::decode(f1("K|(`B"))), "ABCD");
    EXPECT_EQ(f2(base85::decode(f1("K|(`BMF"))), "ABCDE");
}

TEST(Base85, BigTest)
{
    vector<uint8_t> v;
    for (int i = 0; i < 15000; i++)
    {
        v.push_back(i % 256);
    }
    EXPECT_EQ(base85::decode(base85::encode(v)), v);
}
