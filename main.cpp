// #include "stdafx.h"
#include "Graph.h"
#include "math.h"
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

double distanciaEuclidiana(int x, int y, int a, int b) {
	return sqrt(pow(x - a, 2) + pow(y - b, 2));
}

Graph construirGrafo(int n) {

	double x, y;
	double aux; 

	Graph graph(n);

	for (int i = 0; i < n; i++) {

		cin >> x;
		cin >> y;

		graph.addCoor(i, x, y);

	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (i != j) {

				aux = distanciaEuclidiana(graph.coor[i][0], graph.coor[i][1], graph.coor[j][0], graph.coor[j][1]);

				graph.addEdge(i, j, aux);

			}

		}

	}

	return graph;


}


int main() {

	int n;
	cin >> n;

	while(n > 0){
		Graph graph = construirGrafo(n);
		clock_t inicio,fim;
		vector<int> resposta;
		double caminhoTotal;

		for (size_t i = 0; i < 4; i++)
		{
			inicio = clock();
			switch (i)
			{
				case 0:
					resposta = graph.bruteForce();
					cout << "Resolução Força Bruta" << endl;
					break;

				case 1:
					resposta = graph.branchBound();
					cout << "Resolução Branch and Bound" << endl;
					break;

				case 2:
					resposta = graph.dynamic();
					cout << "Resolução Algoritmo Dinâmico" << endl;
					break;

				case 3:
					cout << "Resolução Algoritmo Genético" << endl;
					break;
			}
			fim = clock();

			cout << "Tempo de Execução: ";
			cout << double(fim - inicio) / double(CLOCKS_PER_SEC) << endl;

			if(i == 3){
				algoritmoGenetico ag(&graph, 40, 100, 20, 0);
				ag.gerarMenorCusto();
			}else{
				caminhoTotal = graph.adj[resposta[0]][resposta[resposta.size() - 1]];

				cout << "Caminho: ";

				for (int i = 0; i < resposta.size() - 1; i++) {
					caminhoTotal += graph.adj[resposta[i]][resposta[i + 1]];
					cout << resposta[i] + 1 << " ";
				}

				cout << resposta[resposta.size() - 1] + 1 << endl;

				cout << "Custo: ";
				cout << caminhoTotal << endl;
				cout << endl;
			}

		}
		cout << "------------------------------" << endl;

		cin >> n;
	}

}
