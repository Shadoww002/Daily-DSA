class Solution {
    vector<vector<int>> dp;
    vector<vector<int>> pal;

    int solve(int i, int n, string& s) {

        if (i == n)
            return 0;

        if (dp[i][n] != -1)
            return dp[i][n];

        int ans = INT_MAX;

        for (int j = i; j < n; j++) {

            if (pal[i][j]) {

                int cost = 1 + solve(j + 1, n, s);

                ans = min(ans, cost);
            }
        }

        return dp[i][n] = ans;
    }

public:
    int minCut(string s) {

        int n = s.size();

        dp.assign(n + 1, vector<int>(n + 1, -1));
        pal.assign(n, vector<int>(n, 0));

        // Precompute palindromes
        for (int i = n - 1; i >= 0; i--) {

            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 1 || pal[i + 1][j - 1])) {

                    pal[i][j] = 1;
                }
            }
        }

        return solve(0, n, s) - 1;
    }
};