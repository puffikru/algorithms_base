#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Solution {
public:
    size_t Advance(const string& s, size_t pos) {
        do {
            ++pos;
        } while (pos < s.size() && s[pos] == s[pos - 1]);
        return pos;
    }
    bool isLongPressedName(string name, string typed) {
        size_t t = 0;
        for (size_t n = 0; n < name.size(); ) {
            if (name[n] != typed[t]) {
                return false;
            }
            auto next_n = Advance(name, n);
            auto next_t = Advance(typed, t);
            if (next_n - n > next_t - t) {
                return false;
            }
            n = next_n;
            t = next_t;
        }
        return t == typed.size();
    }
};



int main(){
    Solution s;
    cout << boolalpha << s.isLongPressedName("alex", "aaleex") << endl;
    cout << boolalpha << s.isLongPressedName("saeed", "saaed") << endl;
    cout << boolalpha << s.isLongPressedName("laiden", "laiden") << endl;
}