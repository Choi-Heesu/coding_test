#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        list<char> password;
        list<char>::iterator iter = password.begin();
        string s;
        cin >> s;
        for (auto c: s) {
            if (c == '<') {
                if (iter != password.begin()) iter--;
            } else if (c == '>') {
                if (iter != password.end()) iter++;
            } else if (c == '-') {
                if (iter != password.begin()) {
                    iter--;
                    iter = password.erase(iter);
                }
            } else {
                // iter는 index가 아니라 그 노드를 가리키는 포인터라 생각해야함
                // 즉, insert와 상관없이 iter는 원래 가리키던 노드를 그대로 유지함
                password.insert(iter, c);
            }
        }

        for (auto c: password) {
            cout << c;
        }
        cout << "\n";
    }

    return 0;
}
