# Time:  O(4^n)
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
        val, i = 0, 0
        val_str = ""
        while i < len(num):
            val = val * 10 + ord(num[i]) - ord('0')
            val_str += num[i]
            if str(val) != val_str:
                break
            expr.append(val_str)
            self.addOperatorsDFS(num, target, i + 1, 0, val, expr, result)
            expr.pop()
            i += 1
        return result

    def addOperatorsDFS(self, num, target, pos, operand1, operand2, expr, result):
        if pos == len(num):
            if operand1 + operand2 == target:
                e = "".join(expr)
                result.append(e)
            return

        val, i = 0, pos
        val_str = ""
        while i < len(num):
            val = val * 10 + ord(num[i]) - ord('0')
            val_str += num[i]
            if str(val) != val_str:
                break

            # Case '+':
            expr.append("+" + val_str)
            self.addOperatorsDFS(num, target, i + 1, operand1 + operand2, val, expr, result)
            expr.pop()

            # Case '-':
            expr.append("-" + val_str)
            self.addOperatorsDFS(num, target, i + 1, operand1 + operand2, -val, expr, result)
            expr.pop()
    
            # Case '*':
            expr.append("*" + val_str)
            self.addOperatorsDFS(num, target, i + 1, operand1, operand2 * val, expr, result)
            expr.pop()
    
            i += 1
  
