class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int n = wordList.size();

        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[wordList[i]] = i;
        }

        vector<int> vis(n, 0);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        if (mp.find(beginWord) != mp.end()) {
            vis[mp[beginWord]] = 1;
        }

        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if (word == endWord)
                return step;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == original)
                        continue;
                    word[i] = ch;
                    if (mp.find(word) != mp.end() && vis[mp[word]] == 0) {
                        vis[mp[word]] = 1;
                        q.push({word, step + 1});
                    }
                }
                word[i] = original;
            }
        }

        return 0;
    }
};