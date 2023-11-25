class Solution {
    fun getSumAbsoluteDifferences(a: IntArray): IntArray {
        val pre = a.scan(0) { s,x -> s+x }.toIntArray()
        val suf = a.reversed().scan(0) { s,x -> s+x }.reversed().toIntArray()
        return a.mapIndexed { i, x -> x*(2*i+1-a.size) - pre[i] + suf[i+1] }.toIntArray()
    }
}