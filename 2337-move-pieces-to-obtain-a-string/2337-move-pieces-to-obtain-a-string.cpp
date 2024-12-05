class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        vector<pair<int,int>> a,b;
        for (int i=0; i<n; i++) {
            char c = start[i];
            if (c=='L') a.push_back({0,i});
            if (c=='R') a.push_back({1,i});
        }
        for (int i=0; i<n; i++) {
            char c = target[i];
            if (c=='L') b.push_back({0,i});
            if (c=='R') b.push_back({1,i});
        }
        bool ret = true;
        int m1 = a.size();
        int m2 = b.size();
        if (m1!=m2) return false;
        for (int i=0; i<m1; i++) {
            if (a[i].first != b[i].first) return false;
        }
        for (int i=0; i<m1; i++) {
            if (a[i].first==0) {
                if (a[i].second < b[i].second) return false;
            }
            else {
                if (a[i].second > b[i].second) return false;
            }
        }
        return true;
    }
};