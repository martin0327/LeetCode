class Solution {
public:
    int minimumOperations(string s) {
        int n = s.size();
        set<string> ss = {"00"};
        for (int i=25; i<=75; i+=25) ss.insert(to_string(i));
        
        bool zero = false;
        for (int i=n-1; i>=0; i--) {
            if (s[i]=='0') zero = true;
            for (int j=n-1; j>i; j--) {
                string t;
                t += s[i];
                t += s[j];
                if (ss.count(t)) {
                    return (n-i-2);
                }
            }
        }
        if (zero) return n-1;
        return n;
        
    }
};