// 11-11-17
//Algorithm LAB
//Md. Al Shahriar
//1611076145

#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1000000;

int N, M, adj[1000][1000], dist[1000]; bool flag[1000];

void dijkstra(int source){
    fill(dist, dist+1000, INF);
    dist[source] = 0;
    for(int i=1; i<=N; i++){
        int d=INF, u=0;
        for(int j=1; j<=N; j++)
            if(!flag[j] && dist[j]< d){
                d=dist[j]; u=j;
            }
        flag[u] = 1;
        for(int j=1; j<=N; j++){	
        	if(!flag[j])
                dist[j]=min(dist[j], dist[u]+adj[u][j]);
		}
    }
}
int main(){
    cin >> N >> M;
    fill_n(&adj[0][0], 1000*1000, INF);
    int u, v, w;
    for(int i=0; i<M; i++){
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = min(adj[u][v], w);
    }
    dijkstra(1);
    for(int i=1; i<=N; i++){
		
		if(flag[i])
			cout << dist[i] << endl;
        else
			cout << -1 << endl;
	
	}
}
