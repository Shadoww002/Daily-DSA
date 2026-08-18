class Solution {
    vector<vector<int>> dp;

    int solve(int e, int f) {

        if (e == 1)
            return f;

        if (f <= 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];

        int ans = INT_MAX;

        int lo = 1;
        int hi = f;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            int broken = solve(e - 1, mid - 1);
            int not_broken = solve(e, f - mid);

            int worst = 1 + max(broken, not_broken);

            ans = min(ans, worst);

            if (broken < not_broken) {
                // Need to go higher
                lo = mid + 1;
            }
            else {
                // Need to go lower
                hi = mid - 1;
            }
        }

        return dp[e][f] = ans;
    }

public:
    int superEggDrop(int k, int n) {

        dp.assign(k + 1, vector<int>(n + 1, -1));

        return solve(k, n);
    }
};