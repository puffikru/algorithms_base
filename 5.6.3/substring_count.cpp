#include "../color.h"
#include "../test_runner.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int CountSubstrings(const string& s, int k) {
        int count = 0;
        int cnt_1 = 0;
        for (size_t l = 0; l < s.size(); ++l) {
            size_t r = l;
            cnt_1 = 0;
            while (r < s.size()) {
                if (k > 0) {
                    if (r == s.size() - 1) {
                        if (cnt_1 == k) {
                            count++;
                        } else if (cnt_1 < k && s[r] == '1') {
                            cnt_1++;
                            count++;
                        }
                        break;
                    }
                }
                if (s[l] == '1' && k > 0) {
                    if (cnt_1 < k) {
                        cnt_1++;
                        count++;
                        r++;
                    }
                }
                if (s[r] == '1') {
                    if (k > 0) {
                        if (cnt_1 == k && r - 1 != l) {
                            count++;
                            break;
                        } else if (cnt_1 == k && r - 1 == l) {
                            break;
                        } else if (cnt_1 < k) {
                            cnt_1++;
                            count++;
                            r++;
                        }
                    } else {
                        break;
                    }
                } else if (s[r] == '0') {
                    if (k > 0) {
                        if (r == s.size() - 1) {
                            if (cnt_1 == k) {
                                count++;
                                break;
                            } else {
                                break;
                            }
                        }
                        r++;
                    } else {
                        if (cnt_1 == 0) {
                            cnt_1++;
                        }
                        count++;
                        r++;
                    }
                } else if (s[r] == '1' && k == 0) {
                    break;
                }
            }
        }
        return count;
    }
};
 


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
    int expected = 10;
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


int main() {
    TestRunner tr;
    RUN_TEST(tr, Test1);
    RUN_TEST(tr, Test2);
    RUN_TEST(tr, Test3);
    RUN_TEST(tr, Test4);
    RUN_TEST(tr, Test5);
    RUN_TEST(tr, Test6);

    // int k;
    // cin >> k;
    // string str = "1010";

    // Solution s;
    // s.CountSubstrings(str, k);

    return 0;
}