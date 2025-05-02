def solved():
    n, m = map(int, input().split())
    if(n % m == 0):
        print("divisible")
    else:
        print("not divisible")

t = int(input())
test = 1;
while test <= t:
    print(f"Case {test}:", end=" ")
    solved()
    test += 1
