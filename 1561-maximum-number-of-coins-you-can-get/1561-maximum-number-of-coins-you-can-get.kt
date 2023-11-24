class Solution {
    fun maxCoins(a: IntArray): Int {
        return a.sortedArrayDescending()
        .take(2*a.size/3)
        .filterIndexed { idx, value -> (idx % 2) == 1 }
        .sum()
    }
} 