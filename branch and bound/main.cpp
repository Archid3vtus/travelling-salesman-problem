// #include "stdafx.h"
#include "Graph.h"
#include "math.h"
#include <iostream>
#include <vector>

using namespace std;

double distanciaEuclidiana(int x, int y, int a, int b) {

	return sqrt(pow(x - a, 2) + pow(y - b, 2));

}

Graph construirGrafo() {

	int n;
	double x, y;
	double aux; 

	cin >> n;

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

	Graph graph = construirGrafo();
	vector<int> resposta;
	double caminhoTotal;

	/*Dynamic Programming*/

	resposta = graph.branchBound();

	caminhoTotal = graph.adj[resposta[0]][resposta[resposta.size() - 1]];

	for (int i = 0; i < resposta.size() - 1; i++) {

		caminhoTotal += graph.adj[resposta[i]][resposta[i + 1]];
		cout << resposta[i] + 1 << " ";

	}//fim for

	cout << resposta[resposta.size() - 1] + 1 << endl;

	cout << caminhoTotal << endl;
}