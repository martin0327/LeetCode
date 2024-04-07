class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size(), l=0,r=0;
        for (int i=0; i<n; i++) {
            char c = s[i];
            if (c == '(') l++;
            else if (c == ')') r++;
        }

        if (r < l) {
            int t = '(' ^ ')';
            for (auto &c : s) {
                if (c != '*') c ^= t;
            }
            reverse(s.begin(), s.end());
            swap(l,r);
        }
        vector<int> idx;
        for (int i=0; i<n; i++) {
            if (s[i] == '*') idx.push_back(i);
        }

        int d = r - l, sz = idx.size();
        if (d > sz) return false;
        int h = (sz - d) / 2;
        for (int i=0; i<d+h; i++) s[idx[i]] = '(';
        for (int i=sz-1; i>=sz-h; i--) s[idx[i]] = ')';
        
        int x = 0;
        for (auto c : s) {
            if (c == '(') x++;
            else if (c == ')') x--;
            if (x < 0) return false;
        }
        return true;
    }
};