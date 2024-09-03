class Solution {
public:
    bool checkTwoChessboards(string s, string t) {
        int x = (s[0]-'a')+(s[1]-'0');
        int y = (t[0]-'a')+(t[1]-'0');
        return (x+y)%2==0;
    }
};