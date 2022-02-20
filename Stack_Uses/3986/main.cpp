#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        vector<char> v;
        string s;
        cin >> s;

        for (auto c: s) {
            if (v.size() != 0) {
                if (v.back() == c) {
                    v.pop_back();
                } else {
                    v.push_back(c);
                }
            } else {
                v.push_back(c);
            }
        }

        if (v.size() == 0) ans++;
    }

    cout << ans << "\n";

    return 0;
}
