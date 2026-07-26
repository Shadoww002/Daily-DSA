class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long p1 = 1LL * nums[n - 1] * nums[n - 2] * nums[n - 3];
        long long p2 = 1LL * nums[n - 1] * nums[0] * nums[1];
        return max(p1 , p2);
    }
};