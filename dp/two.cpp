#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    long long total = 1LL * n * (n + 1) / 2;

    if (total % 2 != 0) {
        cout << 0;
        return 0;
    }

    int equi = total / 2;

    vector<vector<long long>> dp(n + 1, vector<long long>(equi + 1, 0));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= equi; j++) {

            long long nottake = dp[i - 1][j];

            long long take = 0;
            if (j >= i) take = dp[i - 1][j - i];

            dp[i][j] = (take + nottake) % mod;
        }
    }

    long long ways = dp[n][equi];

    // Modular inverse of 2 under mod 1e9+7
    long long inv2 = 500000004;

    cout << (ways * inv2) % mod;
}
