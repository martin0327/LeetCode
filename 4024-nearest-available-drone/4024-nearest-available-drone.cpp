template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
using pii = pair<int,int>;
using vp = vector<pii>;
class Solution {
public:
    int nearestDrone(vector<vector<int>>& a, vector<int>& tg) {
        int n = a.size();
        vp b;
        for (int i=0; i<n; i++) {
            int x = a[i][0], y = a[i][1];
            int tx = tg[0], ty = tg[1];
            int d = abs(tx-x) + abs(ty-y);
            if (d <= a[i][2]) {
                b.push_back({d,i});
            }
        }
        asort(b);
        if (b.empty()) return -1;
        auto ans = b.front().second;
        return ans;
    }
};