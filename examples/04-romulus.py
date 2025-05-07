# 6 <- Cuantos elementos tiene la siguiente línea
# 50 10 2 5 1 20 <- Posibles valores
# 3 <- Cuantos elementos tiene la siguiente línea
# 10 49 101 <- Resultados

# Representa la lista de tuplas de (valor, veces)
type Mins = list[tuple[int, int]]


def main():
    values, totals = read_input("inputs/04-input.txt")
    results: list[Mins] = []

    # Calcula los mínimos para cada total
    for total in totals:
        values = sorted(values, reverse=True)
        results.append(calculate_mins(total, values))

    print_results(results)


# Asumir que `values` está ordenada descendente
def calculate_mins(num: int, values: list[int]) -> Mins:
    modulus = num
    acc = []

    for value in values:
        if modulus < value:
            continue
        else:
            # Alternativa:
            # acc.append(divmod(quotient, modulus))

            quotient = modulus // value
            modulus = modulus % value

            acc.append((value, quotient))

    if modulus != 0:
        return []
    else:
        return acc


# Retorna una tupla de (values, totals)
def read_input(path: str) -> tuple[list[int], list[int]]:
    values: list[int]
    results: list[int]

    with open(path, 'r') as f:
        text = f.read()
        lines = text.splitlines()

        values_text = lines[1]
        results_text = lines[3]

        # Convierte cada palabra de la lista en enteros
        values = list(map(int, values_text.split(' ')))
        results = list(map(int, results_text.split(' ')))

    return (values, results)


# Imprime los resultados en el formato solicitado
def print_results(minimums: list[Mins]):
    for mins in minimums:
        # Si encuentra una lista vacía, no tiene soluciones
        if len(mins) == 0:
            print("Imposible")
            continue

        # Sumar todos los acumulados
        total = sum(map(lambda tup: tup[1], mins))

        # Aquí imprimimos realmente
        print(total, end=" ")

        for value, times in mins:
            print(f"{times}x{value}", end=" ")

        print()


# Investigar esto ;)
if __name__ == "__main__":
    main()
