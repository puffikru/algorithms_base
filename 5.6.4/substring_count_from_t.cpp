#include "../color.h"
#include "../test_runner.h"

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>


using namespace std;


unordered_map<char, int64_t> CreateMap(const string& b) {
    unordered_map<char, int64_t> res;
    for (size_t i = 0; i < b.size(); ++i) {
        res[b[i]]++;
    }
    return res;
}


class Solution {
public:
    int64_t CountSubstringsFromSecondArray(const string& a, const string& b) {
        unordered_map<char, int> m;

        for (size_t l = 0; l < b.size(); ++l) {
            if (m.find(b[l]) == m.end()) {
                m[b[l]] = 1;
            } else {
                m[b[l]]++;
            }
        }

        for (auto it = m.begin(); it != m.end(); ++it) {
            
        }


        // cout << m << '\n';
/*
        // int64_t res = 0;
        // size_t count = 0;
        // unordered_map<char, int64_t> m;
        // unordered_map<char, int64_t> target = CreateMap(b);
        // for (size_t l = 0; l < a.size(); ++l) {
        //     size_t r = l;
        //     while (r < a.size() && target.count(a[r]) > 0 && m[a[r]] < target[a[r]]) {
        //         m[a[r]]++;
        //         count++;
        //         r++;
        //     }
        //     res += count;
        //     m.clear();
        //     count = 0;
        // }
        // return res;
*/
    }
};


void SimpleTest() {
    string a = "aaab";
    string b = "aba";
    Solution s;
    int64_t res = s.CountSubstringsFromSecondArray(a, b);
    int64_t expected = 8;
    ASSERT_EQUAL(res, expected);
}


void Test2() {
    string a = "abacaba";
    string b = "abc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 15;
    ASSERT_EQUAL(res, expected);
}


void Test3() {
    string a = "aaaabac";
    string b = "abc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 11;
    ASSERT_EQUAL(res, expected);
}


void Test4() {
    string a = "aaaabbbacccc";
    string b = "abc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 16;
    ASSERT_EQUAL(res, expected);
}


void Test5() {
    string a = "abbbcccc";
    string b = "ac";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 5;
    ASSERT_EQUAL(res, expected);
}


void Test6() {
    string a = "ac";
    string b = "ac";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 3;
    ASSERT_EQUAL(res, expected);
}


void Test7() {
    string a = "a";
    string b = "a";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 1;
    ASSERT_EQUAL(res, expected);
}


void Test8() {
    string a = "a";
    string b = "c";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 0;
    ASSERT_EQUAL(res, expected);
}


void Test9() {
    string a = "acca";
    string b = "abc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 6;
    ASSERT_EQUAL(res, expected);
}


void Test10() {
    string a = "abcabcabcabcabc";
    string b = "aaaaabbbbbccccc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 120;
    ASSERT_EQUAL(res, expected);
}


void Test11() {
    string a = "abcabc";
    string b = "aabbcc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 21;
    ASSERT_EQUAL(res, expected);
}


void Test12() {
    string a = "abccbaabc";
    string b = "aabbcc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 39;
    ASSERT_EQUAL(res, expected);
}


void Test13() {
    string a = "abccbaabc";
    string b = "abc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 18;
    ASSERT_EQUAL(res, expected);
}


void Test14() {
    string a = "adcdbcadbda";
    string b = "abc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 10;
    ASSERT_EQUAL(res, expected);
}


void Test15() {
    string a = "aaaacbbbbb";
    string b = "cdv";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 1;
    ASSERT_EQUAL(res, expected);
}


void Test16() {
    string a = "adcdb";
    string b = "aaabbbccc";
    Solution s;
    int res = s.CountSubstringsFromSecondArray(a, b);
    int expected = 3;
    ASSERT_EQUAL(res, expected);
}


int main() {
    TestRunner tr;
    RUN_TEST(tr, SimpleTest);
    // RUN_TEST(tr, Test2);
    // RUN_TEST(tr, Test3);
    // RUN_TEST(tr, Test4);
    // RUN_TEST(tr, Test5);
    // RUN_TEST(tr, Test6);
    // RUN_TEST(tr, Test7);
    // RUN_TEST(tr, Test8);
    // RUN_TEST(tr, Test9);
    // RUN_TEST(tr, Test10);
    // RUN_TEST(tr, Test11);
    // RUN_TEST(tr, Test12);
    // RUN_TEST(tr, Test13);
    // RUN_TEST(tr, Test14);
    // RUN_TEST(tr, Test15);
    // RUN_TEST(tr, Test16);


    // #ifdef TEST
    //     freopen("input.txt", "rt", stdin);
    //     freopen("output.txt", "wt", stdout);
    // #endif
// g++ -std=c++17  -D TEST

    // int n, m;
    // cin >> n >> m;
    // string a;
    // string b;

    // for (int i = 0; i < n; ++i) {
    //     char temp;
    //     cin >> temp;
    //     a += temp;
    // }

    // for (int i = 0; i < m; ++i) {
    //     char temp;
    //     cin >> temp;
    //     b += temp;
    // }

    // Solution s;
    // cout << s.CountSubstringsFromSecondArray(a, b) << '\n';

    return 0;
}