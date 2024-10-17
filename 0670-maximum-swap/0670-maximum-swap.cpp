class Solution {
public:
    int maximumSwap(int x) {
        string s = to_string(x);
        int n = s.size();
        int ans = x;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                string t = s;
                swap(t[i],t[j]);
                int y = stoi(t);
                ans = max(ans, y);
            }
        }
        return ans;
    }
};