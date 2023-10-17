class Solution {
public:
    vector<int> findIndices(vector<int>& a, int id, int vd) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                if (abs(i-j) >= id) {
                    if (abs(a[i]-a[j]) >= vd) {
                        return {i,j};
                    }
                }
            }
        }
        return {-1,-1};
    }
};