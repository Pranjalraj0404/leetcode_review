class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> st;
        for(auto it : s){
            st[it] ++;
        }
        for(auto it : t){
            st[it]--;
        }
        for(auto it : st){
            if(it.second != 0) return false;
        }
        return true;
    }
};