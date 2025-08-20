nums=list(map(int,input().split()))
f=1
if(len(nums)>2):
	total=sum(nums)

	leftSum=0
	for i in range(len(nums)):
		if leftSum*2==total-nums[i]:
			print(i)
			f=0
			break;
		leftSum+=nums[i]

	if(f==1):
		print("-1")

else:
	print("-1")
