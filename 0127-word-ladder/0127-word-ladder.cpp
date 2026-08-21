class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int combo = q.front().second;
            q.pop();
            if(word == endWord) return combo;
            for(int i  = 0 ; i <  word.size() ; i++ ){
                 char original = word[i];
                for(char k =  'a' ; k <= 'z' ; k++){
                    word[i] = k;
                    if(st.find(word) != st.end()){
                        q.push({word,combo+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};