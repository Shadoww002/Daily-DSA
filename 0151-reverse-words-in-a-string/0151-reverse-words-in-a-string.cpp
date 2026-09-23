class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        vector<string> words;
        int i = 0 ;
        while(i < n){

            while (i < n && s[i] == ' ') {
                i++;
            };

            string temp = "";
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            if(temp.size() != 0 ) words.push_back(temp);
            i++ ;
        }

        reverse(words.begin() , words.end());

        string res = "";
        for(int j = 0 ; j < words.size() ; j++){
            res += words[j];
            if(j != words.size()-1) res += ' ';
        }

        return res ;
    }
};