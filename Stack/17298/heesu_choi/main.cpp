#include <iostream>
#include <vector>

using namespace std;

int n;
int input[1000000];
int ans[1000000];
vector<int> stack;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        ans[i] = -1;
    }

    for (int i = n - 1; i >= 0; --i) {
        while (!stack.empty()) {
            if (input[i] < stack.back()) {
                ans[i] = stack.back();
                break;
            }
            stack.pop_back();
        }
        stack.push_back(input[i]);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
