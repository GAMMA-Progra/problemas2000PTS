#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::unordered_map<char, int> esValido() {
    std::unordered_map<char, int> valores;
    for (int i = 0; i <= 9; i++) {
        valores['0' + i] = i;
    }
    for (int i = 0; i < 26; i++) {
        valores['A' + i] = 10 + i;
    }
    return valores;
}

std::vector<char> fragmentar(const std::string &numero) {
    std::vector<char> v;
    for (char c : numero) v.push_back(c);
    return v;
}

int toDecimal(const std::string &numero, int base, const std::unordered_map<char, int> &mapa) {
    std::vector<char> digitos = fragmentar(numero);
    int resultado = 0;
    for (char c : digitos) {
        resultado = resultado * base + mapa.at(c);
    }
    return resultado;
}

std::vector<char> generarSimbolos() {
    std::vector<char> symbols;
    for (int i = 0; i <= 9; i++) symbols.push_back('0' + i);
    for (int i = 0; i < 26; i++) symbols.push_back('A' + i);
    return symbols;
}

std::string fromDecimal(int numero, int base, const std::vector<char> &symbols) {
    if (numero == 0) return "0";
    std::string res;
    while (numero > 0) {
        int resto = numero % base;
        res.push_back(symbols[resto]);
        numero /= base;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n, base;
    std::cin >> n >> base;

    std::unordered_map<char, int> mapa = esValido();
    std::vector<char> symbols = generarSimbolos();

    int suma = 0;
    for (int i = 0; i < n; i++) {
        std::string num;
        std::cin >> num;
        suma += toDecimal(num, base, mapa);
    }

    std::string resultado = fromDecimal(suma, base, symbols);
    std::cout << resultado << "\n";

    return 0;
}
