class Solution {
public:
    bool isVol(char ch){
        return (ch =='i' || ch =='o' ||ch =='e' || ch =='a' || ch =='u'|| 
                ch =='I' || ch =='O' ||ch =='E' || ch =='A' || ch =='U') ;
    }
    string reverseVowels(string s) {
        
        int left = 0 ;
        int right = s.size() -1 ;

        while(left < right){

            if(isVol(s[left]) && isVol(s[right])){
                swap(s[left] , s[right]);
                left ++ ;
                right -- ;
            }
            else if(isVol(s[left]) == false) left++ ;
            else if(isVol(s[right]) == false) right-- ;

        }
        return s ;
    }
};