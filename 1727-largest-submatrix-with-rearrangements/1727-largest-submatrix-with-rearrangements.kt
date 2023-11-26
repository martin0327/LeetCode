class Solution {
    fun largestSubmatrix(a: Array<IntArray>): Int {
        val n = a.size
        val m = a[0].size
        var ans = 0
        val b = Array(n) { IntArray(m) }

        for (j in 0 until m) {
            var cnt = 0
            for (i in n-1 downTo 0) {
                if (a[i][j]== 1) b[i][j] = if (i==n-1) 1 else b[i+1][j]+1
                else b[i][j] = 0
            }
        }
        
        return (0 until n).map {i -> b[i].toMutableList()
                .sortedDescending()
                .mapIndexed {j,x -> (j+1)*x}
                .max()}.max()        
    }
}