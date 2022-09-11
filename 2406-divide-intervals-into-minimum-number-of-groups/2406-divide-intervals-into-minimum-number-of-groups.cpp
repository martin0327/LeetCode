class Solution {
public:
    int minGroups(vector<vector<int>>& lr) {
        using pii = pair<int,int>;  
        using vp = vector<pii>;

        int n = lr.size();
        
        // want to sort intervals in increasing order of right end
        vp rl(n);
        for (int i=0; i<n; i++) rl[i] = {lr[i][1],lr[i][0]};
        sort(rl.begin(), rl.end());
        
        // s stores each group's right most endpoint
        // at any point, current r is greater than or equal to any previously appeared r
		// hence if there is a group whose right most endpoint is strictly less than the current l, 
		// we may append current interval at the end of that group
        multiset<int> s;
        for (auto [r,l] : rl) {
            
            auto it = s.lower_bound(l);

            if (it == s.begin()) { 
                // there is no group whose right most endpoint is strictly less than the current l
                // so we create a new group
                s.insert(r);
            }
            else {
                it--;
                // there are groups whose right most endpoint is strictly less than the current l
                // we pick the one with the highest r among them and append our current interval.
                s.erase(it);
                s.insert(r);
            }

        }
		// the number of groups in the end is the answer.
        return s.size();
    }
};
