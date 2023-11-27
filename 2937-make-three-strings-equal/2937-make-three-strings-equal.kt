const val inf = 1e9.toInt()
class Solution {
    fun findMinimumOperations(s1: String, s2: String, s3: String): Int {
        val n1 = s1.length
        val n2 = s2.length
        val n3 = s3.length
        val res = (1..listOf(n1,n2,n3).min()).map { l ->
            val t1 = s1.substring(0 until l)
            val t2 = s2.substring(0 until l)
            val t3 = s3.substring(0 until l)
            if (t1 == t2 && t2 == t3) n1+n2+n3-3*l else inf
        }.min()
        return if (res < inf) res else -1
    }
}