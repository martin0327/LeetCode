class Solution {
    fun largestOddNumber(s: String): String {
        return (s.length-1 downTo 0).
        find { (s[it] - '0') and 1 == 1 }
        ?.let { s.substring(0,it+1) } ?: ""
    }
}