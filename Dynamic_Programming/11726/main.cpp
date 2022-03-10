#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int rect[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;

  rect[1] = 1;
  rect[2] = 2;

  for (int i = 3; i <= N; ++i) {
    rect[i] = (rect[i - 1] + rect[i - 2]) % 10007;
  }

  cout << rect[N] << endl;

  return 0;
}
