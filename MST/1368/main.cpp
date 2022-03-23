#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int paddy[301][301];
bool visit[301];

int findCost() {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

  int cur = 1;
  visit[cur] = true;
  for (int j = 0; j <= N; ++j) {
    if (cur == j) continue;
    pq.push({paddy[cur][j], j});
  }

  int count = 0;
  int sum = 0;
  while (!pq.empty()) {
    int weight, dest;
    tie(weight, dest) = pq.top();
    pq.pop();

    if (visit[dest]) continue;
    visit[dest] = true;

    count++;
    sum += weight;
    for (int nxt = 0; nxt <= N; ++nxt) {
      if (dest == nxt) continue;
      pq.push({paddy[dest][nxt], nxt});
    }

    if (count == N) break;
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    int weight;
    cin >> weight;
    paddy[i][0] = weight;
    paddy[0][i] = weight;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cin >> paddy[i][j];
    }
  }

  cout << findCost() << endl;

  return 0;
}

