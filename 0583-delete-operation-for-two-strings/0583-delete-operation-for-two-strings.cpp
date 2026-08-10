class Solution {
    vector<vector<int>> dp ;
    int lcs(int n , int m , string &s1 , string &s2){
        if(n==0 || m==0) return 0 ;
        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1] == s2[m-1]){
            return dp[n][m] = 1 + lcs(n-1 , m-1 , s1 , s2);
        }
        else{
            return dp[n][m] = max(lcs(n-1 , m, s1 , s2) , lcs(n , m-1 , s1 ,s2));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        dp.assign(n+1 , vector<int>(m + 1 , -1));

        int cnt_lcs = lcs(n , m , word1 , word2);

        return n+m-2*cnt_lcs ;

    }
};