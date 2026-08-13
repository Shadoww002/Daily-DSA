class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int , int> mp ;
        mp[0] = 1 ;

        int cnt = 0 ;
        int ps = 0 ;

        for(int x : nums){
            ps += x ;

            int remove = ps - k ;
            cnt += mp[remove];
            mp[ps] ++ ;

        }

        return cnt ;


    }
};