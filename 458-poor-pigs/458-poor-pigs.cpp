class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int num_test = minutesToTest / minutesToDie;
        
        int ret = 0;
        while (pow(num_test+1,ret) < buckets) {
            ret++;
        }
        return ret;
    }
};