// Time:  O(n)
// Space: O(n)

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        var lookup = [Int : Int]()
        for (i, num) in nums.enumerated() {
            if let j = lookup[target - num] {
                return [j, i]
            }
            lookup[num] = i
        }
        return []
    }
}
