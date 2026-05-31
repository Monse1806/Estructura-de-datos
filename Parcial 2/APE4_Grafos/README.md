# APE 4 - Grafos: Mapa del Campus UTA

## Universidad Técnica de Ambato

**Facultad de Ingeniería en Sistemas, Electrónica e Industrial**
**Carrera de Software**
**Asignatura:** Estructura de Datos
**Nombre:** Monserrath Medina

---

## Descripción

Este proyecto implementa un **grafo no dirigido y ponderado** utilizando **listas de adyacencia** para representar rutas entre diferentes ubicaciones del Campus Huachi de la Universidad Técnica de Ambato.

Además, se comparan dos algoritmos de búsqueda de rutas:

* **BFS (Breadth First Search)**: encuentra la ruta con menor número de paradas.
* **Dijkstra**: encuentra la ruta con menor distancia total considerando los pesos de las aristas.

---

## Objetivo

Desarrollar habilidades en la implementación de grafos y algoritmos de búsqueda de rutas mediante un caso de estudio basado en ubicaciones reales dentro del campus universitario.

---

## Estructura del Grafo

### Nodos

| ID         | Nombre      |
| ---------- | ----------- |
| uta        | Universidad |
| fisei      | FISEI       |
| idiomas    | Idiomas     |
| biblioteca | Biblioteca  |
| estadio    | Estadio     |
| comedor    | Comedor     |

### Aristas

| Origen     | Destino    | Distancia |
| ---------- | ---------- | --------- |
| uta        | fisei      | 50        |
| fisei      | idiomas    | 40        |
| idiomas    | biblioteca | 30        |
| biblioteca | estadio    | 70        |
| uta        | comedor    | 20        |
| comedor    | estadio    | 200       |

---

## Métodos Implementados

### agregarNodo()

Permite registrar una nueva ubicación dentro del grafo y crear su lista de adyacencia.

### agregarArista()

Permite conectar dos ubicaciones mediante una arista ponderada, representando la distancia entre ellas.

### bfs()

Implementa el algoritmo Breadth First Search (BFS) para encontrar la ruta con menor cantidad de paradas entre dos nodos.

### dijkstra()

Implementa el algoritmo de Dijkstra para encontrar la ruta con menor distancia total considerando los pesos de las conexiones.

---

## Resultados Obtenidos

### BFS

Ruta con menor número de paradas:

```text
Universidad (uta) -> Comedor (comedor) -> Estadio (estadio)
```

### Dijkstra

Ruta con menor distancia total:

```text
Universidad (uta) -> FISEI (fisei) -> Idiomas (idiomas) -> Biblioteca (biblioteca) -> Estadio (estadio)
```

---

## Análisis

Los resultados demuestran que una ruta con menos paradas no necesariamente corresponde a la ruta más corta en términos de distancia.

* BFS prioriza la menor cantidad de saltos entre nodos.
* Dijkstra prioriza la menor distancia acumulada.

Por esta razón ambos algoritmos generan resultados diferentes para el mismo problema.

---

## Estructura del Proyecto

```text
APE4-Grafos/
│
├── APE4_Grafos.java
├── README.md
├── informe.pdf
│
└── capturas/
    ├── agregarNodo.png
    ├── agregarArista.png
    ├── bfs.png
    ├── dijkstra.png
    └── ejecucion.png
```

---

## Compilación

```bash
javac APE4_Grafos.java
```

## Ejecución

```bash
java APE4_Grafos
```

---

## Tecnologías Utilizadas

* Java JDK 21
* Visual Studio Code
* Estructuras de Datos
* Grafos
* BFS
* Dijkstra

---
