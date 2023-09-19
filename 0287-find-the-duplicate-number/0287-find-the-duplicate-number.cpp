class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int x = a[0], y = a[0];
        do {
            x = a[x];
            y = a[a[y]];
        } while(x != y);
        x = a[0];
        while (x != y) {
            x = a[x];
            y = a[y];
        }
        return x;
    }
};