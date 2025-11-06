// Given a set of points, calculate the sum of all Manhattan distances between two point pairs.
import sys
d=sys.stdin.readlines()
n=int(d[0])
x=[0]*n
y=[0]*n
def f(a):
	a.sort()
	s=0
	for i in range(n):
		s+=a[i]*(2*i-n+1)
	return s
for i in range(1, n+1):
	x[i-1],y[i-1]=map(int,d[i].split())
print(f(x)+f(y))