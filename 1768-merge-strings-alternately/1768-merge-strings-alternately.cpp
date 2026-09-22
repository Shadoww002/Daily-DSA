class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        string s = "";

        int i = 0 ;
        int j = 0 ;
        int k = 0 ;
        
        while(j < n && k < m){

            if(i % 2 == 0){
                s += word1[j];
                j++ ;
            }
            else{
                s += word2[k];
                k++ ;
            }

            i++ ;
        }

        while(j < n){
            s += word1[j];
            j++ ;
            i++ ;
        }

        while(k < m){
            s += word2[k];
            k++ ;
            i++;
        }

        return s ;
    }
};