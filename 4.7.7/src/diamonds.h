#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <fstream>

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
    //for (auto& item : values) {
    //    std::cout << item.first << " " << item.second << std::endl;
    //}
    int v = CountValues(values, k);
    int w = CountWeight(values, k);
    // std::cout << "v: " << v << ", w: " << w << std::endl;
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


