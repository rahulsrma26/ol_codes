from math import comb
# 10101

# 1000000
# 2100000
# 1011000

def upto(x, k):
    n, t, d, r = len(x), 0, 0, k
    for i, v in enumerate(x):
        if v != '0':
            t += comb(n - i - 1, r) * (9**r) * int(v)
            print(f"{i}| {n - i - 1}C{r} -> {t=}")
            d += 1
            if d == k:
                t += 1
                # print(f"{i}| -> {t=}")
            r -= 1
            if r == 0:
                break

    # t = comb(len(n) - 1, k)
    # l = len(n)
    # i = l - 1
    # while i > 0:
    #     if n[i] == '1':
    #         t += comb(len(n) - i, k - 1)
    #         print(f"{i}| {len(n) - i}C{k-1} -> {t=}")
    #     i -= 1
    return t

def uptobf(x, k):
    t = 0
    for i in range(1, int(x) + 1):
        v = str(i)
        if len(v) - v.count('0') == k:
            t += 1
    return t

print(upto("100", 1))
print(upto("200", 1), uptobf("200", 1))


# args = [10, 1]
# print(upto(*args), uptobf(*args))

# def get(l, r, k):
#     return upto(r, k) - upto(l, k)

# print(get(input(), input(), int(input())))

# 1 - 1
# 1 - 10
# 2 - 11
# 1 - 100
# 2 - 101
# 2 - 110
# 3 - 111
# 1 - 1000
# 2 - 1001
# 2 - 1010