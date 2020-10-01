class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        pointerStart = 0
        pointerEnd = len(numbers) - 1
        while(pointerStart<pointerEnd):
            if(numbers[pointerStart] + numbers[pointerEnd] == target):
                return [pointerStart+1, pointerEnd+1]
            elif(numbers[pointerStart] + numbers[pointerEnd] > target):
                pointerEnd -=1
            else:
                pointerStart +=1
