#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

int N, M, V;
vector<int> graph[1001];
bool visit[1001];

void DFS(int start) {
  if (visit[start]) return;
  visit[start] = true;
  cout << start << " ";
  for (auto next : graph[start]) {
    if (visit[next]) continue;
    DFS(next);
  }
}

/*void DFS(int start) {
    fill(visit, visit + 1001, false);
    
    stack<int> s;
    s.push(start);
    
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        
        if(visit[cur]) continue;
        visit[cur] = true;
        
        cout << cur << " ";
        for(auto iter = graph[cur].rbegin(); iter != graph[cur].rend(); iter++) {
            int next = *iter;
            if(visit[next]) continue;
            s.push(next);
        }
    }
}*/

void BFS(int start) {
  fill(visit, visit + 1001, false);

  queue<int> q;
  q.push(start);
  visit[start] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    cout << cur << " ";
    for (auto next : graph[cur]) {
      if (visit[next]) continue;
      visit[next] = true;
      q.push(next);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> V;
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }

  DFS(V);
  cout << "\n";
  BFS(V);

  return 0;
}

