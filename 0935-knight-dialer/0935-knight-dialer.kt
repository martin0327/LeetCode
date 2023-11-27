typealias ll = Long
typealias vi = List<ll>
typealias vvi = List<vi>

class Solution {
    private val mod = 1e9.toLong() + 7
    private val dr = listOf(1, 1, 2, 2)
    private val dc = listOf(2, -2, 1, -1)

    private fun matMul(a: vvi, b: vvi): vvi {
        val n = a.size
        val ret = MutableList(n) { MutableList(n) { 0L } }
        for (i in 0 until n) {
            for (j in 0 until n) {
                for (k in 0 until n) {
                    ret[i][j]+= a[i][k]* b[k][j]
                    ret[i][j]%= mod.toLong()
                }
            }
        }
        return ret
    }

    private fun matExp(a: vvi, e: Int): vvi {
        val n = a.size
        val ret = MutableList(n) { MutableList(n) { 0L } }
        for (i in 0 until n) {
            ret[i][i]= 1L
        }
        var exp = e
        var base = a
        while (exp > 0) {
            if (exp and 1 == 1) {
                val temp = matMul(ret, base)
                ret.clear()
                ret.addAll(temp.map { it.toMutableList() })
            }
            exp = exp shr 1
            base = matMul(base, base)
        }
        return ret
    }

    fun knightDialer(n: Int): Int {
        val R = 4
        val C = 3
        val m = R * C - 2
        val a = MutableList(m) { MutableList(m) { 0L } }

        for (r in 0 until R - 1) {
            for (c in 0 until C) {
                val u = r * C + c
                for (d in 0 until 4) {
                    val nr = r + dr[d]
                    val nc = c + dc[d]
                    if (nr < 0 || nr >= R || nc < 0 || nc >= C || (nr == 3 && nc != 1)) {
                        continue
                    }
                    var v = nr * C + nc
                    if (v >= m) {
                        v = m - 1
                    }
                    a[u][v]= 1L
                    a[v][u]= 1L
                }
            }
        }
        
        return matExp(a, n - 1)
            .flatten()
            .sum()
            .rem(mod.toLong())
            .toInt()
    }
}
