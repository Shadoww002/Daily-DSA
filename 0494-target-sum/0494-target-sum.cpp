class Solution {
    vector<vector<int>> dp;
    int Subset(int n, int sum, vector<int>& nums) {
        if (n == 0) {
            if (sum == 0)
                return 1;
            return 0;
        }
        if (dp[n][sum] != -1)
            return dp[n][sum];

        if (nums[n - 1] <= sum) {
            return dp[n][sum] = Subset(n - 1, sum - nums[n - 1], nums) +
                                Subset(n - 1, sum, nums);
        } else {
            return dp[n][sum] = Subset(n - 1, sum , nums);
        }
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = 0 ;
        for(int x : nums) total += x ;
        dp.assign(n + 1, vector<int>(total + 1, -1));
        target = abs(target);
        int val = (total + target)/2 ;

        if((total + target) % 2 != 0 || total < target) return 0 ;
        return Subset(n, val, nums);
    }
};