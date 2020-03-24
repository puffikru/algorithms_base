#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>


bool BinarySearch() {
    //int l = 0;
    //int r = 0;
    return true;
}


int main() {
    int n, k;
    double res = 0.0;
    std::cin >> n >> k;
    std::vector<double> v(n);
    std::vector<double> w(n);
    for (int i = 0; i < n; ++i) {
        std::cin  >> v[i] >> w[i];
    }
    std::vector<double> best;

    //int best_count = n / k;

    //best.reserve(best_count);

    //double values = 0;
    //double weights = 0;

    for (int i = 0; i < n; ++i) {
        res = v[i] / w[i];
        best.push_back(res);
    }

    std::sort(best.begin(), best.end());
    
    for (int i = best.size() - 1; i >= i - 5; --i) {
        res += best[i];
    }
    std::cout << std::endl;

    return 0;
}
