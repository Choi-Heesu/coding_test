#include <iostream>
#include <sstream>
#include <deque>
#include <string>

using namespace std;

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        deque<int> dq;
        string p, arr;
        int n;
        cin >> p >> n >> arr;

        if (n > 0) {
            string arr_parse = arr.substr(1, arr.size() - 2);
            istringstream iss(arr_parse);
            string token;
            while (getline(iss, token, ',')) {
                dq.push_back(stoi(token));
            }
        }

        bool forward = true;
        bool success = true;
        for (auto func: p) {
            if (func == 'R') {
                forward = !forward;
            } else if (func == 'D') {
                if (dq.empty()) {
                    success = false;
                    break;
                }

                if (forward) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (success) {
            cout << "[";
            if (dq.size() != 0) {
                if (forward) {
                    for (int k = 0; k < dq.size() - 1; ++k) {
                        cout << dq[k] << ",";
                    }
                    cout << dq[dq.size() - 1];
                } else {
                    for (int k = dq.size() - 1; k > 0; --k) {
                        cout << dq[k] << ",";
                    }
                    cout << dq[0];
                }
            }
            cout << "]\n";
        } else {
            cout << "error\n";
        }
    }

    return 0;
}
