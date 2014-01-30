// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            nextPermutation(begin(num), end(num));
        }

    private:
        template<typename BidiIt>
            bool nextPermutation(BidiIt begin, BidiIt end) {
                const auto rbegin = reverse_iterator<BidiIt>(end);
                const auto rend = reverse_iterator<BidiIt>(begin);

                // find the firt element (pivot) which is less than its successor
                auto pivot = next(rbegin);
                while(pivot != rend && *pivot >= *prev(pivot)) {
                    ++pivot;
                }

                // no next permutation, just reverse the whole sequence
                if(pivot == rend) {
                    reverse(rbegin, rend);
                    return false;
                }

                // find the number which is greater than pivot, and swap it with pivot
                auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
                swap(*change, *pivot);

                // make the sequence after pivot non-descending
                reverse(rbegin, pivot);

                return true; // return next permutation
            }
};
