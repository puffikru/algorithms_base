#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>


/*
 *
std::vector<std::string> CreateFilePath(const std::vector<int>& test_numbers, bool is_result = false) {
    std::vector<std::string> files;
    files.reserve(test_numbers.size());
    for (size_t i = 0; i < test_numbers.size(); ++i) {
        std::string temp = "../test/Tests/";
        temp += is_result == true ? "OUT " : "IN ";
        temp += std::to_string(test_numbers[i]) + ".txt";
        files.push_back(temp);
    }
    return files;
}
void Test(std::vector<std::pair<int, int>> val, int k, std::ostream& os = std::cout) {
    double res = CountBest(val, k);
    // std::cout << res << std::endl;
    std::cout << std::fixed << std::setprecision(5) << res << std::endl;
    os << std::fixed << std::setprecision(5) << BinarySearch(val, res, k);
}
void RunTests(const std::vector<int>& nums) {
    int n = 0;
    int k = 0;
    int v, w;
    double res = 0;
    std::vector<std::pair<int, int>> val;
    std::vector<std::string> files = CreateFilePath(nums);
    std::vector<std::string> answers = CreateFilePath(nums, true);

    for (size_t i = 0; i < files.size(); ++i) {
        val.clear();
        std::ifstream test(files[i]);
        std::ifstream answer(answers[i]);
        if (test.is_open()) {
            test >> n >> k;
            val.reserve(n);
            while (test >> v >> w) {
                val.push_back(std::make_pair(v, w));
            }
        }
        test.close();
        if (answer.is_open()) {
            answer >> res;
        }
        answer.close();
        std::ostringstream oss;
        std::ostringstream rs;
        Test(val, k, oss);
        rs << std::fixed << std::setprecision(5) << res;
        if (oss && oss.str() == rs.str()) {
            std::cout << "TEST #" << nums[i] << " is OK" << std::endl;
        } else {
            std::cout << "TEST #" << nums[i] << " is FAILED" << std::endl;
            std::cout << "Expected: " << rs.str() << ", got: " << oss.str() << std::endl;
            std::cout << std::endl;
        }
    }

}
*
*/


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

    

    return 0;
}