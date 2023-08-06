#define ll long long
#define mod 1000000007

class Solution {
public:
    ll dp[101][101];  // Memoization array to store computed values

    ll sol(int len, int num, int goal, int n, int k) {
        // If the playlist length matches the goal length
        if (len == goal) {
            // Return 1 if all distinct songs are used, 0 otherwise
            return num == n;
        }

        // If the value is already computed, return it from memoization
        if (dp[len][num] != -1) {
            return dp[len][num];
        }

        // Calculate the number of playlists by adding a known song or a new song
        ll ans = (sol(len + 1, num, goal, n, k) * max(0, num - k)) % mod;
        ll res = (sol(len + 1, num + 1, goal, n, k) * (n - num)) % mod;

        // Store the result in memoization array and return
        return dp[len][num] = (ans + res) % mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp, -1, sizeof(dp));  // Initialize memoization array with -1
        return sol(0, 0, goal, n, k);  // Call the recursive function
    }
};
