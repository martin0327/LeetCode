class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        while (s != "1") {
            if (s.back() == '0') s.pop_back();
            else {
                int n = s.size(), idx = -1;
                for (int i=n-1; i>=0; i--) {
                    if (s[i] == '0') {
                        idx = i;
                        break;
                    }
                }
                if (idx == -1){
                    s = "1";
                    for (int i=0; i<n; i++) {
                        s += '0';
                    }
                }
                else {
                    s[idx] = '1';
                    for (int i=idx+1; i<n; i++) s[i] = '0';
                }
            }
            ans++;
        }
        return ans;        
    }
};