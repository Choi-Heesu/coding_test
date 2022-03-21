#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> graph[1001];
bool visit[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int count = 0;
  for (int i = 1; i <= N; ++i) {
    if (visit[i]) continue;
    visit[i] = true;
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto next : graph[cur]) {
        if (visit[next]) continue;
        visit[next] = true;
        q.push(next);
      }
    }

    count++;
  }

  cout << count << endl;

  return 0;
}

