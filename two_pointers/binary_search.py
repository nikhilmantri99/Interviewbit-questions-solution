def binary_search(A,left,right,val):
	if(left>right):
		return -1
	mid=int((left+right)/2)
	if(A[mid]==val):
		return mid
	if(val<A[mid]):
		return binary_search(A,left,mid-1,val)
	if(val>A[mid]):
		return binary_search(A,mid+1,right,val)

A=[1,2,3,4,5,6,7,8]
C=binary_search(A,0,len(A)-1,8)
print(C)