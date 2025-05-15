class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto word = q.front();
                if (word == endWord) {
                    return ans;
                }
                q.pop();
                for (int j = 0; j < word.size(); j++) {
                    char ch = word[j];
                    for (int alphabet = 0; alphabet < 26; alphabet++) {
                        word[j] = alphabet + 'a';
                        if (st.find(word) != st.end()) {
                            st.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = ch;
                }
            }
        }
        return 0;
    }
};