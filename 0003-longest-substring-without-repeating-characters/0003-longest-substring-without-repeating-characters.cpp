class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char , int> mp ;
        int ans = 0 ; 

        int i = 0 ;
        for(int j = 0 ; j < n ; j++){
            mp[s[j]]++ ;

            while(mp[s[j]] > 1){
                mp[s[i]] -- ;

                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++ ;
            }
            ans = max(ans , j-i+1);
        }

        return ans ;
    }
};