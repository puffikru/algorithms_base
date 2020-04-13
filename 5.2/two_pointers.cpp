#include <iostream>
#include <vector>
#include <utility>

std::pair<int, int> Solve(std::vector<int>& data, int X) {
    size_t r = 1;
    size_t l = 1;
    int sum = 0;
    for (size_t i = 1; i < data.size(); ++i) {
        while (r < data.size() && sum < X) {
            sum += data[r - 1];
            r += 1;
        }
        if (sum == X) {
            return std::make_pair(l, r - 1);
        }
        sum -= data[l - 1];
    }
    return std::make_pair(1, 0);
}

int main() {
    int N, X;
    std::vector<int> v;
    std::cin >> N >> X;
    v.reserve(N);
    for (int i = 1; i <= N; ++i) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    std::pair<int, int> res = Solve(v, X);
    std::cout << res.first << " " << res.second << std::endl;
}