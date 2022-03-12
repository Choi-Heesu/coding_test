#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> costs;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  costs.assign(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> costs[i];
  }

  int answer = 0;
  for (int i = N - 1; i >= 0; --i) {
    if (K >= costs[i]) {
      answer += K / costs[i];
      K = K % costs[i];
    }
  }
  cout << answer << endl;

  return 0;
}

