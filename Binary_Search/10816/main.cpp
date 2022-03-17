#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int findValueLeftIndex(int value) {
  int start = 0;
  int end = v.size();

  while (start < end) {
    int mid = (start + end) / 2;
    if (v[mid] >= value) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }

  return start;
}

int findValueRightIndex(int value) {
  int start = 0;
  int end = v.size();

  while (start < end) {
    int mid = (start + end) / 2;
    if (v[mid] > value) {
      end = mid;
    } else {
      start = mid + 1;
    }
  }

  return start;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  v.assign(N, 0);

  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  cin >> M;

  for (int i = 0; i < M; ++i) {
    int value;
    cin >> value;

    cout << findValueRightIndex(value) - findValueLeftIndex(value) << " ";
  }

  return 0;
}
