#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
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
    for (int i = 0; i < choice.size(); ++i) {
      if (!choice[i]) cout << v[i] << " ";
    }
    cout << "\n";
  } while (next_permutation(choice.begin(), choice.end()));

  return 0;
}
