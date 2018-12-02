// Time:  O(1)
// Space: O(1)

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string result;
        sort(A.begin(), A.end(), greater<int>());
        do {
            if (A[0] * 10 + A[1] < 24 && A[2] < 6) {
                for (const auto& i : A) {
                    if (result.length() == 2) {
                        result += ":";
                    }
                    result += to_string(i);
                }
                break;
            }
        } while (next_permutation(A.begin(), A.end(), greater<int>()));
        return result;
    }
};
