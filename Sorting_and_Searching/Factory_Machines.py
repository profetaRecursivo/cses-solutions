import sys
# A factory has n machines which can be used to make products. Your goal is to make a total of t products.
# For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
# What is the shortest time needed to make t products?
input = sys.stdin.readline
def f(arr, k, mid):
    suma = sum(mid // x for x in arr)
    return suma>=k

n, k = map(int, input().split())
arr = list(map(int, input().split()))
l = 1
r  = max(arr) * k
ans = 0
while l<=r:
    mid = (l+r)//2
    if f(arr, k, mid):
       ans = mid
       r = mid-1
    else:
        l = mid+1
print(ans)