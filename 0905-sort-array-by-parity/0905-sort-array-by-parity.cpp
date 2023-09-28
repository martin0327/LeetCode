class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        for (int i=0, j=0; j<a.size(); j++) {
            if (~a[j]&1) swap(a[i++],a[j]);
        }
        return a;
    }
};