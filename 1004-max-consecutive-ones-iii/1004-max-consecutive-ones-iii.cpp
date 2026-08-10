class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0 , j = 0 ;

        int maxx = 0 ;
        queue<int> q ;

        while(j < n){

            if(nums[j] == 0){
                q.push(j);
            }

            if(q.size() > k){
                i = q.front() + 1;
                q.pop();
            }
            maxx = max(maxx , j-i+1);
            j++ ;
            
        }
        return maxx ;
    }
};