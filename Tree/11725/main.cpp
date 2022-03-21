#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<int> tree[100001];
int parent[100001];

void BFS(int root) {
  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto nxt : tree[cur]) {
      if (parent[cur] == nxt) continue;
      parent[nxt] = cur;
      q.push(nxt);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i < N; ++i) {
    int r, c;
    cin >> r >> c;
    tree[r].push_back(c);
    tree[c].push_back(r);
  }

  BFS(1);

  for (int i = 2; i <= N; ++i) {
    cout << parent[i] << "\n";
  }

  return 0;
}

