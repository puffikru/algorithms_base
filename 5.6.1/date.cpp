#include "../profile.h"
// #include "../test_runner.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>


class Solution {
public:
    int64_t SolutionCount(std::vector<int>& distances, int64_t max_dist) {
        // LOG_DURATION("Solution");
        size_t l = 0;
        int64_t res = 0;
        int64_t count = 0;
        for (size_t r = 1; r < distances.size(); ++r) {
            res = distances[r] - distances[l];
            while (res > max_dist) {
                count++;
                res -= distances[l++];
            }
        }
        
        return count;

        // size_t l = 0;
        // int64_t cases = 0;
        // for (size_t r = distances.size() - 1; r > l; --r) {
        //     if (distances[r] - distances[0] <= max_dist) {
        //         std::cout << "cases: " << cases << std::endl;
        //         return cases;
        //     }
        //     int pos = distances[r] - max_dist;
        //     // std::cout << pos << std::endl;
        //     auto it = std::find_if(distances.rbegin(), distances.rend(), [&pos](const int i) {
        //         return pos > i;
        //     });
        //     // std::cout << *it << std::endl;
        //     auto res = distances.rend() - it;
        //     // std::cout << "res: " << res << std::endl;
        //     cases += res;
        //     // std::cout << "cases: " << cases << std::endl;
        // }
        // std::cout << "cases: " << cases << std::endl;
        // return cases;

    //     size_t r = distances.size() - 1;
    //     int64_t sum = 0;
    //     int64_t cases = 0;
    //     while (r > 0) {
    //         for (size_t l = 0; l < r; ++l) {
    //             if (distances[r] - distances[0] <= max_dist) {
    //                 std::cout << "cases: " << cases << std::endl;
    //                 return cases;
    //             }
    //             sum = distances[r] - distances[l];
    //             if (sum <= max_dist) {
    //                 break;
    //             }
    //             // std::cout << distances[r] << " - " << distances[l] << " = " << sum << std::endl;
    //             cases++;
    //             // std::cout << cases << std::endl;
    //         }
    //         --r;
    //     }
    //     std::cout << "cases: " << cases << std::endl;
    //     return cases;
    }
};


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
    LOG_DURATION("TestMax");
    int n = 300000;
    std::vector<int> v;
    v.reserve(n);
    int64_t x = 1000000000;
    int64_t r = 900000000;
    int seed = 42;
    std::mt19937 gen(seed);
    // std::random_device rd;
    // std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, x);
    
    for (auto i = 0; i < n; ++i) {
        v.push_back(dist(gen));
    }

    // for (auto& i : v) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;
    // std::cout << std::endl;

    std::sort(v.begin(), v.end());

    // for (auto& i : v) {
    //     std::cout << i << " ";
    // }
    // std::cout << std::endl;

    Solution s;
    int64_t res = s.SolutionCount(v, r);
    int64_t expected = 0;
    if (res == expected) {
        std::cout << "OK: res = " << res << std::endl;
    } else {
        std::cout << "NO, get= " << res << std::endl;
    }
 }




int main() {

    // TestRunner t;
    // RUN_TEST(t, SimpleTest);
    // RUN_TEST(t, Test);
    // RUN_TEST(t, Test2);
    // RUN_TEST(t, Test3);
    // RUN_TEST(t, Test4);

    // std::cout << std::numeric_limits<long long>::max() << std::endl;
    int64_t n, r;
    std::cin >> n >> r;
    std::vector<int> v(n);
    for (int& i : v) {
        std::cin >> i;
    }

    Solution s;
    s.SolutionCount(v, r);
    std::cout << s.SolutionCount(v, r) << std::endl;
    
    return 0;
}