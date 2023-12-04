class Solution {
    fun largestGoodInteger(s: String): String {
        return (0..9)
            .map { it.toString().repeat(3) }
            .filter { s.contains(it) }
            .ifEmpty { listOf("") }
            .max()
    }
}