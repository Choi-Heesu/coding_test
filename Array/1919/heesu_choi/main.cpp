#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int alphabet[26] = {};
    string s1, s2;
    cin >> s1 >> s2;

    for (auto c1: s1) {
        alphabet[c1 - 'a']++;
    }

    for (auto c2: s2) {
        alphabet[c2 - 'a']--;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans += abs(alphabet[i]);
    }
    cout << ans << "\n";

    return 0;
}
