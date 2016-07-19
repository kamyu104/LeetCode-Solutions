// Time:  O(logn)
// Space: O(1)

// Iterative solution.
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        int dvd{n};
        
        while (dvd) {
            result.push_back((dvd - 1) % 26 + 'A');
            dvd = (dvd - 1) / 26;
        }
        reverse(result.begin(), result.end());

        return result;
    }
};

// Time:  O((logn)^2)
// Space: O(logn)
// Recursive solution.
class Solution2 {
public:
    string convertToTitle(int n) {
        if (n == 0) {
            return "";
        }
        return convertToTitle((n - 1) / 26) + static_cast<char>((n - 1) % 26 + 'A');
    }
};
