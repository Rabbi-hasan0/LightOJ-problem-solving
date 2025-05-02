import math
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)
def lcm(a, b):
    val = a * b
    return val // gcd(a, b)

def solved():
    n = int(input())
    a = list(map(int, input().split()))
    ans = 1
    for i in a:
        ans = lcm(ans, i)

    ans = math.floor(ans)
    print(ans)

t = int(input())
test = 1;
while test <= t:
    print(f"Case {test}:", end=" ")
    solved()
    test += 1
