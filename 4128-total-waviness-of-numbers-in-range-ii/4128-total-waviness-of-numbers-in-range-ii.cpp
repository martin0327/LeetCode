class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        using ll = long long;
        // 计算 [0, num] 内所有数字的波动值总和
        auto solve = [&](ll num) -> ll {
            // 如果少于 3 的数字波动值 0
            if (num < 100) {
                return 0;
            }
            string s = to_string(num);
            int n = s.size();
            
            // 记忆化搜索使用两个独立的数组
            // memo_cnt[pos][x][y]：当前位为 pos 位，且前两位为 x, y 的合法填充方案数
            ll memo_cnt[16][10][10];
            // memo_sum[pos][x][y]：当前位为 pos 位，且左边两位为 x, y 的波动值
            ll memo_sum[16][10][10];
            memset(memo_cnt, -1, sizeof(memo_cnt));
            memset(memo_sum, -1, sizeof(memo_sum));
            
            auto dfs = [&](this auto &&dfs, int pos, int prev, int curr, bool isLimit, bool isLeading) -> pair<ll,ll> {
                // 结束位置
                if (pos == n) {
                    return {1, 0};
                }
                // 只有在不受上限限制且不包含前导零时才使用记忆化
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    if (memo_cnt[pos][prev][curr] != -1) {
                        return {memo_cnt[pos][prev][curr], memo_sum[pos][prev][curr]};
                    }
                }
                
                // 计算当前条件下的方案数和波动值
                ll cnt = 0, sum = 0;
                int up = isLimit ? s[pos] - '0' : 9;
                for (int digit = 0; digit <= up; ++digit) {
                    bool newLeading = isLeading && (digit == 0);
                    // 前一个数字更新为 curr
                    int newPrev = curr;
                    // 当前数字更新为 digit
                    int newCurr = newLeading ? -1 : digit;
                    auto [subCnt, subSum] = dfs(pos + 1, newPrev, newCurr, isLimit && (digit == up), newLeading);
                    // 不包含前导零时才计算波动值
                    if (!newLeading && prev >= 0 && curr >= 0) {
                        // 数位为峰或为谷时，更新当前的波动值
                        if ((prev < curr && curr > digit) || (prev > curr && curr < digit)) {
                            sum += subCnt;
                        }
                    }
                    
                    cnt += subCnt;
                    sum += subSum;
                }
                
                if (!isLimit && !isLeading && prev >= 0 && curr >= 0) {
                    // 更新记忆化数组
                    memo_cnt[pos][prev][curr] = cnt;
                    memo_sum[pos][prev][curr] = sum;
                }
                
                return {cnt, sum};
            };
            
            // 修正：传递 dfs 作为第一个参数
            auto [_, totalSum] = dfs(0, -1, -1, true, true);
            return totalSum;
        };
        
        return solve(num2) - solve(num1 - 1);
    }
};