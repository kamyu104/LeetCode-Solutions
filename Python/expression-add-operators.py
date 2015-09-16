# Time:  O(3^n)
# Space: O(n)
#
# Given a string that contains only digits 0-9 
# and a target value, return all possibilities 
# to add operators +, -, or * between the digits
# so they evaluate to the target value.
#
# Examples: 
# "123", 6 -> ["1+2+3", "1*2*3"] 
# "232", 8 -> ["2*3+2", "2+3*2"]
# "00", 0 -> ["0+0", "0-0", "0*0"]
# "3456237490", 9191 -> []
#

class Solution(object):
    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        result, expr = [], []
        self.addOperatorsDFS(num, target, 0, 0, 0, expr, result)
        return result

    def addOperatorsDFS(self, s, target, pos, operand1, operand2, expr, result):
        # Base Case 1
        if pos == len(s):
            if operand1 + operand2 == target:
                e = "".join(expr)
                e = e[1:] if e[0] == '+' else e
                result.append(e)
                return True
            return False

        num, i = 0, pos
        num_str = ""
        while i < len(s):
            num_str += s[i]
            num = num * 10 + ord(s[i]) - ord('0')

            # Case '+':
            expr.append("+"), expr.append(num_str)
            self.addOperatorsDFS(s, target, i + 1, operand1 + operand2, num, expr, result)
            expr.pop(), expr.pop()
            

            # '-' and '*' could be used only if the expression is not empty.
            if expr:
                # Case '-':
                expr.append("-"), expr.append(num_str)
                self.addOperatorsDFS(s, target, i + 1, operand1 + operand2, -num, expr, result)
                expr.pop(), expr.pop()
        
                # Case '*':
                expr.append("*"), expr.append(num_str)
                self.addOperatorsDFS(s, target, i + 1, operand1, operand2 * num, expr, result)
                expr.pop(), expr.pop()

            # Char is '0'.
            if num == 0:
                break
    
            i += 1
  
