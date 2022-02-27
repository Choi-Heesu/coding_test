#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
set<vector<int>> ans;
vector<int> v;
vector<int> permutation;
bool check[10];

void recursive(int num) {
  if (num == m) {
    ans.insert(permutation);
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (check[i]) continue;
    check[i] = true;
    permutation.push_back(v[i]);
    recursive(num + 1);
    permutation.pop_back();
    check[i] = false;
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

  for (const auto &a : ans) {
    for (const auto &b : a) {
      cout << b << " ";
    }
    cout << "\n";
  }

  return 0;
}

/*
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n, m;
set<vector<int>> ans;
vector<int> v;
vector<int> permutation;
bool check[10];

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
    if (check[i] || value == v[i]) continue;
    check[i] = true;
    permutation.push_back(v[i]);
    recursive(num + 1);
    permutation.pop_back();
    check[i] = false;
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
*/
