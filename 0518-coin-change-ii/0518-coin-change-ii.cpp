class Solution {
    vector<vector<int>> dp ;
    int solve(int n, int amt , vector<int> &coins){
        if(n == 0 ){
            if(amt == 0) return 1 ;
            return 0 ;
        }
        if(dp[n][amt] != -1) return dp[n][amt];
        if(coins[n-1] <= amt){
            return dp[n][amt] = (solve(n , amt - coins[n-1] , coins) + solve(n-1 , amt , coins));
        }
        else{
            return dp[n][amt] = solve(n-1 , amt , coins);
        }
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.assign(n+1 , vector<int>(amount+1 , -1));
        return solve(n ,amount , coins);
    }
};