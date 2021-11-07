#include <iostream>
#include <algorithm>

using namespace std;

// 첫 번째 풀이
// 이중 for 문을 돌려서 최대 넓이 구하는 방식
// 시간 초과 남
int arr[100001];
long long ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; ++i) {
            int height = arr[i];
            int width = 1;
            long long max_area = 0;
            for (int j = i; j <= n; ++j) {
                if (arr[j] == 0) break;

                height = min(height, arr[j]);
                long long area = width * height;
                max_area = max(max_area, area);
                width++;
            }
            ans = max(ans, max_area);
        }

        cout << ans << "\n";
        ans = 0;
        fill(arr, arr + 100001, 0);
    }

    return 0;
}
