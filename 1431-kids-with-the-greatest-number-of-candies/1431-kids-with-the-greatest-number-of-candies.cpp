class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        int n = candies.size();
        int maxx = -1 ;
        for(int x : candies) maxx = max(maxx , x);

        vector<bool> res ;
        for(int x : candies){
            if(x + extraCandies >= maxx) {
                res.push_back(true);
            }
            else res.push_back(false);
        }
        return res ;
    }
};