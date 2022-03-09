#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> stair;
vector<vector<int>> sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  stair.assign(N + 1, 0);
  sum.assign(N + 1, vector<int>(2, 0));
  for (int i = 1; i <= N; ++i) {
    cin >> stair[i];
  }

  sum[1][0] = stair[1];
  sum[1][1] = stair[1];
  for (int i = 2; i <= N; ++i) {
    sum[i][0] = max(sum[i - 2][0], sum[i - 2][1]) + stair[i];
    sum[i][1] = sum[i - 1][0] + stair[i];
  }

  int ans = 0;
  ans = max(sum[N][0], sum[N][1]);

  cout << ans << endl;

  return 0;
}

