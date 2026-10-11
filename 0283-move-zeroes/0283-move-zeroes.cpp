class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int j = 0 ;

        for(int i = 0 ; i < n ; i++){
            
            while(j < n && nums[j] != 0) j++ ;

            if(j < n && j < i && nums[j] == 0 && nums[i] != 0){
                swap(nums[i] , nums[j]);
                j++ ;
            }
        }

    }
};