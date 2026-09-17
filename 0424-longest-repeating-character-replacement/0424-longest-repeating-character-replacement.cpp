class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int left = 0 ;
        int ans = 0 ;
        int maxFreq = 0 ;

        vector<int> freq(26 , 0);

        for(int right = 0 ; right < n ; right++){
            freq[s[right] - 'A']++;

            maxFreq = max(maxFreq , freq[s[right] - 'A']);
            int len = right - left + 1;

            if(len - maxFreq > k){
                freq[s[left] - 'A']-- ;
                left++ ;
            }

            ans = max(ans , right-left+1);
        }
        return ans ;
    }
};