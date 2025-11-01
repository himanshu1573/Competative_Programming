#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;
const int N = 1e5 + 10; // Increased size to handle N up to 1e5
ll dp[N]; // Use long long to avoid overflow

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto &i : h) cin >> i;

    // Initialize dp array
    for (int i = 0; i < n; i++) {
        dp[i] = INF; // Set to a large value
    }
    dp[0] = 0; // Base case: Cost to reach Stone 0 is 0

    // Fill DP array
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }

    // Output the minimum cost to reach Stone n-1 (0-based indexing)
    cout << dp[n-1] << endl;

    return 0;
}