class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int count_zeros = 0 ; 
        int maxLen = INT_MIN ;
        int left = 0 ;
        int right = 0 ; 
        
        while(right < n){

            if(nums[right] == 0){
                count_zeros++ ;
            }

            while(count_zeros > k){
                
                if(nums[left] == 0) count_zeros -- ;
                left++ ;
            }

            maxLen = max(maxLen , right - left + 1);
            right++ ;
        }
        return maxLen ;
    }
};