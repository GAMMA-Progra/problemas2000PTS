#define IOSUTILS
#include "template.hpp"

#include <iostream>
#include <vector>


bool is_local_max(i32 a, i32 b, i32 c) {
    return b > a && b > c;
}

bool is_local_min(i32 a, i32 b, i32 c) {
    return b < a && b < c;
}


int main() {
    fastio();

    // Número de días
    const auto days = read_next<usize>();

    // Dinero Inicial (bourles)
    i32 bourles = read_next<i32>();
    i32 martian_dollars = 0;

    // Inicializar lista
    std::vector<i32> values{};
    values.reserve(days);

    // Leer todos los números
    repeat(days) {
        i32 current = read_next<i32>();

        // Quitar repetición
        if (!values.empty()) {
            if (values.back() != current)
                values.push_back(current);
        }
        else
            values.push_back(current);
    }

    // Longitud de valores
    const auto length = values.size();

    // Lista de mínimos y máximos
    std::vector<i32> min_max{};

    // Primer elemento
    if (values[0] < values[1]) {
        min_max.push_back(values[0]);
    }

    // Insertar todos los demás elementos
    for (usize idx = 1; idx < length - 1; ++idx) {
        i32 left = values[idx - 1];
        i32 center = values[idx];
        i32 right = values[idx + 1];

        if (is_local_min(left, center, right))
            min_max.push_back(center);

        if (is_local_max(left, center, right))
            min_max.push_back(center);
    }

    // Último elemento
    if (values[length - 2] < values[length - 1]) {
        min_max.push_back(values[length - 1]);
    }

    // Compraventa
    for_enumerate(i32 value, idx, min_max) {
        // Comprar
        if (idx % 2 == 0) {
            martian_dollars += bourles / value;
            bourles = bourles % value;
        }

        // Vender
        else {
            bourles += martian_dollars * value;
            martian_dollars = 0;
        }
    }

    std::cout << bourles << '\n';
}
