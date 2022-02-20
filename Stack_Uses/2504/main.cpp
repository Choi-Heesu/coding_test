#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

// 괄호가 닫힐 때 그 안에 들어 있는 숫자를 모두 더한 후 괄호 종류에 맞게 곱해주는 방식
// 아직 계산할 내용이 남아 있으면 (괄호가 끝나지 않았으면) stack에 넣어주고 아니면 총합에 더해줌
// 계산한 값을 stack에 넣을 수 있게 string으로 변환했는데 char와 string을 변환하며 문제가 발생할 확률이 높음
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<char, string> m1 = {{')', "("}, {']', "["}};
    map<char, int> m2 = {{')', 2}, {']', 3}};
    vector<string> stack;
    int ans = 0;
    string str;
    cin >> str;

    string check;
    for (auto c: str) {
        if (!check.empty()) {
            if (check.back() == '(' && c == ')') {
                check.pop_back();
            } else if (check.back() == '[' && c == ']') {
                check.pop_back();
            } else {
                check.push_back(c);
            }
        } else {
            check.push_back(c);
        }
    }

    if (!check.empty()) {
        ans = 0;
        cout << ans << "\n";
        return 0;
    }

    for (auto c: str) {
        if (!stack.empty()) {
            int num = 0;
            if (c == ')' || c == ']') {
                while (stack.back() != m1[c]) {
                    num += stoi(stack.back());
                    stack.pop_back();
                }

                stack.pop_back();
                num = num == 0 ? m2[c] : m2[c] * num;

                if (stack.empty()) ans += num;
                else stack.push_back(to_string(num));
            } else {
                string tmp(1, c);
                stack.push_back(tmp);
            }
        } else {
            string tmp(1, c);
            stack.push_back(tmp);
        }
    }

    cout << ans << "\n";

    return 0;
}
