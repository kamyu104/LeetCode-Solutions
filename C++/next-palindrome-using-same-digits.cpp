// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string nextPalindrome(string num) {
        if (!nextPermutation(begin(num), begin(num) + size(num) / 2)) {
            return "";
        }
        copy(begin(num), begin(num) + size(num) / 2, rbegin(num));
        return num;
    }

private:
    template<typename BidiIt>
    bool nextPermutation(BidiIt begin, BidiIt end) {
        const auto rbegin = reverse_iterator<BidiIt>(end);
        const auto rend = reverse_iterator<BidiIt>(begin);
        auto pivot = next(rbegin);
        while (pivot != rend && *pivot >= *prev(pivot)) {
            ++pivot;
        }
        bool is_greater = true;
        if (pivot != rend) {
            auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
            swap(*change, *pivot);
        } else {
            is_greater = false;
        }        
        reverse(rbegin, pivot);
        return is_greater;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    string nextPalindrome(string num) {
        if (!next_permutation(begin(num), begin(num) + size(num) / 2)) {
            return "";
        }
        copy(begin(num), begin(num) + size(num) / 2, rbegin(num));
        return num;
    }
};
