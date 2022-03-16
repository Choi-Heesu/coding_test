#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int value;
    cin >> value;

    if (value == 1) {
      ans++;
      continue;
    }

    for (int j = 2; j * j <= value; ++j) {
      if (value % j == 0) {
        ans++;
        break;
      }
    }
  }

  cout << N - ans << endl;

  return 0;
}

