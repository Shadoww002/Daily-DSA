class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = INT_MIN;
        int second = INT_MIN;

        for(int num : nums){
            if(num >= first){
                second = first ;
                first = num ;
            }
            else if(num >= second){
                second = num ;
            }
        }

        return (first-1) * (second -1);
    }
};