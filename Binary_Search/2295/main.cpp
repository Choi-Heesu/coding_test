#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> two;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  v.assign(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      two.push_back(v[i] + v[j]);
    }
  }

  sort(two.begin(), two.end());
  two.erase(unique(two.begin(), two.end()), two.end());

  int index = N - 1;
  for (int i = v.size() - 1; i >= 0; --i) {
    for (int j = two.size() - 1; j >= 0; --j) {
      int value = v[i] - two[j];
      if (value > 0) {
        if (binary_search(v.begin(), v.end(), value)) {
          cout << v[i] << endl;
          return 0;
        }
      }
    }
  }

  return 0;
}

