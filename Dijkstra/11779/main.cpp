#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = INT_MAX / 2 - 1;
vector<pair<int, int>> graph[1001];
int path[1001];
int tracking[1001];

int N, M, A, B;

void dijkstra() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  path[A] = 0;
  pq.emplace(0, A);

  while (!pq.empty()) {
    int cur_weight = pq.top().first;
    int cur_node = pq.top().second;
    pq.pop();

    if (path[cur_node] != cur_weight) continue;
    for (auto value : graph[cur_node]) {
      int nxt_weight = value.first;
      int nxt_node = value.second;
      if (path[nxt_node] <= path[cur_node] + nxt_weight) continue;
      path[nxt_node] = path[cur_node] + nxt_weight;
      pq.emplace(path[nxt_node], nxt_node);
      tracking[nxt_node] = cur_node;
    }
  }

  cout << path[B] << "\n";
  vector<int> bt;
  bt.push_back(B);
  while (tracking[bt.back()] != 0) {
    bt.push_back(tracking[bt.back()]);
  }
  cout << bt.size() << "\n";
  while (!bt.empty()) {
    cout << bt.back() << " ";
    bt.pop_back();
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  fill(path + 1, path + 1 + N, MAX);

  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].emplace_back(w, v);
  }

  cin >> A >> B;

  dijkstra();

  return 0;
}

