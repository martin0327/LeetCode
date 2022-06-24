class Solution {
public:
    bool isPossible(vector<int>& a) {
        long long s = 0;
        priority_queue<int> pq;
        for (auto x : a) {
            pq.push(x);
            s += x;
        }
        bool ok = true;
        while (pq.size()) {
            int x = pq.top();
            pq.pop();
            s -= x;
            if (x == 1 || s==1) break;
            if (x < s || s <= 0) {
                ok = false; 
                break;
            }
            
            int y = x % s;
            if (y > 0) {
                s += y;
                pq.push(y);
            }
            else {
                ok = false;
                break;
            }
        }
        return ok;
    }
};

