class Solution {
    bool isPal(string &s){
        int i = 0 , j = s.size()-1 ;
        while(i <= j){
            if(s[i++] != s[j--]) return false ;
        }
        return true ;
    }

    void solve(int i , string &s , vector<vector<string>> &res , vector<string>&temp){
        if(i == s.size()){
            res.push_back(temp);
            return ;
        }

        for(int k = i ; k < s.size() ; k++){

            string str1 = s.substr(i , k-i + 1);

            if(isPal(str1)){
                temp.push_back(str1);
                solve(k+1 , s , res , temp);
                temp.pop_back();
            }
        }
    }


public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res ;
        vector<string> temp ;

        solve(0, s , res , temp);
        return res ;
        
    }
};