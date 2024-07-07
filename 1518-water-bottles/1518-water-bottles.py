class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        x, y, z = numBottles, 0, numExchange
        ans = 0
        while x:
            ans += x
            y += x
            x = y // z
            y %= z
        return ans
        
            