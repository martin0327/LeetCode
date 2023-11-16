class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        int n = a.size();
        string ans;
        for (int i=0; i<n; i++) {
            ans += (a[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
}; 