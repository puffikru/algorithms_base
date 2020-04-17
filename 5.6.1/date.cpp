#include "../profile.h"
#include "../test_runner.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


int64_t BinarySearch(const std::vector<int>& v, int64_t x) {
    int64_t l = 0;
    int64_t r = v.size() - 1;
    while (l <= r) {
        int64_t m = l + (r - l) / 2;
        if (v[m] > x) {
            r = m - 1;
        } else if (v[m] < x) {
            l = m + 1;
        } else {
            return m;
        }
    }
    return r + 1;
}



class Solution {
public:
    int64_t SolutionCount(const std::vector<int>& distances, int64_t max_dist) {
        size_t l = 0;
        int64_t result = 0;
        for (size_t r = distances.size() - 1; r > 0; --r) {
            if (distances[r] - distances[0] <= max_dist) {
                return result;
            }
            std::vector<int> v(distances.begin(), distances.begin() + r + 1);
            int64_t pos = BinarySearch(distances, distances[r] - max_dist);
            result += pos;
        }
        return result;
/*
        // size_t l = 0;
        // int64_t cases = 0;
        // std::cout << "l: " << l << std::endl;
        // std::cout << "size: " << distances.size() << std::endl;
        // for (size_t r = distances.size() - 1; r > l; --r) {
        //     if (distances[r] - distances[0] <= max_dist) {
        //         return cases;
        //     }
        //     std::cout << "r: " << r << std::endl;
        //     std::cout << "serching number: " << distances[r] - max_dist << std::endl;
        //     std::cout << distances << std::endl;
        //     auto it = std::find_if(distances.rbegin(), distances.rend(), [&](const int i) {
        //         return distances[r] - max_dist > i;
        //     });
        //     std::cout << "it: " << *it << std::endl;
        //     std::cout << "res: " << distances.rend() - it << std::endl;
        //     cases += distances.rend() - it;
        //     std::cout << "cases: " << cases << std::endl;
        // }
        // return cases;
*/
    }
};

// 20 23 25 30 31 35 40 50 150 151 152 153 10000



void Test() {
    std::vector<int> v = {20, 23, 25, 30, 31, 35, 40, 50, 150, 151, 152, 153, 10000};
    int64_t x = 15;
    Solution s;
    int64_t res = s.SolutionCount(v, x);
    int64_t expected = 51;
    ASSERT_EQUAL(res, expected);
}


 void SimpleTest() {
     std::vector<int> v = {1, 3, 5, 8};
     int64_t x = 4;
     Solution s;
     int64_t res = s.SolutionCount(v, x);
     int64_t expected = 2;
     ASSERT_EQUAL(res, expected);
 }


 void Test2() {
    std::vector<int> v = {20, 23, 25, 30, 31, 35, 40, 50, 150, 151, 152, 153, 10000};
    int64_t x = 9979;
    Solution s;
    int64_t res = s.SolutionCount(v, x);
    int64_t expected = 1;
    ASSERT_EQUAL(res, expected);
 }


  void Test3() {
    std::vector<int> v = {1, 10, 100};
    int64_t x = 1;
    Solution s;
    int64_t res = s.SolutionCount(v, x);
    int64_t expected = 3;
    ASSERT_EQUAL(res, expected);
 }


 void Test4() {
    std::vector<int> v = {1, 10, 100};
    int64_t x = 100;
    Solution s;
    int64_t res = s.SolutionCount(v, x);
    int64_t expected = 0;
    ASSERT_EQUAL(res, expected);
 }


 void TestMax() {
    int n = 300000;
    std::vector<int> v;
    v.reserve(n);
    int64_t r = 10000;
    
    for (auto i = 0; i < n; ++i) {
        v.push_back(i + 1);
    }

    Solution s;
    int64_t res = s.SolutionCount(v, r);
    int64_t expected = 42049855000;
    ASSERT_EQUAL(res, expected);
 }


 int main() {
    TestRunner t;
    RUN_TEST(t, SimpleTest);
    RUN_TEST(t, Test);
    RUN_TEST(t, Test2);
    RUN_TEST(t, Test3);
    RUN_TEST(t, Test4);
    RUN_TEST(t, TestMax);
    
    // int64_t n, r;
    // std::cin >> n >> r;
    // std::vector<int> v(n);
    // for (int& i : v) {
    //     std::cin >> i;
    // }

    // Solution s;
    // s.SolutionCount(v, r);
    // std::cout << s.SolutionCount(v, r) << std::endl;
    
    return 0;
}