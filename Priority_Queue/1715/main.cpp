#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<>> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; ++i) {
    int value;
    cin >> value;
    pq.push(value);
  }

  long long ans = 0;
  while (!pq.empty()) {
    int A = pq.top();
    pq.pop();

    if (pq.empty()) break;

    int B = pq.top();
    pq.pop();

    ans += A + B;
    pq.push(A + B);
  }

  cout << ans << endl;

  return 0;
}

