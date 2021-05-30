/* 
* Actividad Sem14.  
* main.cpp
* Naomi Estefania Nieto Vega A01706095
* Ramsés Herrera Santiago A01283687
*/

#ifndef Bipartite_h
#define Bipartite_h

#include <iostream>
#include <cstdio>
#include <stack>
#include <list>
#include "TopologicalSort.h"
using namespace std;

class Bipartite
{
    private:
        bool isBipartite;
        bool *color;
        bool *marked;
        int *edgeTo;
        stack<int> cycle;
    public:
        Bipartite(Graph G)
        {
            isBipartite = true;
            color = new bool [G.V];
            marked = new bool [G.V];
            edgeTo = new int [G.V];
            for (int v = 0; v < G.V; v++)
            {
                if (!marked[v])
                {
                    color[v] = false;
                    dfs(G, v);
                }
            }
        }
        /*
         * DFS
         */
        void dfs(Graph G, int v)
        {
            marked[v] = true;
            list<int>::iterator w;
            for (w = G.adj[v].begin(); w != G.adj[v].end(); w++)
            {
                if (!cycle.empty())
                    return;
                if (!marked[*w])
                {
                    edgeTo[*w] = v;
                    color[*w] = !color[v];
                    dfs(G, *w);
                }
                else if (color[*w] == color[v])
                {
                    isBipartite = false;
                    cycle.push(*w);
                    for (int x = v; x != *w; x = edgeTo[x])
                    {
                        cycle.push(x);
                    }
                    cycle.push(*w);
                }
            }
        }
        /* 
         * Returns true if graph is Bipartite
         */
        bool isBi()
        {
            return isBipartite;
        }
};
 

#endif /* Bipartite_h */