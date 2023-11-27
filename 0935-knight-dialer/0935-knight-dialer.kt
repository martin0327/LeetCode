typealias ll = Long
typealias vi = List<ll>
typealias vvi = List<vi>

class Solution {
    private val mod = 1e9.toLong() + 7
    private val dr = listOf(1, 1, 2, 2)
    private val dc = listOf(2, -2, 1, -1)
    
    private fun matMul(a: vvi, b: vvi): vvi {
        val n = a.size
        return (0 until n).map { i ->
            (0 until n).map { j ->
                (0 until n).sumOf { k ->
                    a[i][k]*b[k][j]
                }.rem(mod)
            }
        }
    }

    private fun matExp(a: vvi, e: Int): vvi {
        val n = a.size
        val ret = (0 until n).map { i ->
            (0 until n).map { j ->
                if (i == j) 1L else 0L
            }
        }.toMutableList()

        tailrec fun matExpHelper(exp: Int, base: vvi, result: vvi): vvi {
            return when {
                exp == 0 -> result
                exp and 1 == 1 -> {
                    val temp = matMul(result, base)
                    matExpHelper(exp shr 1, matMul(base, base), temp)
                }
                else -> matExpHelper(exp shr 1, matMul(base, base), result)
            }
        }

        return matExpHelper(e, a, ret)
    }


    fun knightDialer(n: Int): Int {
        val R = 4
        val C = 3
        val m = R * C - 2
        val a = MutableList(m) { MutableList(m) { 0L } }
        (0 until R - 1).flatMap { r ->
            (0 until C).flatMap { c ->
                val u = r * C + c
                (0 until 4).mapNotNull { d ->
                    val nr = r + dr[d]
                    val nc = c + dc[d]
                    if (nr in 0 until R && nc in 0 until C && !(nr == 3 && nc != 1)) {
                        val v = if (nr * C + nc >= m) m - 1 else nr * C + nc
                        Pair(u, v)
                    } else null
                }
            }
        }.forEach { (u, v) ->
            a[u][v] = 1L
            a[v][u] = 1L
        }
        
        return matExp(a, n - 1)
            .flatten()
            .sum()
            .rem(mod)
            .toInt()
    }
}  