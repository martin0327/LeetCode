class Solution {
public:
    bool winnerOfGame(string s) {
        vector<int> a(2);
        int n = s.size();
        for (int i=1; i<n-1; i++) {
            if (s[i] == s[i-1] && s[i] == s[i+1]) {
                a[s[i]-'A']++;
            }
        }
        return a[0]>a[1];        
    }
};