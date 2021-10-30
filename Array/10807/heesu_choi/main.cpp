#include <iostream>

using namespace std;

int arr[201];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, index;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        arr[tmp + 100]++;
    }

    cin >> index;
    cout << arr[index + 100] << "\n";

    return 0;
}
