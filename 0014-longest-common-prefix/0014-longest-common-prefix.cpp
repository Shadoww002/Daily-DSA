class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";

        int minLen = INT_MAX ;
        for(string s : strs){
            if(s.size() < minLen){
                minLen = s.size();
            }
        }

        for(int i = 0 ; i < minLen ; i++){

            char ch = strs[0][i];

            for(int j = 1 ; j < n ; j++){
                if(strs[j][i] != ch){
                    return ans ;
                }
            }   
            ans += ch ;
        }

        return ans ;

    }
};