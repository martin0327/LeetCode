class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        auto b = a;
        sort(b.begin(), b.end());
        for (int i=0; i<n; i++) {
            a.push_back(a.front());
            a.erase(a.begin());
            if (a==b) return true;
        }
        return false;
    }
};