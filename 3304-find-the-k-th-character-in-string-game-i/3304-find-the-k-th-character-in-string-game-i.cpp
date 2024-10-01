class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            string t = s;
            int n = t.size();
            for (int i=0; i<n; i++) {
                int x = t[i] - 'a';
                x = (x+1)%26;
                t[i] = 'a' + x;
            }
            s += t;            
        }
        return s[k-1];
    }
};