class Solution {
    // vector<vector<int>> dp ;
    int Subset(int n , int sum , vector<int> &nums){
        if(n == 0){
            if(sum == 0) return 1 ;
            return 0 ;
        }
        // if(dp[n][sum] != -1) return dp[n][sum];
        return Subset(n-1 , sum + nums[n-1] , nums) 
                            + Subset(n-1 , sum - nums[n-1] , nums);

    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        // dp.assign(n+1 , vector<int>(target + 1 , -1));

        return Subset(n , target , nums);
    }
};