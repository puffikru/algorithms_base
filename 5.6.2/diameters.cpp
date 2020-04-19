#include "../profile.h"
#include "../test_runner.h"

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Print(const string& s) {
    cout << s;
}

#define PRINT(x) { \
ostringstream os; \
os << #x << ": " << x << "\n"; \
Print(os.str()); \
} \

class Solution {
public:
    int DiametersSubtraction(const vector<int>& a, const vector<int>& b) {
        int diff = INT_MAX;
        for (size_t l = 0; l < a.size(); ++l) {
            size_t r = 0;
            while (r < b.size()) {
                if (a[l] - b[r] == 0) return 0;
                if (abs(a[l] - b[r]) < diff) {
                    diff = abs(a[l] - b[r]);
                }
                ++r;
            }
        }
        return diff;
    }
};


void SimpleTest() {
    vector<int> a = {1, 8, 15};
    vector<int> b = {5, 6};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 2;
    ASSERT_EQUAL(res, expected);
}


void Test1() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {3, 4, 6};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 0;
    ASSERT_EQUAL(res, expected);
}

void Test2() {
    vector<int> a = {2, 5, 6, 8, 12, 13};
    vector<int> b = {7, 9, 11, 14, 15};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 1;
    ASSERT_EQUAL(res, expected);
}

void Test3() {
    vector<int> a = {2, 5, 6, 8, 12, 13};
    vector<int> b = {7, 9, 11, 13};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 0;
    ASSERT_EQUAL(res, expected);
}


void Test4() {
    vector<int> a = {2, 5};
    vector<int> b = {7, 9, 11, 13, 17};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 2;
    ASSERT_EQUAL(res, expected);
}


void Test5() {
    vector<int> a = {2};
    vector<int> b = {7};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 5;
    ASSERT_EQUAL(res, expected);
}


void Test6() {
    vector<int> a = {20, 23, 26, 28, 34};
    vector<int> b = {2, 4, 7, 9};
    Solution s;
    int res = s.DiametersSubtraction(a, b);
    int expected = 11;
    ASSERT_EQUAL(res, expected);
}


void TestMax() {
    int n = 100000;
    int m = 100000;
    vector<int> a;
    a.reserve(n);
    vector<int> b;
    b.reserve(m);
    for (auto i = 150000; i < n * 2; ++i) {
        a.push_back(i);
    }
    for (auto i = 1; i <= m; ++i) {
        b.push_back(i);
    }
    Solution s;
    int64_t res = s.DiametersSubtraction(a, b);
    int64_t expected = 50000;
    ASSERT_EQUAL(res, expected);
 }


int main() {
    TestRunner r;
    RUN_TEST(r, SimpleTest);
    RUN_TEST(r, Test1);
    RUN_TEST(r, Test2);
    RUN_TEST(r, Test3);
    RUN_TEST(r, Test4);
    RUN_TEST(r, Test5);
    RUN_TEST(r, Test6);
    RUN_TEST(r, TestMax);

    // int n, m;
    // cin >> n >> m;
    // vector<int> a(n);
    // vector<int> b(m);
    // for (int& x : a) {
    //     cin >> x;
    // }
    // for (int& x : b) {
    //     cin >> x;
    // }

    // Solution s;
    // int res = s.DiametersSubtraction(a, b);
    // if (res != -1) {
    //     cout << s.DiametersSubtraction(a, b) << "\n";
    // }

    return 0;
}