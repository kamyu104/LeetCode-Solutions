// Time:  O(n)
// Space: O(h)

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return deserializeHelper(s, &i);
    }

private:
    NestedInteger deserializeHelper(const string& s, int *i) {
        NestedInteger result;
        if (s[*i] != '[') {
            int num = 0;
            int sign = 1;
            if (*i < s.length() && s[*i] == '-') {
                sign = -1;
                ++(*i);
            }
            while (*i < s.length() && isdigit(s[*i])) {
                num *= 10;
                num += s[*i] - '0';
                ++(*i);
            }
            result.setInteger(sign * num);
        } else {
            ++(*i);
            while (*i < s.length() && s[*i] != ']') {
                result.add(deserializeHelper(s, i));
                if (*i < s.length() && s[*i] == ',') {
                    ++(*i);
                }
            }
            ++(*i);
        }
        return result;
    }
};
