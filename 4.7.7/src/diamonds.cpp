#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <string>


double CheckData(std::vector<std::pair<int, int>>& val, int k) {
    long long V_big = 0;
    long long W_big = 1;

    // Считаем суммы ценности и веса
    for (int i = 0; i < k; ++i) {
        V_big += val[i].first;
        W_big += val[i].second;
    }

    // Удельное значение стоимости
    double result_origin = static_cast<double>(V_big) / static_cast<double>(W_big);

    // Создаем переменные для сумм V_j и W_j
    long long V_j = 0;
    long long W_j = 1;

    // Контейнер для 
    std::vector<double> compare(k);

    // Максимальное значение для удельной стоимости
    double MAX = result_origin;

    int index = -1;
    for (size_t j = k; j < val.size(); ++j) {
        // Устанавлиеваем начальное значение для сумм равное текущей драгоценности
        V_j = val[j].first;
        W_j = val[j].second;

        // Подставляем значения поочередно вместо каждого элемента K последовательности
        // Считаем удельную стоимость и сохраняем в вектор
        for (int m = k - 1; m >= 0; --m) {
            for (int i = 0; i < k; ++i) {
                if (i == m) {
                    continue;
                } else {
                    V_j += val[i].first;
                    W_j += val[i].second;
                }
            }
            compare[m] = static_cast<double>(V_j) / static_cast<double>(W_j);
        }

        // Сравниваем каждое полученное значение удельной стоимости 
        // с нашим текущим значением и сохраняем максимум
        for (size_t i = 0; i < compare.size(); ++i) {
            if (compare[i] > MAX) {
                MAX = compare[i];
                index = i;
            }
        }

        // Проверяем если максимум изменился, то мы заменяем максимальное значение на соответсвующей позиции
        if (MAX > result_origin) {
            val[index] = std::make_pair(val[j].first, val[j].second);
        }
        
        // Очищаем контейнера и обнуляем переменные
        compare.clear();
        compare.resize(k);
        index = -1;
        V_big = 0;
        W_big = 0;

        // Просчитываем суммы с учетом новых данных
        for (int i = 0; i < k; ++i) {
            V_big += val[i].first;
            W_big += val[i].second;
        }
    }
    return static_cast<double>(V_big) / static_cast<double>(W_big);
}


// std::vector<std::string> CreateFilePath(const std::vector<int>& test_numbers, bool is_result = false) {
//     std::vector<std::string> files;
//     files.reserve(test_numbers.size());
//     for (size_t i = 0; i < test_numbers.size(); ++i) {
//         std::string temp = "../test/Tests/";
//         temp += is_result == true ? "OUT " : "IN ";
//         temp += std::to_string(test_numbers[i]) + ".txt";
//         files.push_back(temp);
//     }
//     return files;
// }


// void Test(std::vector<std::pair<int, int>> val, int k, std::ostream& os = std::cout) {
//     double res = CheckData(val, k);
//     os << std::fixed << std::setprecision(5) << res;
// }


// void RunTests(const std::vector<int>& nums) {
//     int n = 0;
//     int k = 0;
//     int v, w;
//     double res = 0;
//     std::vector<std::pair<int, int>> val;
//     std::vector<std::string> files = CreateFilePath(nums);
//     std::vector<std::string> answers = CreateFilePath(nums, true);
//     for (size_t i = 0; i < files.size(); ++i) {
//         val.clear();
//         std::ifstream test(files[i]);
//         std::ifstream answer(answers[i]);
//         if (test.is_open()) {
//             test >> n >> k;
//             val.reserve(n);
//             while (test >> v >> w) {
//                 val.push_back(std::make_pair(v, w));
//             }
//         }
//         test.close();
//         if (answer.is_open()) {
//             answer >> res;
//         }
//         answer.close();

//         std::ostringstream oss;
//         std::ostringstream rs;
//         Test(val, k, oss);

//         rs << std::fixed << std::setprecision(5) << res;
//         if (oss && oss.str() == rs.str()) {
//             std::cout << "TEST #" << nums[i] << " is OK" << std::endl;
//         } else {
//             std::cout << "TEST #" << nums[i] << " is FAILED" << std::endl;
//             std::cout << "Expected: " << rs.str() << ", got: " << oss.str() << std::endl;
//             std::cout << std::endl;
//         }
//     }
// }



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

    double res = CheckData(val, k);
    std::cout << std::fixed << std::setprecision(5) << res << std::endl;

    // std::vector<std::pair<int, int>> values = {{6792, 19949}, {22986, 3872},
    //     {28903, 6506}, {2514, 1990}, {23158, 5029}, {2101, 23700}};

    // std::vector<std::pair<int, int>> values = {{10, 1}, {10, 1},
    //     {9000, 1000}, {8, 1}};

    // std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    //                 15, 16, 17, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

    // RunTests(nums);


    return 0;
}
