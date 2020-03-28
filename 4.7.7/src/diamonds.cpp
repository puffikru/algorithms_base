/*
#include "test_runner.h"

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <fstream>
#include <sstream>

 * 
int CountValues(const std::vector<std::pair<int, int>>& best, int k) {
    int v = 0;
    for (int i = 0; i < k; ++i) {
        v += best[i].first;
    }
    return v;
}

int CountWeight(const std::vector<std::pair<int, int>>& best, int k) {
    int w = 0;
    for (int i = 0; i < k; ++i) {
        w += best[i].second;
    }
    return w;
}

double CountDiamonds(const std::vector<std::pair<int, int>>& best, double x, int k) {
    double res = 0.0;
    for (int i = 0; i < k; ++i) {
        res += (best[i].first - x * best[i].second);
    }
    return res;
}

double CheckMax(std::vector<std::pair<int, int>>& values, int k) {
    int v_1 = 0;
    int v_2 = 0;
    int w_1 = 0;
    int w_2 = 0;
    double r_1, r_2;
    for (int i = 0; i < k; ++i) {
        if (i < k - 1) {
            v_1 += values[i].first;
            w_1 += values[i].second;
            v_2 += values[i].first;
            w_2 += values[i].second;
        } else {
            v_1 += values[i].first;
            w_1 += values[i].second;
            v_2 += values[i + 1].first;
            w_2 += values[i + 1].second;
        }
    }
    std::cout << "v_1: " << v_1 << " ,w_1: " << w_1 << std::endl;
    std::cout << "v_2: " << v_2 << " ,w_2: " << w_2 << std::endl;

    r_1 = static_cast<double>(v_1) / static_cast<double>(w_1);
    r_2 = static_cast<double>(v_2) / static_cast<double>(w_2);
    std::cout << r_1 << std::endl;
    std::cout << r_2 << std::endl;
    return r_1 > r_2 ? r_1 : r_2;
}

double CountBest(std::vector<std::pair<int, int>>& values, int k) {
    std::sort(values.begin(), values.end(), 
            [](std::pair<int, int>& a, std::pair<int, int>& b) {
        return static_cast<double>(a.first) / static_cast<double>(a.second) 
        > static_cast<double>(b.first) / static_cast<double>(b.second);
    });
    
    return CheckMax(values, k);




}

double BinarySearch(std::vector<std::pair<int, int>>& best, int k) {

    int l = 0;
    int r = best.size() - 1;
    double res;
    while (l <= r) {
        int m = l + (r - l) / 2;
        res = CountDiamonds(best, m, k);
        if (res >= 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    std::stringstream ss;
    ss << std::fixed << setprecision(5) << res;
    double result;
    ss >> result;
    return result;
}



void Test() {
    int k = 2;
    std::vector<std::pair<int, int>> best = {{1, 1}, {1, 2}, {1, 3}};

    double x = BinarySearch(best, k);

    ASSERT_EQUAL(x, 0.66667);
}



int main() {
     
     int n, k;

     std::cin >> n >> k;
     int v = 0;
     int w = 0;
     std::vector<std::pair<int, int>> val;
     val.reserve(n);
     for (int i = 0; i < n; ++i) {
         std::cin  >> v >> w;
         val.push_back(std::make_pair(v, w));
     }




    std::cout << std::fixed << std::setprecision(5) << CheckMax(val, k) << std::endl;
     

    return 0;
}
*
*/




#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>

int CountValues(const std::vector<std::pair<int, int>>& best, int k) {
    int v = 0;
    for (int i = 0; i < k; ++i) {
        v += best[i].first;
    }
    return v;
}

int CountWeight(const std::vector<std::pair<int, int>>& best, int k) {
    int w = 0;
    for (int i = 0; i < k; ++i) {
        w += best[i].second;
    }
    return w;
}

double CountBest(std::vector<std::pair<int, int>>& values, int k) {
    std::sort(values.begin(), values.end(), 
            [](std::pair<int, int>& a, std::pair<int, int>& b) {
        return static_cast<double>(a.first) / static_cast<double>(a.second) 
        > static_cast<double>(b.first) / static_cast<double>(b.second);
    });
    int v = CountValues(values, k);
    int w = CountWeight(values, k);
    return static_cast<double>(v) / static_cast<double>(w);
}

double BinarySearch(std::vector<std::pair<int, int>>& best,  double x, int k) {
    int l = 0;
    int r = best.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (CountBest(best, k) - x >= 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return CountBest(best, k);
}

int main() {
    int n, k;
    double res = 0.0;
    std::cin >> n >> k;
    int v = 0;
    int w = 0;
    std::vector<std::pair<int, int>> val;
    val.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::cin  >> v >> w;
        val.push_back(std::make_pair(v, w));
    }

    res = CountBest(val, k);

    std::cout << std::fixed << std::setprecision(5) << BinarySearch(val, res, k) << std::endl;

    return 0;
}