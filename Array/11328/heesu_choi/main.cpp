#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 첫 번째 풀이
// 문자열을 정렬하여 같은지 확인
/*int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i = 0; i < num; ++i) {
        string s1, s2;
        cin >> s1 >> s2;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        cout << (s1 == s2 ? "Possible\n" : "Impossible\n");
    }

    return 0;
}*/


// 두 번째 풀이
// 각 문자열이 영어 소문자로만 이루어졌기 때문에 알파벳 개수가 같은지 확인
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i = 0; i < num; ++i) {
        int alphabet[26] = {};
        string s1, s2;
        cin >> s1 >> s2;

        for (auto c1: s1) {
            alphabet[c1 - 'a']++;
        }

        for (auto c2: s2) {
            alphabet[c2 - 'a']--;
        }

        int index;
        for (index = 0; index < 26; ++index) {
            if (alphabet[index] != 0) break;
        }

        cout << (index == 25 ? "Possible\n" : "Impossible\n");
    }

    return 0;
}
