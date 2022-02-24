#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int answer = 0;
bool check_col[15];
bool check_left_cross[30];
bool check_right_cross[30];

void recursive(int i) {
  if (i == n) {
    answer++;
    return;
  }

  for (int j = 0; j < n; ++j) {
    if (check_col[j] || check_left_cross[i - j + n] || check_right_cross[i + j]) continue;
    check_col[j] = true;
    check_left_cross[i - j + n] = true;
    check_right_cross[i + j] = true;
    recursive(i + 1);
    check_col[j] = false;
    check_left_cross[i - j + n] = false;
    check_right_cross[i + j] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  recursive(0);
  cout << answer << "\n";

  return 0;
}
