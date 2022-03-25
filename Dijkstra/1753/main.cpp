#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = INT_MAX / 2 - 1;
vector<pair<int, int>> graph[20001];
int path[20001];

int V, E, K;

void dijkstra(int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  path[start] = 0;
  pq.emplace(0, start);

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
    }
  }

  for (int i = 1; i <= V; ++i) {
    if (path[i] == MAX) {
      cout << "INF\n";
    } else {
      cout << path[i] << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E >> K;

  fill(path + 1, path + 1 + V, MAX);

  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].emplace_back(w, v);
  }

  dijkstra(K);

  return 0;
}

