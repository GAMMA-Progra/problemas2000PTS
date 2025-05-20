def sum_digits(num: int) -> int:
    acc = 0

    while num != 0:
        mod = num % 10
        num = num // 10

        acc += mod

    return acc


def river(num: int, steps: int):
    nums = []

    for _ in range(steps):
        nums.append(num)
        num = num + sum_digits(num)

    return nums


def river_until(num: int, top: int):
    nums = []

    while True:
        nums.append(num)
        num += sum_digits(num)

        if num > top:
            break

    return nums


def gen_river(num: int):
    while True:
        yield num + sum_digits(num)
        num += sum_digits(num)


def binary_search(target: int, nums: list[int]) -> int | None:
    low = 0
    high = len(nums) - 1

    while low <= high:
        mid = low + (high - low) // 2

        if target == nums[mid]:
            return mid

        elif target > nums[mid]:
            low = mid + 1
        else:
            high = mid - 1

    return None


def main():
    river_1 = river_until(1, 2**16)
    river_3 = river_until(3, 2**16)
    river_9 = river_until(9, 2**16)

    # Verificar en cual río
    river_generator = gen_river(10584)
    current = 87
    found = False

    while not found:
        if index := binary_search(current, river_1):
            print(f"River: 1{index=} | {current=}")
            found = True

        elif index := binary_search(current, river_3):
            print(f"River 3: {index=} | {current=}")
            found = True

        elif index := binary_search(current, river_9):
            print(f"River 9: {index=} | {current=}")
            found = True

        current = next(river_generator)


if __name__ == "__main__":
    main()
