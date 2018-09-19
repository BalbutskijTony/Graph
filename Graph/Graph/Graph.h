#pragma once
#define WHITE 0
#define GREY 1
#define BLACK 2


#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>



using std::pair;
using std::vector;
using std::set;
using std::map;
using std::stack;
using std::queue;


class Graph
{
public:
	Graph() {};
	~Graph() {};

	void addVertex(int vertex);
	void addEdge(int startVertex, int endVertex);

	bool widthSearch(int startVertex, int goalVertex) const;
	bool depthSearch(int startVertex, int goalVertex) const;

	bool has_vertex(int vertex) const;
private:
	map<int, vector<int>> vertices;
};

	
	