class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> a;
        for (int i=0; i<n; i++) {
            a.push_back(i);
        }
        k--;
        for (int i=0;;) {
            int m = a.size();
            if (m==1) return a[0]+1;
            i = (i+k) % m;
            a.erase(a.begin() + i);
        }
        return -1;
    }
};