#include <iostream>


int mod(int k, int n) {
    return ( (k %= n) < 0) ? k + n : k;
}

unsigned get_min_distance(unsigned pos, unsigned last) {
    if (pos < last / 2)
        return pos + 1;
    else
        return last - pos;
}

template <typename T>
T read_integer() {
    T num;
    std::cin >> num;
    return num;
}


int main() {
    std::cin.tie(nullptr);
    std::cout.sync_with_stdio(false);

    const auto SHIPS_NO = read_integer<unsigned>();
    const auto SECTORS_NO = read_integer<unsigned>();

    // Iterar por cada nave
    for (unsigned ship_no = 0; ship_no < SHIPS_NO; ++ship_no) {
        // Leemos la info de cada nave
        const auto MOVS_NO = read_integer<unsigned>();
        const auto INIT_POS = read_integer<unsigned>();

        // Leemos cada movimiento
        int current_position = static_cast<int>(INIT_POS);

        for (unsigned mov_no = 0; mov_no < MOVS_NO; ++mov_no)
            current_position += read_integer<int>();

        // Obtenemos la posición final (sin nada)
        int final_pos = mod(current_position, SECTORS_NO);

        // Standard Console Output
        std::cout
            << final_pos << ' '
            << get_min_distance(final_pos, SECTORS_NO - 1) << ' '
            << current_position << '\n';
    }
}
