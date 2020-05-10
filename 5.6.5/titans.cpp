#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int64_t FindMinBoxSize(vector<int64_t>& v, int64_t N, int64_t M) {
        sort(v.begin(), v.end());
        int64_t result = v.back(); // Минимальным размером будет максимальный размер из списка вещей
        int64_t full_box_count = 0;
        int64_t boxes = N % M;
        if (boxes == 0 && N / M == 2) { // Проверка все ли коробки заполнены полностью
            boxes = M;
        }
        int64_t l = 0;
        int64_t r = v.size() - 1;
        // Если кол-во коробок больше, чем кол-во вещей, либо если вещей слишком много, возвращаем -1
        if (M > N || ((N - 1) / M) + 1 > 2) {
            return -1;
        }
        if (boxes == 0) { // Все коробки заполнены на половину либо полностью
            if (((N - 1) / M) + 1 == 1) { // Если кол-во вещей и коробок совпадают
                return result;
            } else if (((N - 1) / M) + 1 > 1) { // Кол-во вещей больше кол-ва коробок, но меньше, чем кол-во коробок * 2
                while (full_box_count <= boxes) {
                    if (v[l] + v[r] > result) { // Если сумма размера вещей больше текущего размера
                        result = v[l] + v[r];
                    }
                    full_box_count++;
                    l++;
                    r--;
                }
            }
        } else if (boxes > 0) { // Часть коробок заполнена полностью
            r -= (N - (boxes) * 2);
            while (full_box_count <= boxes) {
                if (v[l] + v[r] > result) { // Если сумма размера вещей больше текущего размера
                    result = v[l] + v[r];
                }
                full_box_count++;
                l++;
                r--;
            }
        }
        return result;
    }
};



int main() {
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t> sizes(N);

    for (int64_t& i : sizes) {
        cin >> i;
    }

    Solution s;
    cout << s.FindMinBoxSize(sizes, N, M) << '\n';

    return 0;
}