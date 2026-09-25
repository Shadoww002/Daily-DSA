class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0 , j = 0 ;

        while(j < n){
            char ch = chars[j];
            int st = j ;

            while(j < n && chars[j] == ch){
                j++ ;
            }

            int len = j - st ;

            chars[i] = ch;
            i++ ;

            if(len > 1){
                string count = to_string(len);
                for(char c : count){
                    chars[i] = c ;
                    i++ ;
                }
            }
        }
        return i ;

    }
};