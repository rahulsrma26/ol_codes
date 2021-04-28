import itertools


# def gen():
#     count = set()
#     for h in range(24):
#         for m in range(60):
#             for s in range(6):
#                 t = f"{h:02}{m:02}{s:01}"
#                 if t == t[::-1]:
#                     count.add(t)
#     print(sorted(count), len(count))
    
def gen():
    count = set()
    for h in range(24):
        for m in range(60):
            for s in range(6):
                t = f"{h:02}{m:02}{s:01}"
                if t == t[::-1]:
                    count.add(t)
    print(sorted(count), len(count))

if __name__ == "__main__":
    gen()
