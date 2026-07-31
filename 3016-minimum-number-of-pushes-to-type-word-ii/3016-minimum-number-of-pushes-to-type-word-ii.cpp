class Solution {
public:
    int minimumPushes(string word) {

        vector<int> arr(26 , 0);
        for(int i = 0 ; i < word.size() ; i++){
            arr[word[i] - 'a']++;
        }

        sort(arr.begin() , arr.end() , greater<int>());

        int moves = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if(i < 8 && arr[i] != 0){
                moves += arr[i]*1;
            }
            else if(i >= 8 && i < 16 && arr[i] != 0){
                moves += arr[i]*2;
            }
            else if(i >= 16 && i < 24 && arr[i] != 0){
                moves += arr[i]*3;
            }
            else if(i >= 24 && arr[i] != 0){
                moves += arr[i]*4;
            }
        
        }
        return moves ;

    }
};