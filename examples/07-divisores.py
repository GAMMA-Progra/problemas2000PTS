# Verificar si un número divide a otro
def divides(a: int, b: int) -> bool:
    if a % b == 0:
        return True
    else:
        return False


def main():
    a = 123
    b = 1000

    # Matemáticamente más fácil
    print(b - a % b)

    # Más fácil de entender
    count = 0

    while not divides(a, b):
        count += 1
        a += 1

    print(count)


if __name__ == "__main__":
    main()