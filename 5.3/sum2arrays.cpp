#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, sum;
    cin >> n >> m >> sum;
    vector<int> a(n);
    vector<int> b(m);

    for (int& x : a) {
        cin >> x;
    }
    for (int& x : b) {
        cin >> x;
    }

    int j = b.size() - 1;
    for (size_t i = 0; i < a.size(); ++i) {
        while (j >= 0 && a[i] + b[j] > sum) {
            --j;
        }
        if (j >= 0 && a[i] + b[j] == sum) {
            cout << i + 1 << ' ' << j + 1;
            return 0;
        }
    }
    cout << "0 0";
}