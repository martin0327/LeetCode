class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            if (a[i] == t) return i;
        }
        return -1;
    }
};