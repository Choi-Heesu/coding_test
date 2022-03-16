#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> dp;
vector<int> weight;
vector<int> value;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  dp.assign(N + 1, vector<int>(K + 1, 0));
  weight.assign(N + 1, 0);
  value.assign(N + 1, 0);

  for (int i = 1; i <= N; ++i) {
    cin >> weight[i] >> value[i];
  }

  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= K; ++j) {
      if (weight[i] <= j) {
        dp[i][j] = max(value[i] + dp[i - 1][j - weight[i]], dp[i - 1][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << dp[N][K] << endl;

  return 0;
}

