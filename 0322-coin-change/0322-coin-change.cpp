class Solution {
    vector<vector<long long>> dp ;
    int solve(int n, int amt ,vector<int> &coins){
        if(n == 0){
            if(amt == 0) return 0 ;
            return INT_MAX-1;
        }
        if(amt == 0) return 0 ;

        if(dp[n][amt] != -1) return dp[n][amt];
        if(coins[n-1] <= amt){
            return dp[n][amt] = min(solve(n , amt - coins[n-1] , coins)+1 , solve(n-1 , amt , coins))  ;
        }
        else{
            return dp[n][amt] = solve(n-1 , amt , coins);
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp.assign(n+1 , vector<long long>(amount+1 , -1));
        int ans = solve(n ,amount , coins);
        if(ans >= INT_MAX-1) return -1 ;
        return ans ;
    }
};