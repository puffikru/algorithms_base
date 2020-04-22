#include "../color.h"
#include "../test_runner.h"

#include <iostream>
#include <vector>
#include <string>
#include <array>


using namespace std;



class Solution {
public:
    int CountSubstrings(const string& s, int k) {
        int count_k = 0;
        int res = 0;
        int n = s.size();
        int *sums = new int[n + 1]{};

        sums[0] = 1;
        for (size_t i = 0; i < s.size(); ++i) {
            count_k += (s[i] - '0');
            // cout << count_k << '\n';

            if (count_k >= k) {
                res += sums[count_k - k];
            }
            sums[count_k]++;
        }
        return res;
    }
};
 
// 0 1 0 0 1 0 0 1 0 1      15
// sum[0] = 1
// sum[1] = 2 // 10
// sum[2] = 2 // 10 


void Test1() {
    string str = "1010";
    int k = 1;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 6;
    ASSERT_EQUAL(res, expected);
}


void Test2() {
    string str = "010010";
    int k = 1;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 12;
    ASSERT_EQUAL(res, expected);
}


void Test3() {
    string str = "000000";
    int k = 1;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 0;
    ASSERT_EQUAL(res, expected);
}


void Test4() {
    string str = "110101";
    int k = 0;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 2;
    ASSERT_EQUAL(res, expected);
}


void Test5() {
    string str = "1111";
    int k = 1;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 4;
    ASSERT_EQUAL(res, expected);
}


void Test6() {
    string str = "1000";
    int k = 1;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 4;
    ASSERT_EQUAL(res, expected);
}


void Test7() {
    string str = "0000";
    int k = 0;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 10;
    ASSERT_EQUAL(res, expected);
}


void Test8() {
    string str = "010110101";
    int k = 2;
    Solution s;
    int res = s.CountSubstrings(str, k);
    int expected = 10;
    ASSERT_EQUAL(res, expected);
}


int main() {
    TestRunner tr;
    RUN_TEST(tr, Test1);
    RUN_TEST(tr, Test2);
    RUN_TEST(tr, Test3);
    RUN_TEST(tr, Test4);
    RUN_TEST(tr, Test5);
    RUN_TEST(tr, Test6);
    RUN_TEST(tr, Test7);
    RUN_TEST(tr, Test8);

    // int k;
    // cin >> k;
    // string str = "1010";

    // Solution s;
    // s.CountSubstrings(str, k);

    return 0;
}