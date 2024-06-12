class Solution {
public:
    void sortColors(vector<int>& a) {
        vector<int> cnt(3);
        for (int x : a) cnt[x]++;
        for (int i=0,j=0; i<(int)a.size(); j++) {
            while (cnt[j]--) a[i++] = j;
        }        
    }
};