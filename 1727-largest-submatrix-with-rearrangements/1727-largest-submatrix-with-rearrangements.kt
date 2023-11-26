class Solution {
    fun largestSubmatrix(a: Array<IntArray>): Int {
        val n = a.size
        val m = a[0].size
        var ans = 0
        val b = Array(n) { IntArray(m) }

        for (j in 0 until m) {
            var cnt = 0
            for (i in n - 1 downTo 0) {
                if (a[i][j]== 1) b[i][j] = ++cnt
                else {
                    b[i][j] = 0
                    cnt = 0
                }
            }
        }

        for (i in 0 until n) {
            val t = b[i].toMutableList()
            t.sortDescending()
            for (j in 0 until m) {
                ans = maxOf(ans, (j + 1) * t[j])
            }
        }
        return ans
    }
}
