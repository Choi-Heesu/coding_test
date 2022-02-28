#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;

    vector<int> v;
    vector<int> choice(n, 1);
    fill(choice.begin(), choice.begin() + 6, 0);

    for (int i = 0; i < n; ++i) {
      int input;
      cin >> input;
      v.push_back(input);
    }

    do {
      for (int i = 0; i < choice.size(); ++i) {
        if (!choice[i]) cout << v[i] << " ";
      }
      cout << "\n";
    } while (next_permutation(choice.begin(), choice.end()));

    cout << "\n";
  }

  return 0;
}

/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> ans;
vector<int> choice;
vector<bool> check;

void recursive(int num) {
  if(num == n) {
    for(int i = 0; i < n; ++i) {
      if(!ans[i]) cout << v[i] << " ";
    }
    cout << "\n";
    return;
  }

  int value = -1;
  for(int i = 0; i < n; ++i) {
    if(check[i] || value == choice[i]) continue;
    check[i] = true;
    ans.push_back(choice[i]);
    recursive(num + 1);
    ans.pop_back();
    check[i] = false;
    value = choice[i];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> n;
    if (n == 0) break;

    check.assign(n, false);
    choice.assign(n, 1);
    fill(choice.begin(), choice.begin() + 6, 0);

    for (int i = 0; i < n; ++i) {
      int input;
      cin >> input;
      v.push_back(input);
    }

    recursive(0);

    ans.clear();
    v.clear();
    choice.clear();
    check.clear();

    cout << "\n";
  }

  return 0;
}
*/

/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> ans;

void recursive(int index, int num) {
  if (index == n) return;

  if (num == 6) {
    for (int a : ans) {
      cout << a << " ";
    }
    cout << "\n";
    return;
  }

  for (int i = index + 1; i < n; ++i) {
    ans.push_back(v[i]);
    recursive(i, num + 1);
    ans.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    cin >> n;
    if (n == 0) break;

    for (int i = 0; i < n; ++i) {
      int input;
      cin >> input;
      v.push_back(input);
    }

    recursive(-1, 0);

    ans.clear();
    v.clear();

    cout << "\n";
  }

  return 0;
}
*/
