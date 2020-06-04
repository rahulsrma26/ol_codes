def get(l, r, k):
    return upto(r, k) - upto(l, k)

l = int(input())
r = int(input())
k = int(input())

print(get(l, r, k))