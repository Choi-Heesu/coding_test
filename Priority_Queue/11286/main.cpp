#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

struct compare {
  bool operator()(int a, int b) {
    if (abs(a) == abs(b)) return a > b;
    return abs(a) > abs(b);
  }
};

int N;
priority_queue<int, vector<int>, compare> pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 0; i < N; ++i) {
    int value;
    cin >> value;

    if (value == 0) {
      if (pq.empty()) {
        cout << "0\n";
      } else {
        cout << pq.top() << "\n";
        pq.pop();
      }
    } else {
      pq.push(value);
    }
  }

  return 0;
}

