#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;

int arr[100001];
long long sum[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  cin >> arr[1];
  sum[1] = arr[1];

  for (int i = 2; i <= N; ++i) {
    cin >> arr[i];
    sum[i] = sum[i - 1] + arr[i];
  }

  for (int i = 0; i < M; ++i) {
    int x, y;
    cin >> x >> y;
    cout << sum[y] - sum[x - 1] << "\n";
  }

  return 0;
}
