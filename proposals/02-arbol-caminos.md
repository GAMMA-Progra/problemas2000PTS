# Problema
Se tiene un árbol con `n` nodos, donde cada arista tiene un peso positivo.

Encontrar cuantos caminos simples entre pares de nodos cumplen que la suma de pesos en el camino entre ellos es menor o igual a algún número `K`.

# Glosario
* **Grafo**: Es una colección de vértices (nodos) y aristas (líneas que unen nodos).
* **Grafo no Dirigido**: Es un grafo *sin flechas*; es decir, la dirección en la que se recorre no importa.
* **Grafo Conexo**: Es un grafo donde todos los vértices están conectados por algún camino.
* **Grafo sin Ciclos**: Es un grafo donde no existen caminos que empiecen y terminen en el mismo grafo.

* **Árbol**: Es un grafo no dirigido, conexo, sin ciclos.
* **DFS**: Depth First Search o busqueda en profundidad, es un algoritmo de búsqueda no informada utilizado para recorrer todos los nodos de un grafo o árbol de manera ordenada, pero no uniforme.
* **Centroid Decomposition of Tree**: Algoritmo que ordena el grafo segun un centroide de los nodos.

# Ejemplo
![image](https://github.com/user-attachments/assets/85bcc595-3d74-4010-9fde-99a6a54fe79b)

En este ejemplo se ven `9` nodos. Por ejemplo, el camino entre el nodo `A` y el nodo `H` tiene un peso total de `5 + 10 + 7 = 22`.

Si buscamos todos los caminos entre dos nodo, tales que el peso total es menor que 3, únicamente tenemos los siguientes:
* `A - C`
* `A - D`
* `B - F`

De modo que existirían 3 caminos que satisfacen esto.
# Documentación 
https://www.geeksforgeeks.org/centroid-decomposition-of-tree/
