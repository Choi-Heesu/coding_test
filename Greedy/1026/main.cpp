#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  vector<int> a(N, 0);
  vector<int> b(N, 0);

  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < N; ++i) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), [](int x, int y) { return x > y; });

  int answer = 0;
  for (int i = 0; i < N; ++i) {
    answer += a[i] * b[i];
  }

  cout << answer << endl;

  return 0;
}

