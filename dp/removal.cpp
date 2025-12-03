#include <bits/stdc++.h>
using namespace std;

vector<long long> arr;
long long dp[5005][5005];
bool vis[5005][5005];

long long helper(int i, int j, bool turn) {
    if (i > j) return 0;
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = true;

    if (turn) {
        // My turn: I want to maximize my score
        long long takeLeft  = arr[i] + helper(i+1, j, false);
        long long takeRight = arr[j] + helper(i, j-1, false);
        return dp[i][j] = max(takeLeft, takeRight);
    } else {
        // Opponent's turn: tries to minimize MY score
        long long left  = helper(i+1, j, true);
        long long right = helper(i, j-1, true);
        return dp[i][j] = min(left, right);
    }
}

int main() {
    int n; 
    cin >> n;

    arr.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << helper(0, n-1, true);
}
