k=int(raw_input())
a=1
b=0
aa=0
bb=1
for i in range(k-1):
	aaa = a+aa
	a = aa
	aa = aaa

	bbb = b+bb
	b = bb
	bb = bbb

print str(aa)+" "+str(bb)
