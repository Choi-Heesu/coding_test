#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int RGB[1002][3];
int sum[1002][3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
  }

  sum[0][0] = RGB[0][0];
  sum[0][1] = RGB[0][1];
  sum[0][2] = RGB[0][2];

  for (int i = 1; i < N; ++i) {
    sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + RGB[i][0];
    sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + RGB[i][1];
    sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + RGB[i][2];
  }

  int ans = min(min(sum[N - 1][0], sum[N - 1][1]), sum[N - 1][2]);

  cout << ans << endl;


  return 0;
}
