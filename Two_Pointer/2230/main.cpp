#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  v.assign(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int ans = INT_MAX;
  int index = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = index; j < N; ++j) {
      if (v[j] - v[i] == M) {
        cout << M << endl;
        return 0;
      } else if (v[j] - v[i] > M) {
        ans = min(ans, v[j] - v[i]);
        index = j;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}

