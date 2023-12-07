class Solution {
    fun largestOddNumber(s: String): String {
        return s.substring(0, s.indexOfLast { it.toString().toInt() and 1 == 1} + 1)
        // return (s.length-1 downTo 0).
        // find { (s[it].toString().toInt() and 1) == 1 }
        // ?.let { s.substring(0,it+1) } ?: ""
    }
}