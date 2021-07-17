# Time:  O(n)
# Space: O(1)

class Solution:
    def intToRoman(self, num: int) -> str:

    
        num_to_roman = {
            1 : "I",
            5 : "V",
            10: "X", 
            50: "L", 
            100: "C", 
            500: "D", 
            1000: "M", 
            4: "IV", 
            40: "XL", 
            400: "CD", 
            9: "IX", 
            90: "XC", 
            900: "CM"
        }
        
        if num_to_roman.get(num, 0):
            return num_to_roman[num]
        
        output = ''
        num = str(num)
        digits = len(num)
        for i, char in enumerate(num): 
            
            multiple = (10**(digits-i-1))
            n = int(char)*multiple
            
            
            # perform lookup 
            if num_to_roman.get(n, 0):
                output += num_to_roman[n]
                continue
            
            val = n//multiple
            if val < 5:
                output += num_to_roman[multiple]*val
            
            else: 
                output += num_to_roman[multiple*5]
                val = val - 5
                output += num_to_roman[multiple]*val
                
            
        return output

            
        
        
        
