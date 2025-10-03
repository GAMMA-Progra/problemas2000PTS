#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){
    long long numCasos, diferencia;
    std::cin >> numCasos;

    std::vector<std::vector<long long>> casos;

    for(long long caso = 0 ; caso < numCasos ; caso++){
        long long pares;
        std::cin >> pares;
        std::vector<long long> datos(pares);

        for(long long i = 0 ; i < pares ; i++){
            std::cin >> datos[i];
        }
        casos.push_back(datos);
    }

    for(long long i = 0 ; i < numCasos ; i++){
        long long max = 0;
        std::sort(casos[i].begin(), casos[i].end());
        for(long long j = 0 ; j < casos[i].size() ; j += 2){
            diferencia = std::abs(casos[i][j] - casos[i][j+1]);
            
            max = std::max(max, diferencia);
        }
        std::cout << max << "\n";
    }
    return 0;
}
