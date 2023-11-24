class Solution {
    fun maxCoins(a: IntArray): Int {
        return a.sortedArrayDescending()
        .filterIndexed { i,v -> (i % 2) == 1 }
        .take(a.size/3)
        .sum()
    }
}  