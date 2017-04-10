// Time:  O(logn) = O(1)
// Space: O(logn) = O(1)

class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        nextPermutation(begin(digits), end(digits));  // self-implemented next_permutattion()
        auto result = stoll(digits);
        return (result > numeric_limits<int>::max() || result <= n) ? -1 : result;
    }

private:
    template<typename BidiIt>
    bool nextPermutation(BidiIt begin, BidiIt end) {
        const auto rbegin = reverse_iterator<BidiIt>(end);
        const auto rend = reverse_iterator<BidiIt>(begin);
        
        // Find the first element (pivot) which is less than its successor.
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot)) {
            ++pivot;
        }

        bool is_greater = true;
        if (pivot != rend) {
            // Find the number which is greater than pivot, and swap it with pivot
            auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        } else {
            is_greater = false;
        }
        
        // Make the sequence after pivot non-descending
        reverse(rbegin, pivot);
        
        return is_greater;
    }
};
