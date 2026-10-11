class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res ;

        int left = 1;

        for(int x : nums){
            res.push_back(left);
            left = left * x ;
        }

        int right = 1 ;

        for(int i = n-1 ; i >= 0 ; i--){
            res[i] = res[i] * right ;
            right = right * nums[i];
        }
        return res ;
    }
};