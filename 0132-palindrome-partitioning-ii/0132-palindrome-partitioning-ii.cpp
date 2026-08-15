class Solution {
    vector<int> dp;
    bool isPal(int i, int j, string& s) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    int solve(int i, int n, string& s) {
        if (i == n)
            return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int ans = INT_MAX ;
        for(int j = i ; j < n ; j ++){
            if(isPal(i , j , s)){
                int cost = 1 + solve(j + 1 , n , s);
                ans = min(cost , ans);
            }
        }
        return dp[i] = ans ;
        
    }

public:
    int minCut(string s) {
        int n = s.size();
        dp.assign(n , -1);
        return solve(0, s.size() , s)-1;
    }
};