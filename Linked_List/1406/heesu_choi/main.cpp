#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

list<char> editor;
list<char>::iterator iter;
string str;
int num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> str;
    for (auto c: str) {
        editor.push_back(c);
    }
    iter = editor.end();

    cin >> num;
    for (int i = 0; i < num; ++i) {
        char c1, c2;
        cin >> c1;
        switch (c1) {
            case 'L':
                if (iter != editor.begin()) iter--;
                break;
            case 'D':
                if (iter != editor.end()) iter++;
                break;
            case 'B':
                if (iter == editor.begin()) break;
                iter--;
                iter = editor.erase(iter);
                break;
            case 'P':
                cin >> c2;
                editor.insert(iter, c2);
                break;
        }
    }

    for (auto c: editor) {
        cout << c;
    }
    cout << "\n";

    return 0;
}
