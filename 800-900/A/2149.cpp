#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int numCasos, count = 0, countM = 0/*, resultado = 1*/;
    std::cin >> numCasos;

    std::vector<std::vector<int>> todos;

    for (int caso = 0; caso < numCasos; caso++) {
        int tam;
        std::cin >> tam;
        std::vector<int> datos(tam);

        for (int i = 0; i < tam; i++) {
            std::cin >> datos[i];
        }

        todos.push_back(datos);
    }
    
    for(int i = 0 ; i < numCasos ; i++){
        std::sort(todos[i].begin(), todos[i].end());
            for(int j = 0 ; j < todos[i].size() ; j++){
                int valor = todos[i][j];
                int siguiente = todos[i][j+1];

                if(valor == 0){
                    todos[i][j] = 1;
                    valor = 1;
                    count++;
                }
                if(valor == -1 && siguiente != -1){
                    todos[i][j] = 1;
                    valor = 1;
                    count = count + 2;
                }
                if(valor == -1 && siguiente == -1){
                    j++;
                }
            }

        // for(int j = 0 ; j < todos[i].size() ; j++){
        //     resultado *= todos[i][j];
        // }

        std::cout << count << "\n";
        count = 0;
    }

    return 0;
}
