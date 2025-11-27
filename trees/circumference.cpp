#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int farthestNode, maxDist;

// YOUR helper() EXACT, UNCHANGED
int helper(int node, int parent, vector<vector<int>>& adj) {
    int maxi = 0;
    for (int nxt : adj[node]) {
        if (nxt == parent) continue;
        maxi = max(maxi, helper(nxt, node, adj));
    }
    return 1 + maxi;
}

// Wrapper DFS to track REAL distance (not subtree height)
void dfs(int node, int parent, int dist) {
    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }
    for (int nxt : adj[node]) {
        if (nxt == parent) continue;
        dfs(nxt, node, dist + 1);
    }
}

int main() {
    int n;
    cin >> n;

    adj.assign(n+1, {});

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 1st DFS from node 1 → find farthest node A
    maxDist = -1;
    dfs(1, -1, 0);
    int A = farthestNode;

    // 2nd DFS from A → find farthest node B
    maxDist = -1;
    dfs(A, -1, 0);
    int diameter = maxDist;

    cout << 3 * diameter;
}
