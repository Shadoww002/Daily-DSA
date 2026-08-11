class Solution {
    vector<vector<int>> dp;
    int LCS(int n, int m, string& s1, string& s2) {
        if (n == 0 || m == 0)
            return 0;

        if (dp[n][m] != -1)
            return dp[n][m];

        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + LCS(n - 1, m - 1, s1, s2);
        } else {
            return dp[n][m] = max(LCS(n, m - 1, s1, s2), LCS(n - 1, m, s1, s2));
        }
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        LCS(n, m, str1, str2);

        string s = "";
        int i = n , j = m ;

        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s.push_back(str1[i-1]);
                i --;
                j --;
            }
            else{
                if(dp[i-1][j] > dp[i][j-1]){
                    s.push_back(str1[i-1]);
                    i-- ;
                }
                else{
                    s.push_back(str2[j-1]);
                    j-- ;
                }
            }
        }

        while(i > 0 ){
            s.push_back(str1[i - 1]);
            i-- ;
        }
        while(j > 0){
            s.push_back(str2[j - 1]);
            j-- ;
        }

        reverse(s.begin() , s.end());


        return s ;

    }
};