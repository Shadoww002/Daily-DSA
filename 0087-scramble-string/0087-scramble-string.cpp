class Solution {
    unordered_map<string , bool> mp ;
    bool solve(string s1 , string s2){
        if(s1 == s2) return true ;
        if(s1.size() != s2.size()) return false ;

        int n = s1.size();
        if(n <= 1) return false ;

        string key = s1 + '_' + s2 ;
        if(mp.find(key) != mp.end()) return mp[key];
        // bool flag = false ;

        for(int k = 1 ; k < n ; k++){
            
            string left1 = s1.substr(0 , k) ;
            string right1 = s1.substr(k);

            // if no swap 
            if(solve(left1 , s2.substr(0 , k)) && solve(right1 , s2.substr(k))){
                return mp[key] = true;
            }
            // swap 
            if(solve(left1 , s2.substr(n-k)) && solve(right1 ,s2.substr(0 , n-k))){
                 return mp[key] = true;
            }
        }

        return mp[key] = false;;
    }

public:
    bool isScramble(string s1, string s2) {
        // int n = s1.size();
        mp.clear();
        return solve( s1 , s2);
    }
};