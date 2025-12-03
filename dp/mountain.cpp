#include <bits/stdc++.h>
using namespace std;

vector<long long> h;
vector<int> L, R;
vector<int> dp;
int n;

// Memoized DFS: compute max glide route starting from mountain i
int solve(int i) {
    if (i == -1) return 0;
    if (dp[i] != -1) return dp[i];

    int best = 0;
    if (L[i] != -1) best = max(best, solve(L[i]));
    if (R[i] != -1) best = max(best, solve(R[i]));

    return dp[i] = best + 1;   // count this mountain + best next
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    L.assign(n, -1);
    R.assign(n, -1);
    dp.assign(n, -1);

    // Find previous greater (nearest higher on the left)
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) L[i] = st.top();
        st.push(i);
    }

    // Clear stack and find next greater (nearest higher on the right)
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) R[i] = st.top();
        st.push(i);
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, solve(i));
    }

    cout << ans;
    return 0;
}
