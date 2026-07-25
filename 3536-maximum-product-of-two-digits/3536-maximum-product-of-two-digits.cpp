class Solution {
public:
    int maxProduct(int n) {
        int num = n ;
        vector<int> arr(10 , 0);

        while(num > 0){
            int x = num % 10 ;
            arr[x]++ ;
            num = num / 10 ;
        }

        for(int i = 9 ; i>=0 ; i--){
            if (arr[i] == 0) continue ;
            else if(arr[i] >= 2) return i*i;

            int j = i - 1;
            while(j > 0){
                if(arr[j] >= 1){
                    return i*j;
                }
                j--;
            }
            
        }

        
        return 0 ;
        
    }
};