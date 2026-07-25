class Solution {
    unordered_map<string , int> mp ;
    vector<vector<string>> ans ;
    string b ;
    int wz ;
private:
    void dfs(string word , vector<string> &seq){
        if(word == b){
            reverse(seq.begin() , seq.end());
            ans.push_back(seq);
            reverse(seq.begin() , seq.end());
            return ;
        }
        int step = mp[word];

        for (int i = 0; i < wz; i++) {
                char orginal = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch ;
                    if(mp.find(word) != mp.end() && mp[word]+1 == step){
                        seq.push_back(word);
                        dfs(word , seq);
                        seq.pop_back();
                    }
                }
                word[i] = orginal;
            }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        wz = beginWord.size();
        b = beginWord ;

        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q ;
        q.push(beginWord) ;
        st.erase(beginWord);
        mp[beginWord] = 0 ;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int step = mp[word];
            if(word == endWord) break ;
            for (int i = 0; i < wz; i++) {
                char orginal = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if(ch == orginal) continue ;
                    word[i] = ch ;
                    if(st.count(word)){
                        mp[word] = step + 1 ;
                        
                        st.erase(word);
                        q.push(word);
                    }
                }
                word[i] = orginal;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> seq ;
            seq.push_back(endWord);
            dfs(endWord , seq);

        }

        return ans;
    }
};