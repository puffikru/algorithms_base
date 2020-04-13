#include "../color.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>


double CheckData(std::vector<std::pair<int, int> >& val, int k) {

    std::cout << "k = " << k << std::endl;
    std::cout << std::endl;

    // Cоздаем суммы V_i, W_i, V_j и W_j
    long long V_big = 0;
    long long W_big = 1;
    long long V_j = 0;
    long long W_j = 1;
    long long V = 0;
    long long W = 0;
    int v_i = 0;
    int w_i = 0;
    int v_j = 0;
    int w_j = 0;

    // Считаем суммы ценности и веса
    for (int i = 0; i < k; ++i) {
        if (i < k - 1) {
            V_big += val[i].first;
            W_big += val[i].second;
            V += val[i].first;
            W += val[i].second;
        } else {
            V_big += val[i].first;
            W_big += val[i].second;
        }
    }

    std::cout << "V_big: " << V_big << std::endl;
    std::cout << "W_big: " << W_big << std::endl;
    std::cout << "V_j: " << V_j << std::endl;
    std::cout << "W_j: " << V_j << std::endl;
    std::cout << "V: " << V << std::endl;
    std::cout << "W: " << W << std::endl;
    std::cout << std::endl;

    for (size_t j = k; j < val.size(); ++j) {
        // Устанавлиеваем начальное значение для сумм равное текущей драгоценности
        V_j = val[j].first;
        W_j = val[j].second;
        V += val[j].first;
        W += val[j].second;
        v_j = val[j].first;
        w_j = val[j].second;

        // Подставляем значения поочередно вместо каждого элемента K последовательности
        // Считаем удельную стоимость и сохраняем в вектор
        for (int m = k - 1; m >= 0; --m) {
            v_i = val[m].first;
            w_i = val[m].second;

            std::cout << std::endl;
            std::cout << "v_i: " << v_i << std::endl;
            std::cout << "w_i: " << w_i << std::endl;
            std::cout << std::endl;

            for (int i = 0; i < k; ++i) {
                if (i == m) {
                    continue;
                } else {
                    V_j += val[i].first;
                    W_j += val[i].second;
                }
            }
            std::cout << std::endl;
            std::cout << "V_j: " << V_j << std::endl;
            std::cout << "W_j: " << w_j << std::endl;
            std::cout << std::endl;

            if (((w_j - w_i) * V_big + (v_i - v_j) * W_big) * -1 > 0) {
                val[m] = std::make_pair(val[j].first, val[j].second);
            }
        }

        std::cout << std::endl;
        for (auto& item : val) {
            std::cout << item.first << " " << item.second << std::endl;
        }
        std::cout << std::endl;
   
        V_big = 0;
        W_big = 0;

        // Просчитываем суммы с учетом новых данных
        for (int i = 0; i < k; ++i) {
            V_big += val[i].first;
            W_big += val[i].second;
        }
        std::cout << std::endl;
        std::cout << "V_big: " << V_big << std::endl;
        std::cout << "W_big: " << W_big << std::endl;
        std::cout << std::endl;
    }
    return static_cast<double>(V_big) / static_cast<double>(W_big);
}


std::vector<std::string> CreateFilePath(const std::vector<int>& test_numbers, bool is_result = false) {
    std::vector<std::string> files;
    files.reserve(test_numbers.size());
    for (size_t i = 0; i < test_numbers.size(); ++i) {
        std::string temp = "../4.7.7/test/Tests/";
        
        temp += is_result == true ? "OUT " : "IN ";
        temp += std::to_string(test_numbers[i]) + ".txt";
        files.push_back(temp);

        std::cout << std::endl;
        std::cout << temp << std::endl;
        std::cout << std::endl;
    }
    return files;
}


void Test(std::vector<std::pair<int, int> > val, int k, std::ostream& os = std::cout) {
    
    std::cout << std::endl;
    std::cout << "val: " << val[0].first << " " << val[0].second << std::endl;
    std::cout << std::endl;

    double res = CheckData(val, k);
    std::cout << std::endl;
    std::cout << "Test: res: " << res << std::endl;
    std::cout << std::endl;
    os << std::fixed << std::setprecision(5) << res;
}


void RunTests(const std::vector<int>& nums) {
    int n = 0;
    int k = 0;
    int v, w;
    double res = 0;
    std::vector<std::pair<int, int> > val;
    std::vector<std::string> files = CreateFilePath(nums);
    std::vector<std::string> answers = CreateFilePath(nums, true);
    for (size_t i = 0; i < files.size(); ++i) {
        val.clear();
        std::ifstream test;
        test.open(files[i]);
        std::ifstream answer;
        answer.open(answers[i]);
        if (test.is_open()) {
            test >> n >> k;

            std::cout << std::endl;
            std::cout << n << " " << k << std::endl;
            std::cout << std::endl;

            val.reserve(n);
            while (test >> v >> w) {
                val.push_back(std::make_pair(v, w));
            }

            std::cout << std::endl;
            for (auto& i : val) {
                std::cout << i.first << " " << i.second << std::endl;
            }
            std::cout << std::endl;

        }
        test.close();
        if (answer.is_open()) {
            answer >> res;
        }
        answer.close();

        std::cout << std::endl;
        std::cout << "res: " << res << std::endl;
        std::cout << std::endl;

        std::ostringstream oss;
        std::ostringstream rs;
        Test(val, k, oss);

        rs << std::fixed << std::setprecision(5) << res;
        if (oss && oss.str() == rs.str()) {
            Color::Modifier green(Color::FG_GREEN);
            std::cout << green << "TEST #" << nums[i] << " is OK" << std::endl;
            std::cout << std::endl;
        } else {
            Color::Modifier red(Color::FG_RED);
            Color::Modifier yellow(Color::FG_YELLOW);
            std::cout << yellow << "TEST #" << nums[i] << red << " is FAILED" << std::endl;
            std::cout << yellow << "Expected: " << rs.str() << ", got: " << oss.str() << std::endl;
            std::cout << std::endl;
        }
    }
}



int main() {
    // int n, k;
    // std::cin >> n >> k;
    // int v = 0;
    // int w = 0;
    // std::vector<std::pair<int, int>> val;
    // val.reserve(n);
    // for (int i = 0; i < n; ++i) {
    //     std::cin  >> v >> w;
    //     val.push_back(std::make_pair(v, w));
    // }

    // double res = CheckData(val, k);
    // std::cout << std::fixed << std::setprecision(5) << res << std::endl;

    // std::vector<int> nums = {1, 3, 4, 6, 7, 8, 9, 10, 13,
    //                 15, 20, 21, 29};

    //std::cout << "Hello, world!" << std::endl;

    //int a = 3;
    //int b = 2;

    //int c = a + b;

    //std::cout << c << std::endl;

    std::vector<int> nums = {1};

    RunTests(nums);

    return 0;
}
