n = int(raw_input())
a1 = raw_input().split(' ')
A=1
for i in range(n):
	A = A * int(a1[i])
m = int(raw_input())	
a2 = raw_input().split(' ')
B=1
for i in range(m):
	B = B*int(a2[i])
C = A%B
A=B
B=C
while C != 0:
	C=A%B
	A=B
	B=C
if A >= 1000000000:
	print('%09d' % (A%1000000000))
else:
	print(A)