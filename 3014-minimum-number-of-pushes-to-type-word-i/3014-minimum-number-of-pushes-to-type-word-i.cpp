class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        if(n <= 8) return n ;

        n = n - 8;
        if(n <= 8) return n*2 + 8;

        n = n - 8;
        if(n <= 8) return n*3 + 16 + 8;

        n = n - 8;
        return n*4 + 24 + 16 + 8;


    }
};