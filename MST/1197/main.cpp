#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int V, E;
vector<pair<int, int>> graph[10001];
bool check[10001];

int MST() {
  priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;

  check[1] = true;
  for (auto nxt : graph[1]) {
    pq.push({nxt.second, nxt.first});
  }

  int sum = 0;
  int count = 0;
  while (!pq.empty()) {
    int weight, dest;
    tie(weight, dest) = pq.top();
    pq.pop();

    if (check[dest]) continue;
    check[dest] = true;

    count++;
    sum += weight;
    for (auto nxt : graph[dest]) {
      pq.push({nxt.second, nxt.first});
    }

    if (count == V - 1) break;
  }
  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;

  for (int i = 0; i < E; ++i) {
    int A, B, C;
    cin >> A >> B >> C;
    graph[A].emplace_back(B, C);
    graph[B].emplace_back(A, C);
  }

  cout << MST() << endl;

  return 0;
}

