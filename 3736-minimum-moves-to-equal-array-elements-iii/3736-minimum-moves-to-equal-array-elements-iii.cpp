class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0 ;
        for(int num : nums) maxi = max(maxi , num);

        int cnt = 0 ;

        for(int num : nums) cnt += abs(num - maxi);

        return cnt ;
    }
};