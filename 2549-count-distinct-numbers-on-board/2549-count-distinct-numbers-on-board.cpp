class Solution {
public:
    int distinctIntegers(int n) {
        set<int> s;
        queue<int> q;
        q.push(n);
        s.insert(n);
        while (q.size()) {
            int x = q.front();
            q.pop();
            for (int i=1; i<=n; i++) {
                if (s.count(i)) continue;
                if (x % i == 1) {
                    q.push(i);
                    s.insert(i);
                }
            }
        }
        int ans = s.size();
        return ans;
    }
};