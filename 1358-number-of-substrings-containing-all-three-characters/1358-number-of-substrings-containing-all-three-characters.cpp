class Solution {
    int atMost(string &s , int k){

        int n = s.size();
        unordered_map<char , int> mp ;

        int i = 0 ;
        int cnt = 0 ;

        for(int j = 0 ; j < n ;j++){
            char ch = s[j];
            mp[ch]++ ;

            while(mp.size() > k){
                mp[s[i]]--;

                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                i++ ;
            }
            cnt += j-i+1 ;

        }
        return cnt ;
    }
public:
    int numberOfSubstrings(string s) {
        
        return atMost(s , 3) - atMost(s , 2);

    }
};