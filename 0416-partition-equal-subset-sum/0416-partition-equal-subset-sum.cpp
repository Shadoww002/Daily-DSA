class Solution {
    vector<vector<int>> dp ;

    bool solve(int i ,int n , vector<int>&nums ,int sum , int target){

        if(sum == target) return true ;
        if(i == n) return false ;

        if(dp[i][sum] != -1) return dp[i][sum];

        if(sum + nums[i] <= target){
            return dp[i][sum] = solve(i+1 , n , nums , sum + nums[i] , target) ||
                    solve(i+1 , n , nums , sum , target);
        }
        else return solve(i+1 , n , nums , sum , target);
    }
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int total = 0 ;
        for(int num : nums) total += num ;
        if(total % 2 != 0) return false ;
        int target = total/2 ;

        dp.assign(n + 1 , vector<int> (target+1 , -1));

        return solve(0 , n , nums , 0 , target);
    }

};