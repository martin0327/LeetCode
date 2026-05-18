using vi = vector<int>;
class Solution {
public:
    int sortableIntegers(vector<int>& b) {
        int n = b.size();
        vi divs;
        for (int i=1; i*i<=n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                if (i*i != n) divs.push_back(n/i);
            }
        }
        int ans = 0;
        for (auto d : divs) {
            bool ok = true;
            int pmax = -1;
            for (int i=0; i<n; i+=d) {
                auto [it1,it2] = minmax_element(b.begin()+i, b.begin()+i+d);
                int mn = *it1, mx = *it2;
                if (mn < pmax) {
                    ok = false;
                    break;
                }
                if (mn != mx) {
                    int idx = -1;
                    if (b[i] == mn) {
                        idx = 0;
                        for (int j=d-1; j>=0; j--) {
                            if (b[i+j] == mn) {
                                idx = j;
                            }
                            else break;
                        }
                    }
                    else {
                        for (int j=0; j<d; j++) {
                            if (b[i+j] == mn) {
                                idx = j;
                                break;
                            }
                        }
                    }
                    assert(idx != -1);
                    for (int j=0; j+1<d; j++) {
                        int l = (idx+j) % d;
                        int r = (idx+j+1) % d;
                        if (b[i+l] > b[i+r]) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (!ok) break;
                pmax = mx;
            }
            if (ok) ans += d;
        }
        return ans;
    }
};