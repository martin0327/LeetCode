using vi = vector<int>;
class Solution {
public:
    int distributeCookies(vector<int>& a, int k) {
        int n = a.size();
        int lo = 1;
        int hi = 1e9;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            vi idx;
            for (int i=0; i<n; i++) idx.push_back(i);
            bool ok = false;
            do {
                int cnt = 1;
                int cum = 0;
                int mm = 0;
                for (int i=0; i<n; i++) {
                    int x = a[idx[i]];
                    if (cum + x <= mid) cum += x;
                    else {
                        cnt++;
                        cum = x;
                    }
                    mm = max(mm, cum);
                }
                if (cnt <= k && mm <= mid) ok = true;
            } while(next_permutation(idx.begin(), idx.end()));
            if (ok) {
              ans = mid;
              hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};