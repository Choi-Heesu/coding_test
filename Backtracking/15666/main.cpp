#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<int> permutation;

void recursive(int num) {
  if (num == m) {
    for (int i = 0; i < m; ++i) {
      cout << permutation[i] << " ";
    }
    cout << "\n";
    return;
  }

  int value = 0;
  for (int i = 0; i < n; ++i) {
    if (value == v[i]) continue;
    if (!permutation.empty() && permutation.back() > v[i]) continue;
    permutation.push_back(v[i]);
    recursive(num + 1);
    permutation.pop_back();
    value = v[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int value;
    cin >> value;
    v.push_back(value);
  }

  sort(v.begin(), v.end());

  recursive(0);

  return 0;
}
