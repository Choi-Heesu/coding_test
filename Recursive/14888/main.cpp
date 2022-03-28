#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[12];
int op[5];
int MAX = -1000000001;
int MIN = 1000000001;

void cal(int index, int sum) {
  if (index > N) {
    if (sum > MAX) {
      MAX = sum;
    }
    if (sum < MIN) {
      MIN = sum;
    }
    return;
  }

  if (op[1] != 0) {
    op[1]--;
    cal(index + 1, sum + arr[index]);
    op[1]++;
  }
  if (op[2] != 0) {
    op[2]--;
    cal(index + 1, sum - arr[index]);
    op[2]++;
  }
  if (op[3] != 0) {
    op[3]--;
    cal(index + 1, sum * arr[index]);
    op[3]++;
  }
  if (op[4] != 0) {
    op[4]--;
    cal(index + 1, sum / arr[index]);
    op[4]++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i <= 4; ++i) {
    cin >> op[i];
  }

  cal(2, arr[1]);

  cout << MAX << endl;
  cout << MIN << endl;

  return 0;
}

