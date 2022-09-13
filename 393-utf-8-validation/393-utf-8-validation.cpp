// void print_binary(int x) {
//     string s;
//     for (int i=0; i<8; i++) {
//         if ((x>>i)&1) s += '1';
//         else s += '0';
//     }
//     reverse(s.begin(), s.end());
//     cout << s << endl;
//     return;
// }
class Solution {
public:
    bool validUtf8(vector<int>& a) {
        bool ret = true;
        int n = a.size();
        int i = 0;
        // for (auto x : a) {
        //     print_binary(x);
        // }
        while (i < n) {
            int x = a[i];
            int pos = -1;
            for (int j=7; j>=0; j--) {
                if (((x>>j)&1) == 0) {
                    pos = j;
                    break;
                }
            }
            
            
            if (pos==7) i++;
            else if (pos==6) {
                ret = false;
                break;
            }
            else {
                int m = 6 - pos;
                if (m>3) {
                    ret = false;
                    break;
                }
                for (int j=i+1; j<i+1+m; j++) {
                    if (j >= n) {
                        ret = false;
                        break;
                    }
                    int x = a[j];
                    ret &= ((x>>7)&1) & (!((x>>6)&1));
                }
                i += m + 1;
            }
        }
        return ret;
    }
};