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

// Iterative solution. 
class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) {
            return NestedInteger();
        }

        if (s[0] != '[') {
            return NestedInteger(stoi(s));
        }

        stack<NestedInteger> stk;
        for (int i = 0, j = 0; j < s.length(); ++j) {
            if (s[j] == '[') {
                stk.emplace(NestedInteger()); 
                i = j + 1;
            } else if (s[j] == ',' ||s[j] == ']'){
                if (isdigit(s[j - 1])) {
                    stk.top().add(NestedInteger(stoi(s.substr(i,j - i))));
                }
                if (s[j] == ']' && stk.size() > 1) {
                    NestedInteger cur = stk.top();
                    stk.pop();
                    stk.top().add(cur);
                }
                i = j + 1;
            }
        }
        return stk.top();
    }
};

// Time:  O(n)
// Space: O(h)
// Recursive solution. 
class Solution2 {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) {
            return NestedInteger();
        }
        int i = 0;
        return deserializeHelper(s, &i);
    }

private:
    NestedInteger deserializeHelper(const string& s, int *i) {
        NestedInteger result;
        if (s[*i] != '[') {
            int j = *i;
            while (j < s.length() && (s[j] == '-' || isdigit(s[j]))) {
                ++j;
            }
            result.setInteger(stoi(s.substr(*i, j - *i + 1)));
            *i = j;
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

// Time:  O(n)
// Space: O(n)
// Recursive solution. 
class Solution3 {
public:
    NestedInteger deserialize(string s) {
        if (s.empty()) {
            return NestedInteger();
        }
        istringstream in(s);  // copy string: extra O(n) space
        return deserializeHelper(in);
    }

private:
    NestedInteger deserializeHelper(istringstream &in) {
        NestedInteger result;
        int num = 0;
        if (in >> num) {
            result.setInteger(num);
        } else {
            in.clear();
            in.get();
            while (in.peek() != ']') {
                result.add(deserializeHelper(in));
                if (in.peek() == ',') {
                    in.get();
                }
            }
            in.get();
        }
        return result;
    }
};
