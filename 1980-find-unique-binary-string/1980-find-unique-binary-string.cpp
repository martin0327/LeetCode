class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        int n = a.size();
        set<string> s(a.begin(), a.end());
        for (int mask=0; mask<(1<<n); mask++) {
            string t;
            for (int i=0; i<n; i++) {
                if (mask>>i&1) t += '1';
                else t += '0';
            }
            if (!s.count(t)) return t;
        }
        return "";        
    }
};