class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int time = 0 ;
        int curr = 0 ;
        for(int x : requests){
            if(curr != x){
                time += abs(x - curr);
            }
            curr = x ;
        }
        return time ;
    }
};