// GraphMatrix.h
// Actividad Sem13-2
// Naomi Estefania Nieto Vega A01706095
// Ramsés Herrera Santiago A01283687

#ifndef GraphMatrix_h
#define GraphMatrix_h

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class GraphMatrix {
   private:
  int numNodes;
  int numEdges;
  bool** adjMatrix;
  void split(std::string line, std::vector<int>& res);

   public:
  void loadGraphList(std::istream& input);
  GraphMatrix(int numEdges);
  void addEdge(int i, int j);
  void printMatrix();
  void removeEdge(int i, int j);
  ~GraphMatrix();
  void AdjMatrixBFS( int start);
  void AdjMatrixDFS( int &vertex, vector<bool> &visited);
  void AdjMatrixDFSInitialize( int start);
};


  void GraphMatrix::loadGraphList(std::istream& input) {
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
        i++;
        continue;
      }
      vector<int> res;
      split(line, res);
      int u = res[0];
      int v = res[1];
      addEdge(u,v);
      i++;
    }
}

void GraphMatrix::split(std::string line, std::vector<int>& res) {
  int strPos = line.find(" ");
  int lastPos = 0;
  while (strPos != std::string::npos) {
    res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
    lastPos = strPos + 1;
    strPos = line.find(" ", lastPos);
  }
  res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}
  // Initialize the matrix to zero
  GraphMatrix::GraphMatrix(int numEdges) {
    this->numEdges = numEdges;
    adjMatrix = new bool*[numEdges];
    for (int i = 0; i < numEdges; i++) {
      adjMatrix[i] = new bool[numEdges];
      for (int j = 0; j < numEdges; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void GraphMatrix::addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void GraphMatrix::removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void GraphMatrix::printMatrix() {
    cout << "\n";
    for (int i = 0; i < numNodes; i++) {
      cout << i << " : ";
      for (int j = 0; j < numNodes; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }

  GraphMatrix::~GraphMatrix() {
    for (int i = 0; i < numNodes; i++)
      delete[] adjMatrix[i];
    delete[] adjMatrix;
  }

  void GraphMatrix::AdjMatrixBFS( int start)
    {
    cout << "\nDoing a BFS on an adjacency matrix.\n";
    
    int n = numNodes; //adjMatrix.size();
    // Create a "visited" array (true or false) to keep track of if we visited a vertex.
    bool visited[n] = { false };
    
    // Create a queue for the nodes we visit.
    queue<int> q;
    
    // Add the starting vertex to the queue and mark it as visited.
    q.push(start);
    visited[start] = true;
    
    // While the queue is not empty..
    while(q.empty() == false)
        {
        int vertex = q.front();
        q.pop();
        
        cout << vertex << " ";
        
        // Loop through all of it's friends.
        for(int i = 0; i < numNodes; i++) //adjMatrix[vertex].size(); i++)
            {
            
            // The neighbor is the column number, and the edge is the value in the matrix.
            int neighbor = i;
            int edge = adjMatrix[vertex][i];
            
            // If the edge is "0" it means this guy isn't a neighbor. Move on.
            if(edge == 0) { continue; }
            
            // If the friend hasn't been visited yet, add it to the queue and mark it as visited
            if(visited[neighbor] == false)
                {
                q.push(neighbor);
                visited[neighbor] = true;
                }
            }
        }
    cout << endl << endl;
    return;
    }

void GraphMatrix::AdjMatrixDFS( int &vertex, vector<bool> &visited)
    {
    // Mark the vertex as visited.
    visited[vertex] = true;
    
    // Outputting vertex+1 because that's the way our graph picture looks.
    cout << vertex << " ";
    
    // Look at this vertex's neighbors.
    for(int i = 0; i < numNodes; i++)
        {
        int edge = adjMatrix[vertex][i];
        int neighbor = i;
        //cout << "Neighbor: " << i << endl;
        // If the edge doesn't exist, move on.
        if(edge == 0) { continue; }
        
        // Recursively call DFS on the neighbor, if it wasn't visited.
        if(visited[neighbor] == false)
            {
            AdjMatrixDFS(neighbor, visited);
            }
        }
    }
    
// Given an Adjacency Matrix, do a DFS on vertex "start"
void GraphMatrix::AdjMatrixDFSInitialize( int start)
    {
    cout << "Doing a DFS on an adjacency matrix.\n";
    
    int n = numNodes;
    // Create a "visited" array (true or false) to keep track of if we visited a vertex.
    vector<bool> visited;
    
    for(int i = 0; i < n; i++)
        {
        visited.push_back(false);
        }
    
    AdjMatrixDFS( start, visited);
    
    cout << endl << endl;
    return;
    }

#endif /* GraphMatrix_h */