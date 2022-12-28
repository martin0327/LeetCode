class Solution {
public:
    int minStoneSum(vector<int>& a, int k) {
        priority_queue<int> pq;
        for (int x : a) pq.push(x);
        while (k--) {
            int x = (pq.top()+1)/2;
            pq.pop();
            if (x) pq.push(x);
        }
        int ans = 0;
        while (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};