from sys import stdin
input = lambda: stdin.buffer.readline().decode().strip()


for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    mx = max(a)
    a = [mx - x for x in a if mx - x]
    a.sort()
    if not a:
        print(0)
    else:
        print(max(a[-1], (sum(a)+min(k, len(a))-1) // min(k, len(a))))