class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char , int> need;
        for(char ch : t) need[ch]++ ;

        int left = 0 ;
        int minLen = INT_MAX ;
        int start = 0 ;
        int count = 0 ;

        for(int right = 0 ; right < n ; right++){
            
            char ch = s[right];

            if(need[ch] > 0){
                count++; 
            }

            need[ch]-- ;
            
            while(count == t.size()){

                // minLen = min(minLen , right - left + 1);
                
                if(right-left+1 < minLen){
                    minLen = right-left+1 ;
                    start = left ;
                }

                need[s[left]]++;
                if(need[s[left]] > 0){
                    count-- ;
                }
                left++ ;
            }
        }

        if(minLen == INT_MAX) return "";
        return s.substr(start , minLen);
    }
};