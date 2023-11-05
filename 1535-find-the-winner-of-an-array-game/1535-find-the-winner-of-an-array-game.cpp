class Solution {
public:
    int getWinner(vector<int>& a, int k) {
        int n = a.size();
        k = min(k, n);
        int x = a[0];
        queue<int> q;
        for (int i=1; i<n; i++) q.push(a[i]);
        int cnt = 0;
        while (true) {
            int y = q.front();
            q.pop();
            if (x > y) {
                q.push(y);
                cnt++;
            }
            else {
                q.push(x);
                x = y;
                cnt = 1;
            }
            if (cnt==k) return x;
        }
        return -1;
    }
};