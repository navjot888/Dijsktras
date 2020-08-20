#include<iostream>
#include<set>
#include<list>
#include<algorithm>
using namespace std;

typedef struct nodes 
{
   int DEST;
   int COST;
}node;

class Graph 
{
   int N;
   list<node> *adjList;
   private:
      void showList(int src, list<node> lt)
      {
         list<node> :: iterator i;
         node tempNode;

         for(i = lt.begin(); i != lt.end(); i++)
         {
            tempNode = *i;
            cout << "(" << src << ")---("<<tempNode.DEST << "|"<<tempNode.COST<<") ";
         }
         cout << endl;
      }
   public:
      Graph()
      {
        N = 0;
      }

      Graph(int nodeCount) 
      {
         N = nodeCount;
         adjList = new list<node>[N];
      }

      void addEdge(int source, int DEST, int COST) 
      {
         node newNode;
         newNode.DEST = DEST;
         newNode.COST = COST;
         adjList[source].push_back(newNode);
      }

      void displayEdges() 
      {
         for(int i = 0; i < N; i++)
         {
            list<node> tempList = adjList[i];
            showList(i, tempList);
         }
      }

      friend void dijkstra(Graph G, int *dist, int *prev, int start);
};

void dijkstra(Graph G, int *dist, int *prev, int start)
{
   int N = G . N;

   for(int u = 0; u < N; u++)
   {
      dist[u] = 9999;   //set as infinity
      prev[u] = -1;    //undefined previous
   }

   dist[start] = 0;   //distance of start is 0
   set<int> S;       //create empty set S
   list<int> Q;

   for(int u = 0; u < N; u++) 
   {
      Q.push_back(u);    //add each node into queue
   }

   while(!Q.empty())
   {
      list<int> :: iterator i;
      i = min_element(Q.begin(), Q.end());
      int u = *i; //the minimum element from queue
      Q.remove(u);
      S.insert(u); //add u in the set
      list<node> :: iterator it;

      for(it = G.adjList[u].begin(); it != G.adjList[u].end();it++)
      {
         if((dist[u]+(it-> COST)) < dist[it-> DEST])//(u,v)
         {
            dist[it-> DEST] = (dist[u]+(it-> COST));
            prev[it->DEST] = u;
         }
      }
   }
}

main() {
   int N = 7;
   Graph G(N);
   int dist[N], prev[N];
   int start = 0;

   G.addEdge(0, 1, 3);
   G.addEdge(0, 2, 6);
   G.addEdge(1, 0, 3);
   G.addEdge(1, 2, 2);
   G.addEdge(1, 3, 1);
   G.addEdge(2, 1, 6);
   G.addEdge(2, 1, 2);
   G.addEdge(2, 3, 1);
   G.addEdge(2, 4, 4);

   G.addEdge(2, 5, 2);
   G.addEdge(3, 1, 1);
   G.addEdge(3, 2, 1);
   G.addEdge(3, 4, 2);
   G.addEdge(3, 6, 4);
   G.addEdge(4, 2, 4);
   G.addEdge(4, 3, 2);
   G.addEdge(4, 5, 2);
   G.addEdge(4, 6, 1);
   G.addEdge(5, 2, 2);
   G.addEdge(5, 4, 2);
   G.addEdge(5, 6, 1);
   G.addEdge(6, 3, 4);
   G.addEdge(6, 4, 1);
   G.addEdge(6, 5, 1);

   dijkstra(G, dist, prev, start);

   for(int i = 0; i < N; i++)
      if(i != start)
         cout<<start<<" to "<<i<<", Cost: "<<dist[i]<<" Previous: "<<prev[i]<<endl;
}

