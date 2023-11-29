class Solution {
    fun areSimilar(a: Array<IntArray>, k: Int): Boolean {
        val m = a[0].size
        val d = k % m
//         a.mapIndexed { i, b -> 
//             when (i % 2) {
//                 0 -> b.sliceArray(m-d until m) + b.slice(0 until m-d)
//                 else -> b.sliceArray(d until m) + b.sliceArray(0 until d) 
//             }
//         }.toTypedArray().forEach { r ->
//             r.forEach {
//                 c -> print("$c ")
//             }
//             println()
//         }
    

        return a contentDeepEquals a.mapIndexed { i, b -> 
            when (i % 2) {
                0 -> b.sliceArray(m-d until m) + b.slice(0 until m-d)
                else -> b.sliceArray(d until m) + b.sliceArray(0 until d) 
            }
        }.toTypedArray()
    }
}