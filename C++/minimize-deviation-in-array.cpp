// Time:  O((n * log(max_num)) * logn)
// Space: O(n)

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        vector<int> evens;
        for (const auto& num : nums) {
            evens.emplace_back(num % 2 ? 2 * num : num);
        }
        int min_elem = *min_element(cbegin(evens), cend(evens));
        priority_queue<int> max_heap(less<int>(), move(evens));
        int result = numeric_limits<int>::max();
        while (size(max_heap) == size(nums)) {
            const auto num = max_heap.top(); max_heap.pop();
            result = min(result, num - min_elem);
            if (num % 2 == 0) {
                min_elem = min(min_elem, num / 2);
                max_heap.emplace(num / 2);
            }
        }
        return result;
    }
};
