class Solution {
    // you need treat n as an unsigned value
    fun hammingWeight(n:Int):Int {
        return n.countOneBits()
    }
}