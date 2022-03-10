#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  arr[1] = 0;
  for (int i = 2; i <= N; ++i) {
    arr[i] = arr[i - 1] + 1;
    if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
    if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
  }

  cout << arr[N] << endl;

  int value = N;
  cout << value << " ";

  while (value > 1) {
    int tmp = value - 1;

    if (value % 2 == 0) {
      if (arr[value / 2] < arr[tmp]) {
        tmp = value / 2;
      }
    }

    if (value % 3 == 0) {
      if (arr[value / 3] < arr[tmp]) {
        tmp = value / 3;
      }
    }

    value = tmp;
    cout << value << " ";
  }
  cout << "\n";

  return 0;
}

