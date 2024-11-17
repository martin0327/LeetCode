class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int k) {
        int n = a.size(), cnt = 0;
        for (int i=1; i<k; i++) {
            if (a[i] == a[i-1]+1) cnt++;
        }
        vector<int> ans;
        ans.push_back((cnt==k-1)?a[k-1]:-1);
        for (int i=k; i<n; i++) {
            if (a[i] == a[i-1]+1) cnt++;
            if (a[i-k+1] == a[i-k]+1) cnt--;
            ans.push_back((cnt==k-1)?a[i]:-1);
        }
        return ans;
    }
};
