class Solution {
    fun arrayStringsAreEqual(a: Array<String>, b: Array<String>): Boolean {
        return a.reduce { acc, s -> acc + s } == b.reduce { acc, s -> acc + s }
    }
}