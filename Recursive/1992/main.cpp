#include <iostream>
#include <string>

using namespace std;

int arr[65][65];

void recursive(int x, int y, int n) {
  int value = arr[x][y];
  for (int i = x; i < x + n; ++i) {
    for (int j = y; j < y + n; ++j) {
      if (value != arr[i][j]) {
        n /= 2;
        cout << "(";
        recursive(x, y, n);
        recursive(x, y + n, n);
        recursive(x + n, y, n);
        recursive(x + n, y + n, n);
        cout << ")";
        return;
      }
    }
  }

  cout << value;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int num;
  cin >> num;

  for (int i = 0; i < num; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < s.size(); ++j) {
      arr[i][j] = s[j] - '0';
    }
  }

  recursive(0, 0, num);

  return 0;
}
