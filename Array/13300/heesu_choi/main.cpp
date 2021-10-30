#include <iostream>

using namespace std;

int student[6][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int s, y;
        cin >> s >> y;
        student[y - 1][s]++;
    }

    int ans = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (student[i][j] % k == 0) {
                ans += student[i][j] / k;
            } else {
                ans += student[i][j] / k + 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
