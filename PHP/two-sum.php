// Time:  O(n)
// Space: O(n)

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $lookup = array();
        foreach ($nums as $i => $x) {
            if (isset($lookup[$target -$x])) {
                return [$lookup[$target - $x], $i];
            }
            $lookup[$x] = $i;
        }
        return [];
    }
}
