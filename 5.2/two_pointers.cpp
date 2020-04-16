#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    size_t x;
    cin >> n >> x;
    vector<int> a(n);
    for (int& s : a) {
        cin >> s;
    }

    for (size_t l = 0, r = 0, sum = 0; l < a.size(); ++l) {
        while (r < a.size() && sum < x) {
            sum += a[r++];
        }
        if (sum == x) {
            cout << l + 1 << ' ' << r;
            return 0;
        }
        sum -= a[l];
    }
    cout << "1 0";
}