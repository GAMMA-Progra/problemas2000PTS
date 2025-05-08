def sum_digits(num: int) -> int:
    acc = 0

    while num != 0:
        mod = num % 10
        num = num // 10

        acc += mod

    return acc

def main():
    res = sum_digits(123456789)
    print(f"{res=}")

main()
