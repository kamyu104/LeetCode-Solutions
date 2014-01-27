// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
    public:
        bool isValid(string s) {
            const string left = "([{";
            const string right = ")]}";
            stack<char> stack;
            for(auto c : s) {
                if(left.find(c) != string::npos) {
                    stack.push(c);
                }
                else if (right.find(c) != string::npos){
                    if(!stack.empty() && stack.top() == left[right.find(c)]) {
                        stack.pop();
                    }
                    else
                        return false;
                }
            }

            return stack.empty();
        }
};
