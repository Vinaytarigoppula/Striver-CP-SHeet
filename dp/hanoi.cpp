#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<long long>> dp;

long long helper(int i, int prev, long long arr[][3]) {
    if (i >= n) return 0;

    if (dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    long long take = 0;
    if (prev == -1 ||
        (arr[i][1] <= arr[prev][1] && arr[i][1] > arr[prev][0])) {

        take = arr[i][2] + helper(i + 1, i, arr);
    }

    long long nottake = helper(i + 1, prev, arr);

    return dp[i][prev + 1] = max(take, nottake);
}

int main() {

    cin >> n;
    vector<array<long long, 3>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];

    // IMPORTANT FIX:
    // sort by b DESC, then a DESC
    sort(v.begin(), v.end(), [&](auto &x, auto &y) {
        if (x[1] != y[1]) return x[1] > y[1];  // outer radius descending
        return x[0] > y[0];                    // inner radius descending
    });

    long long arr[n][3];

    for (int i = 0; i < n; i++) {
        arr[i][0] = v[i][0];  // a
        arr[i][1] = v[i][1];  // b
        arr[i][2] = v[i][2];  // h
    }

    dp.assign(n + 1, vector<long long>(n + 1, -1));

    cout << helper(0, -1, arr);
}
