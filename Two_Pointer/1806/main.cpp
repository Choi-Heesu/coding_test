#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> S;
  v.assign(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  int ans = 100001;
  int index = 0;
  int sum = v[0];
  for (int i = 0; i < v.size(); ++i) {
    while (index < v.size() && sum < S) {
      index++;
      sum += v[index];
    }

    if (index >= v.size()) break;
    ans = min(ans, index - i + 1);
    sum -= v[i];
  }

  if (ans == 100001) ans = 0;
  cout << ans << endl;

  return 0;
}

