class Solution {
    fun largestGoodInteger(s: String): String {
        return (9 downTo 0)
            .map { it.toString().repeat(3) }
            .find { s.contains(it) } ?: ""
    }
}