#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> fragmentarFecha(std::string waos){
    std::stringstream ss(waos);
    std::string numero;
    std::vector<int> dma;

    while(std::getline(ss, numero, '.')){
        dma.push_back(std::stoi(numero));
    }

    return dma;
}

bool esBisiesto(int year){
    if(year % 4 == 0 && year % 100 == 0 && year % 400 != 0){
        return false;
    } else {
        return true;
    }
}

int diasMeses(int mes, int year){
    switch (mes){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return esBisiesto(year) ? 29 : 28;
    default:
        return 30;
    }
}

std::string reconstruido(int day, int mes, int year){
    std::string dayS = "01";
    std::string mesS = "01";
    std::string yearS = std::to_string(year);

    if(day > 0 && day < 10){
        dayS = "0" + std::to_string(day);
    } else {
        dayS = std::to_string(day);
    }

    if(mes > 0 && mes < 10){
        mesS = "0" + std::to_string(mes);
    } else {
        mesS = std::to_string(mes);
    }

    std::string reconstruido = dayS + "." + mesS + "." + yearS;

    return reconstruido;
}

int main(){
    std::string fecha;
    int numDias;
    std::cin >> fecha >> numDias;

    std::vector<int> dma = fragmentarFecha(fecha);

    int day = dma[0];
    int mes = dma[1]; 
    int year = dma[2];

    if(numDias > 0){
        day += numDias;
        while (day > diasMeses(mes, year)) {
            day -= diasMeses(mes, year);
            mes++;
            if (mes > 12) {
                mes = 1;
                year++;
            }
        }
    } else if(numDias < 0){
        day += numDias;
        while (day < 1) {
            mes--;
            if (mes < 1) {
                mes = 12;
                year--;
            }
            day += diasMeses(mes, year);
        }
    }

    std::string newFecha = reconstruido(day, mes, year);

    std::cout << newFecha;

    return 0;
}