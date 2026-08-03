class Solution {
    vector<int> dp;
    int ways(int n){
        if(n < 0) return 0 ;
        if(n == 0) return 1;
        
        if(dp[n] != -1) return dp[n];
        return dp[n] = ways(n-1) + ways(n-2);
        }
public:
    int climbStairs(int n) {
        dp.assign(n+1 , -1);
        return ways(n);
    }
};