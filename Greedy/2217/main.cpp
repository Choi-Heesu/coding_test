#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> ropes;

int main() {

  cin >> N;
  ropes.assign(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> ropes[i];
  }

  sort(ropes.begin(), ropes.end());

  int count = N;
  int answer = ropes[0] * count;
  for (int i = 1; i < N; ++i) {
    count--;
    if (answer < ropes[i] * count) {
      answer = ropes[i] * count;
    }
  }

  cout << answer << endl;


  return 0;
}

