class Solution {
public:
    int minOperations(vector<int>& a, int k) {
        int cnt = 0;
        set<int> s;
        while (a.size()) {
            int x = a.back();
            a.pop_back();
            if (x <= k) s.insert(x);
            cnt++;
            if (s.size() == k) return cnt;
        }
        return 0;
    }
};