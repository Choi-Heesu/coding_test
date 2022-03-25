#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = INT_MAX / 2 - 1;
int N, M;
int city[102][102];
int tracking[102][102];

void backTracking(int x, int y) {
  if (city[x][y] == 0) {
    cout << city[x][y] << "\n";
    return;
  }

  vector<int> bt;
  bt.push_back(y);
  while (tracking[x][bt.back()] != 0) {
    bt.push_back(tracking[x][bt.back()]);
  }

  cout << bt.size() << " ";
  while (!bt.empty()) {
    cout << bt.back() << " ";
    bt.pop_back();
  }

  cout << "\n";
}

void floyd() {
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        if (city[i][j] > city[i][k] + city[k][j]) {
          city[i][j] = city[i][k] + city[k][j];
          tracking[i][j] = tracking[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (city[i][j] == MAX) city[i][j] = 0;
    }
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      cout << city[i][j] << " ";
    }
    cout << "\n";
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      backTracking(i, j);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; ++i) {
    fill(city[i] + 1, city[i] + 1 + N, MAX);
  }

  for (int i = 0; i < M; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    city[a][b] = min(city[a][b], c);
    tracking[a][b] = a;
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j) city[i][j] = 0;
    }
  }

  floyd();

  return 0;
}

