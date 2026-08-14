class Solution {
    static bool cmp(const pair<int , int > &a ,const pair<int , int > &b){
        if(a.first == b.first ){
            return a.second > b.second ;
        }
        return a.first < b.first ;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int , int>> temp;

        unordered_map<int , int> mp ;
        for(int x : nums) mp[x]++ ;
            
        for(auto &[x , f] : mp){
            temp.push_back({f , x});
        }
        sort(temp.begin() , temp.end() ,cmp);
        vector<int> ans;
        for(auto it : temp){
            int cnt = it.first ;
            while(cnt--){
                ans.push_back(it.second);
            }
        }

        return ans;

    }
};