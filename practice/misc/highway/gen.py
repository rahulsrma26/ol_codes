import itertools

def check(item):
    count, speed = 1, item[0]
    for a in item[1:]:
        if a < speed:
            speed = a
            count +=1
    return count


def groups(items):
    count = 0
    for item in itertools.permutations(items):
        count += check(item)
    return count

for i in range(1, 7):
    print(i, groups(range(i)))
