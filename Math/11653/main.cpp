#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int divisor = 2;
  while (N != 1) {
    if (N % divisor == 0) {
      cout << divisor << "\n";
      N /= divisor;
    } else {
      if (divisor * divisor > N) {
        cout << N << "\n";
        break;
      }
      divisor++;
    }
  }

  return 0;
}

