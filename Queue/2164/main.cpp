#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    int num = q.size();
    while (num > 1) {
        q.pop();
        q.push(q.front());
        q.pop();
        num--;
    }

    cout << q.front() << '\n';

    return 0;
}
