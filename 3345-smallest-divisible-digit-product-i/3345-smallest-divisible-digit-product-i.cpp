class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n ; i < INT_MAX ; i++){
            int num = i ;
            int prod = 1 ;
            while(num){
                int digit = num % 10 ;
                if(digit == 0){
                    prod = 0 ;
                    break ;
                }
                num /= 10 ;
                prod *= digit ;
            }
            if(prod % t == 0) return i ;
        }
        return -1 ;
    }
};