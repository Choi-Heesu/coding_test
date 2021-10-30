#include <iostream>
#include <string>

using namespace std;

// 첫번째 풀이
// 각 알파벳마다 string을 탐색하면서 일치하는 문자가 있는지 확인
/*int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z'; ++i) {
        int ans = 0;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == i) ans++;
        }
        cout << ans << " ";
    }

    return 0;
}*/

// 두 번째 풀이
// 알파벳 개수만큼 배열을 미리 만들어 놓고 string을 탐색하면서 일치하면 값을 올림
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 지역변수는 선언만 하면 쓰레기 값을 가짐
    int alphabet[26] = {};
    string s;
    cin >> s;

    for (auto c: s) {
        alphabet[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }

    return 0;
}