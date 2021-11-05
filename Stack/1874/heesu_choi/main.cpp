#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s;
vector<char> answer;
int idx = 1;
bool possible = true;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        if (possible) {
            for (; idx <= num; ++idx) {
                s.push(idx);
                answer.push_back('+');
            }

            if (s.top() == num) {
                s.pop();
                answer.push_back('-');
            } else {
                possible = false;
            }
        }
    }

    if (possible) {
        for (auto c: answer) {
            cout << c << "\n";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}
