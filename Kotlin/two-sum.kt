// Time:  O(n)
// Space: O(n)

class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val lookup = HashMap<Int, Int>()
        nums.forEachIndexed { i, x ->
            val j = lookup[target - x]
            j?.let {
                return intArrayOf(j, i)
            }
            lookup[x] = i
        }
        return intArrayOf()
    }
}
