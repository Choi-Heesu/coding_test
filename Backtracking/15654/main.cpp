#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;
vector<int> ans;
bool check[8];

void recursive(int index, int num) {
  if (num == m) {
    for (int a : ans) {
      cout << a << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (check[i]) continue;
    check[i] = true;
    ans.push_back(v[i]);
    recursive(index + 1, num + 1);
    ans.pop_back();
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

  recursive(0, 0);

  return 0;
}

/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> ans;
vector<int> choice;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int value;
    cin >> value;
    v.push_back(value);

    if (i < m) {
      choice.push_back(0);
    } else {
      choice.push_back(1);
    }
  }

  sort(v.begin(), v.end());

  do {
    vector<int> tmp;
    for (int i = 0; i < choice.size(); ++i) {
      if (choice[i] == 0) tmp.push_back(v[i]);
    }

    do {
      ans.push_back(tmp);
    } while (next_permutation(tmp.begin(), tmp.end()));
  } while (next_permutation(choice.begin(), choice.end()));

  sort(ans.begin(), ans.end());

  for(const auto& a : ans) {
    for(const auto& b : a) {
      cout << b << " ";
    }
    cout << "\n";
  }

  return 0;
}
*/
