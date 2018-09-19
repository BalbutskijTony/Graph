#include "Graph.h"

#include <iostream>
using std::cout;
using std::endl;




int main() {
	Graph G;
	G.addEdge(1, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 4);
	G.addEdge(5, 6);

	G.addVertex(7);

	cout << G.depthSearch(1, 7) << endl;
	
	cout << G.widthSearch(5, 6) << endl;

	system("pause");
	return 0;
}