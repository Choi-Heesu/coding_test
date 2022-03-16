#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> N;

  vector<int> num(N + 1, 1);

  num[1] = 0;
  for (int i = 2; i <= N; ++i) {
    if (!num[i]) continue;
    for (int j = 2; i * j <= N; ++j) {
      num[i * j] = 0;
    }
  }

  for (int i = M; i <= N; ++i) {
    if (num[i]) cout << i << "\n";
  }

  return 0;
}

