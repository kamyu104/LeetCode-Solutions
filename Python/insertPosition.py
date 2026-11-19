nums=list(map(int,input().split()))
target=int(input())
low = 0
high = len(nums) - 1
flag=1

while low <= high:

	mid = int((low + high) / 2)

	if nums[mid] == target:
		flag=0
		break

	elif nums[mid] < target:
		low = mid + 1

	else:
		high = mid - 1
    
if(flag==1):
	print(low)
else:
	print(mid)