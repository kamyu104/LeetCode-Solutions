// Time:  O(n * l), l is the max length of numbers
// Space: O(l)

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int min_num = *min_element(A.begin(),A.end());
        int total = 0;
        while (min_num) {
            total += min_num % 10;
            min_num /= 10;
        }
        return total % 2 == 0;
    }
};
