#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Global variables for grid size, grid content, and memoization table
int n;
vector<string> s;
vector<vector<long long>> memo;
// Use a large, safe value for infinity (10^18)
const long long INF = 1e18; 

/**
 * @brief Calculates the cost of a cell (1-based indexing).
 * The cost is the character value 'A'=0, 'B'=1, etc.
 */
inline int cost(int i, int j) {
    // This is safe because it's only called for 1 <= i, j <= n
    return s[i - 1][j - 1] - 'A';
}

/**
 * @brief Top-down DP (memoization): Calculates the minimum cost
 * from cell (i, j) to (n, n). (1-based indexing)
 */
long long solve(int i, int j) {
    // 1. Base Case: Out of bounds (no path possible)
    if (i > n || j > n) return INF;

    long long& ans = memo[i][j];
    // Check if the result is already computed
    if (ans != -1) return ans;

    // 2. Base Case: Destination cell (n, n)
    if (i == n && j == n) {
        ans = cost(i, j); 
        return ans;
    }

    // 3. Recursive Step: Find the minimum cost from neighbors
    long long right = solve(i, j + 1); // Cost from moving Right
    long long down = solve(i + 1, j);  // Cost from moving Down

    // Calculate the minimum cost for the current cell
    if (right >= INF && down >= INF) {
        ans = INF; // Dead end
    } else {
        ans = cost(i, j) + min(right, down);
    }
    
    return ans;
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input grid size N
    if (!(cin >> n)) return 0;
    
    // Input the grid
    s.resize(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    // Prepare memoization table: initialize with -1
    // Use n+2 for safe 1-based indexing
    memo.assign(n + 2, vector<long long>(n + 2, -1));

    // Compute the minimum cost from the start (1, 1)
    solve(1, 1);

    // ----------------------------------------------------
    // Path Reconstruction with Tie-Breaker: Prefer DOWN
    // ----------------------------------------------------
    int i = 1, j = 1;
    string ans = "";

    while (i <= n && j <= n) {
        // Add the current cell's character
        ans += s[i - 1][j - 1];
        
        // Stop if we reached the destination
        if (i == n && j == n) break;

        // Get the pre-calculated minimum cost to the end from the neighbors
        // We use the memo table directly since solve(1,1) filled it.
        long long right_cost = (j < n) ? memo[i][j + 1] : INF;
        long long down_cost = (i < n) ? memo[i + 1][j] : INF;

        // The total cost from the current cell (i, j) must be equal to memo[i][j]
        long long current_min_cost = memo[i][j];

        // Check which move (or both) leads to the minimal cost
        bool can_go_right = (j < n) && (cost(i, j) + right_cost == current_min_cost);
        bool can_go_down = (i < n) && (cost(i, j) + down_cost == current_min_cost);

        // **Tie-breaking logic**: If both are valid, prefer moving Down (i++).
        if (can_go_down) {
            // Move Down if it's minimal, even if Right is also minimal (prefer down)
            ++i;
        } else if (can_go_right) {
            // Only move Right if Down was not minimal
            ++j;
        } else {
             // Should not happen for a valid path
             break; 
        }
    }

    cout << ans << '\n';
    return 0;
}