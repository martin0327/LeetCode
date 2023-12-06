class Solution {
    fun totalMoney(n: Int): Int {
        val q = n / 7
        val r = n % 7
        return 7*q*(q+7)/2 + r*(2*q+r+1)/2        
    }
}