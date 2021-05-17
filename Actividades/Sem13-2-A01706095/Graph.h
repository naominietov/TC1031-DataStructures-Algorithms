// Graph.h
// Actividad Sem13-2
// Naomi Estefania Nieto Vega A01706095
// Ramsés Herrera Santiago A01283687

#ifndef Graph_h
#define Graph_h

#include <list>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

class Graph {
  private:
    int numNodes;
    int numEdges;
    std::vector<int> *adjList;
    void split(std::string line, std::vector<int>& res);
  public:
    void loadGraphList(std::istream& input);
    string printAdjList();
    void BFS(int s);
    void DFSUtil(int v, bool visited[]); 
    void DFS(int);  
};



void Graph::loadGraphList(std::istream& input) {
    std::string line;
    int i = 0;
    while (std::getline(input, line)) {
      if (i == 0) {
        i++;
        continue;
      }
      if (i == 1) {
        std::vector<int> res;
        split(line, res);
        for (int i = 0; i < res.size(); i++)
          cout << res[i] << endl;
        numNodes = res[0];
        numEdges = res[2];
        adjList = new vector<int>[numNodes+1];
        i++;
        continue;
      }
      vector<int> res;
      split(line, res);
      int u = res[0];
      int v = res[1];
      adjList[u].push_back(v);
      adjList[v].push_back(u);
      i++;
    }
}

void Graph::split(std::string line, std::vector<int>& res) {
  int strPos = line.find(" ");
  int lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

string Graph::printAdjList(){
	  stringstream aux;
		for (int i = 0; i < numNodes; i++){
	        aux << "vertex "
	             << i << " :";
	        for (int j = 0; j < adjList[i].size(); j ++){
							 aux << " " << adjList[i][j];
					}
	        aux << " \n";
    }
    
		return aux.str();
}

void Graph::BFS(int s)
{
    bool *visited = new bool[numEdges];
    for(int i = 0; i < numEdges; i++)
        visited[i] = false;
 
    vector<int> queue;
 
    visited[s] = true;
    queue.push_back(s);
 
    vector<int>::iterator i;
 
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.erase(queue.begin());
;
 
        for (i = adjList[s].begin(); i != adjList[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[])
{

	visited[v] = true;
	cout << v << " ";

	vector<int>::iterator i;
	for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited);
}

void Graph::DFS(int v)
{
    bool *visited = new bool[numEdges];
    for (int i = 0; i < numEdges; i++)
        visited[i] = false;
 

    DFSUtil(v, visited);
}



#endif /* Graph_h */