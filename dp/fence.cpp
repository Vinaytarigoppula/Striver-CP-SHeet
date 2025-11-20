#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, k;
    cin >> n >> a >> b >> k;

    // dp[i]: number of ways to reach floor i after the current step.
    vector<int> dp(n + 1, 0);
    dp[a] = 1; // Initial state: 1 way to be at floor 'a'

    // Loop for k steps
    while (k--) {
        // diff[i]: the amount to add starting from index i in the next step.
        // We use an n+2 size array for 1-based indexing and the R+1 boundary.
        vector<int> diff(n + 2, 0); 

        // 1. Iterate over the SOURCE floor 'j' (previous step)
        for (int j = 1; j <= n; j++) {
            if (dp[j] == 0) continue; 

            // Calculate the distance from the source 'j' to the forbidden floor 'b'
            // D_j is the maximum allowed distance for a move.
            int D_j = abs(j - b);

            // Valid moves 'i' must satisfy |j - i| < D_j.
            // This translates to the range: j - D_j < i < j + D_j.
            // Inclusive bounds: [j - D_j + 1, j + D_j - 1]
            
            int L_j = j - D_j + 1;
            int R_j = j + D_j - 1;

            // Clamp the range to the building limits [1, n]
            L_j = max(1, L_j);
            R_j = min(n, R_j);
            
            if (L_j > R_j) continue; // Invalid range (shouldn't happen with constraints)

            // Update the difference array (O(1) operation)
            // Add dp[j] to the range [L_j, R_j]
            diff[L_j] = (diff[L_j] + dp[j]) % MOD;
            
            // Subtract dp[j] at the index R_j + 1 to stop the addition there
            if (R_j + 1 <= n + 1) {
                diff[R_j + 1] = (diff[R_j + 1] - dp[j] + MOD) % MOD;
            }
        }
        
        // 2. Compute the new DP state 'ndp' using prefix sums on the difference array
        vector<int> ndp(n + 1, 0);
        long long current_sum = 0;
        for (int i = 1; i <= n; i++) {
            // Calculate the prefix sum (which is ndp[i] before adjustments)
            current_sum = (current_sum + diff[i]) % MOD;
            ndp[i] = (int)current_sum;
            
            // ADJUSTMENT 1: The destination floor 'i' must not be the same as the source 'j'.
            // The range update above included i=j (where i is the destination, j is the source).
            // We must subtract the ways that came from the floor itself: dp[i].
            ndp[i] = (ndp[i] - dp[i] + MOD) % MOD;
            
            // ADJUSTMENT 2: The destination floor 'i' cannot be 'b'.
            if (i == b) {
                ndp[i] = 0;
            }
        }

        dp = ndp; // Move to the next step
    }

    // Final result: sum of all ways to reach any floor after k steps
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << '\n';
    return 0;
}