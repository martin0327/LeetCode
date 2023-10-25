class Solution {
public:
    int kthGrammar(int n, int k) {
        function<int(int,int)> f = [&] (int n, int k) {
            if (n==1) return 0;
            if (k&1) return f(n-1,k>>1)^1;
            else return f(n-1,k>>1);
        };
        return f(n,k-1);
    }
};