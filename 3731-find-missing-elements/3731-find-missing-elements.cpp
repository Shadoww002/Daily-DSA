class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        int high = INT_MIN ;
        int low = INT_MAX ;
        unordered_map<int , int> mp ;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] < low) low = nums[i];
            if(nums[i] > high) high = nums[i];

            mp[nums[i]]++ ;
        }

        vector<int> ans ;

        for(int i = low+1; i < high ; i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }

        return ans ;
    }
};