// Time:  O(n)
// Space: O(h)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<int> result;
        for(auto list : nestedList) {
            depthSumInverseHelper(list, 0, &result);
        }

        int sum = 0;
        for (int i = result.size() - 1; i >= 0; --i) {
            sum += result[i] * (result.size() - i);
        }
        return sum;
    }

private:
    void depthSumInverseHelper(const NestedInteger &list, int depth, vector<int> *result) {
        if (result->size() < depth + 1) {
            result->emplace_back(0);
        }
        if (list.isInteger()) {
            (*result)[depth] += list.getInteger();
        } else {
            for(auto l : list.getList()) {
                depthSumInverseHelper(l, depth + 1, result);
            }
        }
    }
};
