#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int GCD(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int LCM(int a, int b) { return a / GCD(a, b) * b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    x = x % M;
    y = y % N;
    int max = LCM(M, N);
    int possible = false;
    for (int j = x; j <= max; j += M) {
      if (j % N == y) {
        cout << j << "\n";
        possible = true;
        break;
      }
    }

    if (!possible) cout << -1 << "\n";
  }

  return 0;
}

