class Solution {
public:
    string convertToTitle(int x) {
        string s;
        
        while (x) {
            x--;
            s += 'A' + (x%26);
            x /= 26;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

