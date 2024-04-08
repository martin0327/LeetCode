class Solution {
public:
    int countStudents(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int x = accumulate(a.begin(), a.end(), 0);
        int y = n - x;
        for (int i=0; i<n; i++) {
            if (b[i]) {
                if (!x--) return n-i;
            }
            else {
                if (!y--) return n-i;
            }
        }
        return 0;
    }
};