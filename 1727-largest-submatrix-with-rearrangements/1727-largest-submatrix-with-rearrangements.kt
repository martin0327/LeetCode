class Solution {
    fun largestSubmatrix(a: Array<IntArray>): Int {
        val n = a.size
        val m = a[0].size
        
        val b = (0 until n).fold(Array(n) { IntArray(m) }) { t, i ->
            t.apply {
                (0 until m).forEach { j ->
                    t[i][j] = if (a[i][j] == 1) {
                        if (i == 0) 1 else t[i-1][j]+ 1
                    } else 0
                }
            }
        }
        
        return (0 until n).map {i -> 
            b[i].toMutableList()
                .sortedDescending()
                .mapIndexed {j,x -> (j+1)*x}
                .max()
        }.max()        
    }
}