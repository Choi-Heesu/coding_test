#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

bool findValue(int value) {
  int start = 0;
  int end = v.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;
    if (v[mid] == value) {
      return true;
    } else if (v[mid] > value) {
      end = mid - 1;
    } else if (v[mid] < value) {
      start = mid + 1;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  v.assign(N, 0);

  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  cin >> M;
  for (int i = 0; i < M; ++i) {
    int value;
    cin >> value;

    if (findValue(value)) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}

/*
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  v.assign(N, 0);

  for (int i = 0; i < N; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  cin >> M;
  for (int i = 0; i < M; ++i) {
    int value;
    cin >> value;

    if (binary_search(v.begin(), v.end(), value)) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}
*/

