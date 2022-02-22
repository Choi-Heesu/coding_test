#include <iostream>
#include <vector>

using namespace std;

int paper[2187][2187];
int answer[3] = {0, 0, 0};

void recursive(int x, int y, int n) {
  int value = paper[x][y];
  for (int i = x; i < x + n; ++i) {
    for (int j = y; j < y + n; ++j) {
      if (value != paper[i][j]) {
        n /= 3;
        for (int a : {0, 1, 2}) {
          for (int b : {0, 1, 2}) {
            recursive(x + a * n, y + b * n, n);
          }
        }
        return;
      }
    }
  }

  answer[value] += 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  for (int i = 0; i < num; ++i) {
    for (int j = 0; j < num; ++j) {
      cin >> paper[i][j];
      paper[i][j] += 1;
    }
  }

  recursive(0, 0, num);

  for (int i : answer) {
    cout << i << endl;
  }

  return 0;
}
