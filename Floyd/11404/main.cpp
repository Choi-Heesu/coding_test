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

void Floyd() {
  for (int k = 1; k <= N; ++k) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= N; ++j) {
        city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
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
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (i == j) city[i][j] = 0;
    }
  }

  Floyd();

  return 0;
}

