#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int source, destination, weight;
};
struct Graph
{
    int V, E;
    struct Edge* edge;
};
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph =
         (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;

    graph->edge =
       (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

    return graph;
}
void printArr(int distance[], int n)
{
    cout<<"Vertex distance from Source"<<endl;
    for (int i = 0; i < n; ++i)
        cout<<i<<"   "<<distance[i]<<endl;
}
void BellmanFord(struct Graph* graph, int source)
{
    int V = graph->V;
    int E = graph->E;
    int distance[V];
    for (int i = 0; i < V; i++)
        distance[i]   = INT_MAX;
    distance[source] = 0;
    for (int i = 1; i <= V-1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
            printf("Graph contains negative weight cycle");
    }

    printArr(distance, V);

    return;
}
int main()
{
    int V,E;
    cout<<"Enter no.of vertices and edges"<<endl;
    cin>>V>>E;
    struct Graph* graph = createGraph(V, E);

    int a[E][3];
    cout<<"enter source,destination and weight for each edge"<<endl;
    for(int i=0;i<E;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=0;i<E;i++){
        graph->edge[i].source=a[i][0];
        graph->edge[i].destination=a[i][1];
        graph->edge[i].weight=a[i][2];
    }
    long int start_s=clock();
	BellmanFord(graph, 0);// the code you wish to time goes here
    long int stop_s=clock();
    cout << setprecision(5);
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}

