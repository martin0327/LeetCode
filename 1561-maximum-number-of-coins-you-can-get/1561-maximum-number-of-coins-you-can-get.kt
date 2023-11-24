class Solution {
    fun maxCoins(a: IntArray): Int {
        return a.sortedArrayDescending()
        .filterIndexed { idx, value -> (idx % 2) == 1 }
        .take(a.size/3)
        .sum()
    }
} 