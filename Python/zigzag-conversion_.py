class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        ans = [""]*numRows
        down = True
        row = 0
        for i in s:
            if down:
                if numRows == row:
                    down = False
                    row -= 1
                else:
                    ans[row] += i
                    row += 1
            if down==False:
                row -=1
                ans[row]+=i
                if row==0:
                    down = True
                    row += 1
        return "".join(ans)
