def solve():
    _length = int(input())
    line = input()
    arr = [int(word) for word in line.split(' ')]

    z_count = arr.count(0)
    neg_count = arr.count(-1)

    if neg_count % 2 == 0:
        return z_count
    
    return 2 + z_count

def main():
    cases = int(input())
    
    for _ in range(cases):
        print(solve())


if __name__ == "__main__":
    main()
