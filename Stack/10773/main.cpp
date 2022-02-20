#include <iostream>
#include <stack>

using namespace std;

int total;
stack<int> s;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int num;
        cin >> num;

        if (num == 0) {
            int wrong = s.top();
            total -= wrong;
            s.pop();
        } else {
            total += num;
            s.push(num);
        }
    }

    cout << total << "\n";

    return 0;
}
