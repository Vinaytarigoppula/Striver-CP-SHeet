#include <bits/stdc++.h>
using namespace std;

int modo = 1e9 + 7;
int n, k;
vector<vector<int>> dp;

int helper(int prev, int cnt) {
    if (cnt == k) return 1;

    int id = prev + 1;
    if (dp[id][cnt] != -1) return dp[id][cnt];

    long long ways = 0;

    if (prev == -1) {
        // prev = -1 → choose any number from 1..n
        for (int j = 1; j <= n; j++)
            ways = (ways + helper(j, cnt + 1)) % modo;
    } else {
        // only multiples of prev: prev, 2*prev, 3*prev ...
        for (int j = prev; j <= n; j += prev)
            ways = (ways + helper(j, cnt + 1)) % modo;
    }

    return dp[id][cnt] = ways;
}

int main() {
    cin >> n >> k;
    dp.assign(n + 2, vector<int>(k + 1, -1));
    cout << helper(-1, 0);
}
