def basic_io(s, n):
    if s % n == 0:
        print("divisible")
    else:
        print("not divisible")

def main():
    t = int(input())
    for i in range(1, t + 1):
        print("Case " + str(i) + ":", end=" ")
        s, n = map(int, input().split())
        basic_io(s, n)
main()

