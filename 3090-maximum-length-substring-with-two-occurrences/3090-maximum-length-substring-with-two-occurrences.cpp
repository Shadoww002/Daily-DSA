class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char , int> mp ;

        int i = 0 ;
        int maxx = 0 ;
        for(int j = 0 ; j < n ; j++){
            char ch = s[j];
            mp[ch]++ ;

            while(mp[ch] > 2){
                mp[s[i]]-- ;
                i++;
            }

            maxx = max(maxx , j-i+1);

        }
        return maxx ;
    }
};