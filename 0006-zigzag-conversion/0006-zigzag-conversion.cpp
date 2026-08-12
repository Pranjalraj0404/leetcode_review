class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> v(numRows);
        int row = 0, dir = 1;

        for (char c : s) {
            v[row] += c;

            if (row == 0)
                dir = 1;
            else if (row == numRows - 1)
                dir = -1;

            row += dir;
        }

        string ans;
        for (auto &x : v)
            ans += x;

        return ans;
    }
};