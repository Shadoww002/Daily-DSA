class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        unordered_map<int , int> mp ;
        int left = 0 ;
        int right = 0 ;
        int maxFruits = INT_MIN;

        while(right < n){

            mp[fruits[right]]++ ;

            while(mp.size() > 2){

                mp[fruits[left]] -- ;

                if(mp[fruits[left]] == 0){
                    mp.erase(fruits[left]);
                }
                left ++ ;
            }
            
            maxFruits = max(maxFruits , right - left + 1);
            right++ ;
        }

        return maxFruits ;
    }
};