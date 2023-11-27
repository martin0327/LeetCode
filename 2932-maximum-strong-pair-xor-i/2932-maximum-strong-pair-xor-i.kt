class Solution {
    fun maximumStrongPairXor(a: IntArray): Int {
        return a.map {x ->
            a.map {y ->
                if (abs(x-y) <= min(x,y)) x xor y else 0
            }.max()
        }.max()
    }
}   