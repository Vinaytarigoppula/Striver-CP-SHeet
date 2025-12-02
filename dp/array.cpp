#include <bits/stdc++.h>
using namespace std;

static const int mod = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(n+1, vector<long long>(m+2, 0));
    vector<int> arr(n+1);

    for (int i = 1; i <= n; i++) cin >> arr[i];

    // Base case
    if (arr[1] == 0) {
        for (int v = 1; v <= m; v++)
            dp[1][v] = 1;
    } else {
        dp[1][arr[1]] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            // Skip invalid values
            if (arr[i] != 0 && arr[i] != j) continue;

            long long ways = dp[i-1][j];

            if (j > 1)
                ways = (ways + dp[i-1][j-1]) % mod;

            if (j < m)
                ways = (ways + dp[i-1][j+1]) % mod;

            dp[i][j] = ways;
        }
    }

    long long ans = 0;
    for (int v = 1; v <= m; v++)
        ans = (ans + dp[n][v]) % mod;

    cout << ans;
}
