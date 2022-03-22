#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> student[32001];
int precede[32001];

void sorting() {
  queue<int> q;
  for (int i = 1; i <= N; ++i) {
    if (precede[i] != 0) continue;
    q.push(i);
  }

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    for (auto nxt : student[cur]) {
      if (--precede[nxt] != 0) continue;
      q.push(nxt);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    student[a].push_back(b);
    precede[b]++;
  }

  sorting();

  return 0;
}

