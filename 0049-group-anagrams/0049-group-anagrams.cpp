class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string , vector<string>> mp ;

        for(string s : strs){
            string t = s ;
            sort(t.begin() , t.end());

            mp[t].push_back(s);     
        }

        vector<vector<string>> res;
        
        for(auto& [key , value] : mp){
            vector<string> temp ;

            for(string s : value){
                temp.push_back(s);
            }
            res.push_back(temp);
        }

        return res ;
    }
};