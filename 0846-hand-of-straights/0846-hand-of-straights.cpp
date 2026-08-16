class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false ;
        map<int , int> mp ;
        for(int x : hand) mp[x] ++ ;

        while(!mp.empty()){
            int st = mp.begin()->first;

            for(int i = st ; i < st + groupSize ; i++){
                if(mp[i] == 0) return false ;
                mp[i]--;
                if(mp[i] == 0) mp.erase(i);
            }
        }
        return true ;
    }
};