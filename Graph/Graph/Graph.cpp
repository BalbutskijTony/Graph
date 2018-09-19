#include "Graph.h"



void Graph::addVertex(int vertex) {
	if (!has_vertex(vertex)) {
		vertices[vertex] = vector<int>();
	}
}

void Graph::addEdge(int startVertex, int endVertex) {
	if (startVertex != endVertex) {
		vertices[startVertex].push_back(endVertex);
		vertices[endVertex].push_back(startVertex);
	}
	else {
		addVertex(startVertex);
	}
}

bool Graph::has_vertex(int vertex) const {
	return (vertices.find(vertex) != vertices.end());
}

bool Graph::widthSearch(int startVertex, int goalVertex) const {
	map<int, int> verticesColor;
	int currentVertex;
	for (auto v : vertices)
		verticesColor[v.first] = WHITE;

	queue<int> Q;
	if (verticesColor.empty()) return false;

	Q.push(startVertex);
	while (!Q.empty()) {
		currentVertex = Q.front();
		Q.pop();
		if (currentVertex == goalVertex) return true;
		verticesColor[currentVertex] = BLACK;

		for (auto v : vertices.at(currentVertex))
			if (verticesColor[v] == WHITE)
			{
				Q.push(v);
				verticesColor[v] = GREY;
			}
	}

	return false;
}

bool Graph::depthSearch(int startVertex, int goalVertex) const {
	map<int, int> verticesColor;
	int currentVertex;
	for (auto v : vertices)
		verticesColor[v.first] = WHITE;

	stack<int> S;
	if (verticesColor.empty()) return false;


	S.push(startVertex);
	while (!S.empty()) {
		currentVertex = S.top();
		S.pop();
		if (currentVertex == goalVertex) return true;
		if (verticesColor[currentVertex] == WHITE) {
			verticesColor[currentVertex] = BLACK;

			for (auto v : vertices.at(currentVertex))
				if (verticesColor[v] == WHITE) S.push(v);
		}
	}

	return false;
}

