#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool arr[6561][6561];

void recursive(int x, int y, int n) {
  if (n == 1) return;

  n = n / 3;
  for (int i : {0, 1, 2}) {
    for (int j : {0, 1, 2}) {
      if (i == 1 && j == 1) {
        for (int a = x + n; a < x + 2 * n; ++a) {
          for (int b = y + n; b < y + 2 * n; ++b) {
            arr[a][b] = true;
          }
        };
      } else {
        recursive(x + i * n, y + j * n, n);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  recursive(0, 0, num);

  for (int i = 0; i < num; ++i) {
    for (int j = 0; j < num; ++j) {
      if(arr[i][j]) cout << ' ';
      else cout << '*';
    }
    cout << endl;
  }

  return 0;
}
