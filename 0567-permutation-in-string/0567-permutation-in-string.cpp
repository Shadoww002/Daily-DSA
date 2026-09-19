class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();

        unordered_map<char , int> mp;
        for(char ch : s1) mp[ch]++ ;

        int left = 0 ;
        int minLen = INT_MAX ;
        int count = 0 ;

        for(int right = 0 ; right < n ; right++){
            char ch = s2[right];

            if(mp[ch] > 0){
                count ++ ;
            }
            mp[ch]-- ;

            while(count == s1.size()){
                minLen = min(minLen , right - left + 1);

                mp[s2[left]]++ ;
                if(mp[s2[left]] > 0){
                    count -- ;
                }
                left++ ;
            }   
        }
        if(minLen == s1.size()) return true ;
        return false ;
    }
};