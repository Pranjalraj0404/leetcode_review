class Solution {
public:
bool check(string &s, int index, int cnt){
    if(cnt< 0) return false;
    if (index == s.size()) {
        return cnt == 0;
    }
    if(s[index] == '(') return check(s,index+1,cnt+1);
    else if (s[index] == ')') return check(s,index+1,cnt-1);
    else return check(s,index+1,cnt+1) || check(s,index+1,cnt-1) || check(s,index+1,cnt);
}
    bool checkValidString(string s) {
        //return check(s,0,0);
    int mini = 0, maxi = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            mini++;
            maxi++;
        }
        else if (s[i] == ')') {
            mini--;
            maxi--;
        }
        else {
            mini--;
            maxi++;
        }
        if (mini < 0) mini = 0;
        if (maxi < 0) return false;
    }
    return mini == 0;
}
};