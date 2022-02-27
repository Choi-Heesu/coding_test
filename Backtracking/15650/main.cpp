#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<int> check;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    v.push_back(i + 1);
  }

  for (int i = 0; i < n; ++i) {
    if (i < m) {
      check.push_back(0);
    } else{
      check.push_back(1);
    }
  }

  do {
    for (int i = 0; i < check.size(); ++i) {
      if (check[i] == 0) cout << v[i] << " ";
    }
    cout << "\n";
  } while (next_permutation(check.begin(), check.end()));

  return 0;
}
