using vi = vector<int>;
using vvi = vector<vi>;

vi diff(vi &x, vi &y) {
    return {x[0]-y[0], x[1]-y[1]};
}
int norm(vi x) {
    return x[0]*x[0]+x[1]*x[1];
}
int dot(vi &x, vi &y) {
    return x[0]*y[0]+x[1]*y[1];
}
bool normal(vvi &a) {
    for (int i=0; i<3; i++) {
        auto x = a[i];
        auto y = a[(i+1)%3];
        auto z = a[(i+2)%3];
        auto d1 = diff(x,y);
        auto d2 = diff(x,z);
        if (dot(d1,d2) == 0) return true;
    }
    return false;
}

bool f(vvi a) {
    for (int i=0; i<4; i++) {
        vvi b;
        for (int j=0; j<4; j++) {
            if (i == j) continue;
            b.push_back(a[j]);
        }
        if (!normal(b)) return false;
    }
    return true;
}

bool g(vvi a) {
    vi b;
    for (int i=0; i<4; i++) {
        for (int j=i+1; j<4; j++) {
            b.push_back(norm(diff(a[i],a[j])));
        }
    }
    sort(b.begin(),b.end());
    return b[0] == b[3] && b[0] > 0;
}

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vvi a = {p1,p2,p3,p4};
        return f(a) && g(a);
    }
};