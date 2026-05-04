class Solution {
public:
    void wiggleSort(vector<int>& a) {
        int n = a.size(), j = 0;
        sort(a.rbegin(), a.rend());
        vector<int> b(n);
        for (int i=1; i<n; i+=2) {
            b[i] = a[j++];
        }
        for (int i=0; i<n; i+=2) {
            b[i] = a[j++];
        }
        swap(a,b);
    }
};