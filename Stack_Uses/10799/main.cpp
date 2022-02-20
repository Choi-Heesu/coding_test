#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str;
vector<char> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    for (auto c: str) {
        if (v.size() != 0) {
            if (v.back() == '(' && c == ')') {
                v.pop_back();
                v.push_back('L');
            } else {
                v.push_back(c);
            }
        } else {
            v.push_back(c);
        }
    }

    int num = 0;
    int ans = 0;
    for (auto c: v) {
        if (c == '(') {
            num++;
            ans++;
        } else if (c == ')') {
            num--;
        } else if (c == 'L') {
            ans += num;
        }
    }

    cout << ans << '\n';

    return 0;
}
