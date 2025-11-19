#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<vector<vector<int>>> dp;

bool helper(int i, int r, bool taken) {
    if (i == n) {
        return taken && (r == 0);
    }

    int &res = dp[i][r][taken];
    if (res != -1) return res;

    bool ok = false;

    // take arr[i]
    ok |= helper(i + 1, (r + arr[i]) % m, true);

    // skip arr[i]
    ok |= helper(i + 1, r, taken);

    return res = ok;
}

int main() {
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));

    bool ans = helper(0, 0, false);

    cout << (ans ? "YES" : "NO");
}
