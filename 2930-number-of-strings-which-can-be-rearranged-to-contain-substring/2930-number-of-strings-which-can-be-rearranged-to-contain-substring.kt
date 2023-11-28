typealias ll = Long
typealias ti3 = Triple<Int,Int,Int>
typealias vi = List<Long>
typealias vvi = List<vi>
const val mod = 1e9.toLong() + 7

    
class Solution {
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
        }.toList()

        tailrec fun matExpHelper(exp: Int, base: vvi, res: vvi): vvi {
            return when {
                exp == 0 -> res
                exp and 1 == 1 -> matExpHelper(exp shr 1, matMul(base, base), matMul(res, base))
                else -> matExpHelper(exp shr 1, matMul(base, base), res)
            }
        }

        return matExpHelper(e, a, ret)
    }


    fun stringCount(n: Int): Int {
        val mp = (0 until 2).flatMap { i ->
            (0 until 2).flatMap { j ->
                (0 until 3).map { k ->
                    Triple(i, j, k)
                }
            }
        }.withIndex().associate { (index, triple) ->
            triple to index
        }.toMap()
        
        val m = mp.size
        val a = MutableList(m) { MutableList(m) { 0L } }
        
        (0 until 2).forEach { i ->
            (0 until 2).forEach { j ->
                (0 until 3).forEach { k ->
                    val ni = minOf(1, i + 1)
                    val nj = minOf(1, j + 1)
                    val nk = minOf(2, k + 1)
                    val u = mp[Triple(i, j, k)]!!
                    val v1 = mp[Triple(ni, j, k)]!!
                    val v2 = mp[Triple(i, nj, k)]!!
                    val v3 = mp[Triple(i, j, nk)]!!
                    a[u][u]+= 23L
                    a[u][v1]+= 1L
                    a[u][v2]+= 1L
                    a[u][v3]+= 1L
                }
            }
        }
        
        return matExp(a, n)[0][m-1].toInt()
    }
}  