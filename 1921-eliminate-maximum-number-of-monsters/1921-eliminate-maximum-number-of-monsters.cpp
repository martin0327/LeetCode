class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> time(n);
        for (int i=0; i<n; i++) {
            time[i] = dist[i] / speed[i] + ((dist[i] % speed[i]) > 0);
        }
        sort(time.begin(), time.end());
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (time[i] > i) ans++;
            else break;
        }
        return ans;
    }
        
};