class Solution {
    fun distributeCandies(n: Int, lim: Int): Long {
        return (0..minOf(n,lim)).sumOf { i ->
            val m = n - i
            val l = maxOf(0,m-lim).toLong()
            val r = minOf(m,lim).toLong()
            maxOf(0, r-l+1)
        }
    }
}