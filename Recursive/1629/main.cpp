#include <iostream>
#include <vector>

using namespace std;

long long recursive(long long a, long long b, long long c) {
  if (b == 1) return a % c;

  long long value = recursive(a, b / 2, c);
  value = (value * value) % c;
  
  if (b % 2 == 0) return value;
  else return (value * a) % c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long a, b, c;
  cin >> a >> b >> c;

  cout << recursive(a, b, c);

  return 0;
}
