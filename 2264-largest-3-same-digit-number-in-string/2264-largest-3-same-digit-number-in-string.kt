class Solution {
    fun largestGoodInteger(s: String): String {
        return (0..9)
            .map { i -> i.toString().repeat(3) }
            .filter { t -> s.contains(t) }
            .ifEmpty { listOf("") }
            .max()
    }
}