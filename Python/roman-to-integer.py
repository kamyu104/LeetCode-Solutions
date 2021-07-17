# Time:  O(n)
# Space: O(1)

class Solution:
    def romanToInt(self, s: str) -> int:
        
        roman_to_num = {
            "I":1, 
            "V":5,
            "X":10,
            "L":50,
            "C":100,
            "D":500,
            "M":1000, 
            "IV":4, 
            "XL":40, 
            "CD":400,
            "IX":9,
            "XC":90,
            "CM":900
        }
        
        if roman_to_num.get(s, 0):
            return roman_to_num[s]
        
        out = 0
        i = 0
        while i < len(s):
            if i < len(s)-1:
                
                # Check if the next two are equal to something 
                if roman_to_num.get(s[i:i+2], 0):
                    out += roman_to_num[s[i:i+2]]
                    i += 2
                    continue
            
            out += roman_to_num[s[i]]
            i += 1
            
        return out



            
        
        
        
