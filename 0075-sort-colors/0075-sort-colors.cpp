class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size();
        vector<int> cnt(3);
        for (auto x : a) cnt[x]++;
        for (int i=0,j=0; i<n; j++) {
            while (cnt[j]--) a[i++] = j;
        }        
    }
};