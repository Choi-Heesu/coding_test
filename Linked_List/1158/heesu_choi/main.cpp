#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 첫 번째 풀이
// 리스트를 사용하는 방법
/*
int n, k, check;
list<int> people;
list<int>::iterator iter;
vector<int> answer;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        people.push_back(i);
    }

    check = k;
    iter = people.begin();
    while (answer.size() != n) {
        check--;
        if (check == 0) {
            answer.push_back(*iter);
            iter = people.erase(iter);
            check = k;
        } else {
            iter++;
        }

        if (iter == people.end()) iter = people.begin();
    }

    int index = 0;
    cout << "<";
    for (index = 0; index < n - 1; ++index) {
        cout << answer[index] << ", ";
    }
    cout << answer[index] << ">\n";

    return 0;
}
*/

// 두 번째 풀이
// 배열을 사용하는 방법
int n, k;
int nxt[5001];
int pre[5001];
vector<int> answer;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 1; i <= n; ++i) {
        if (i == n) nxt[i] = 1;
        else nxt[i] = i + 1;

        if (i == 1) pre[i] = n;
        else pre[i] = i - 1;
    }

    int cur = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cur = nxt[cur];
        }
        nxt[pre[cur]] = nxt[cur];
        pre[nxt[cur]] = pre[cur];
        answer.push_back(cur);
    }

    int index;
    cout << "<";
    for (index = 0; index < n - 1; ++index) {
        cout << answer[index] << ", ";
    }
    cout << answer[index] << ">\n";

    return 0;
}
