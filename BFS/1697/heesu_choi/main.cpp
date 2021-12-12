#include <iostream>
#include <queue>

using namespace std;

bool visit[100000];
int n, k;
int ans = 99999999;

int moveLocation(int loc, int option) {
    if (option == 0) {
        loc += 1;
        if (loc > 100000) return -1;
    } else if (option == 1) {
        loc -= 1;
        if (loc < 0) return -1;
    } else if (option == 2) {
        loc *= 2;
        if (loc > 100000) return -1;
    }
    return loc;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int>> q;

    cin >> n >> k;

    if (n >= k) {
        ans = n - k;
        cout << ans << endl;
        return 0;
    }

    visit[n] = true;
    q.push({n, 0});

    while (!q.empty()) {
        int cur_loc = q.front().first;
        int time = q.front().second;
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int loc = moveLocation(cur_loc, i);
            if (loc == -1 || visit[loc]) continue;
            if (loc == k) {
                cout << min(ans, time + 1) << endl;
                return 0;
            } else if (loc > k){
                ans = min(ans, time + loc - k + 1);
                continue;
            }

            q.push({loc, time + 1});
            visit[loc] = true;
        }
    }

    cout << ans << endl;

    return 0;
}
