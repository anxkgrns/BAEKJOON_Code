#include<iostream>
#include<vector>
#include<queue>
#define MAX 10 * 300000 + 1

using namespace std;

// int find_min(vector<int> dist, vector<bool> visited){
//     int min = MAX;
//     int min_index = 0;
//     for(int i = 1;i<dist.size();i++){
//         if(!visited[i] && dist[i] < min){
//             min = dist[i];
//             min_index = i;
//         }
//     }
//     return min_index;
// }

int main()
{
    int V,E;
    cin >> V >> E;
    int K; // start node
    cin >> K;
    vector< pair <int,int> > adj[V+1];
    for(int i = 0 ;i<E;i++){
        int u,v,w;
        cin >> u >> v >> w; // u -> v, weight = w
        adj[u].push_back(make_pair(w,v));
    }
    vector<int> dist(V+1,MAX);
    //vector<bool> visited(V+1,false);

    // 평범한 다익스트라
    // int start = K;
    // dist[start] = 0;
    // visited[start] = true;
    // for(int i = 1;i<=V;i++){
    //     for(int j = 0;j<adj[start].size();j++){
    //         dist[adj[start][j].first] = adj[start][j].second;
    //     }
    // }
    // for(int i = 0;i<V-1;i++){
    //     int u = find_min(dist,visited); // 연산량이 많다. 
    //     if(u == 0) break; // if there is no node to visit
    //     visited[u] = true;
    //     for(int j = 0;j<adj[u].size();j++){
    //         if(!visited[adj[u][j].first] && dist[u] + adj[u][j].second < dist[adj[u][j].first]){
    //             dist[adj[u][j].first] = dist[u] + adj[u][j].second;
    //         }
    //     }
    // }
    
    // 최솟값을 구하는 방법을 이진힙이라는 기술을 통한 우선순위 큐를 이용하자.

    // priority_queue<int, vector<int>, greater<int>> pq; 이런식으로 작성
    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq; // 오름차순 
    dist[K] = 0;
    pq.push(make_pair(0,K));
    while(!pq.empty()){
        int weight = pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < weight) continue; // 갱신되어서 최솟값이 변경된 경우
        for(int i =0;i<adj[here].size();i++){
            int nextDist = weight + adj[here][i].first;
            int next = adj[here][i].second;
            if(nextDist < dist[next]){
                dist[next] = nextDist;
                pq.push(make_pair(nextDist,next));
            }
        }
    }

    for( int i = 1;i<=V;i++){
        if(dist[i] == MAX){
            printf("INF\n");
        }
        else{
            printf("%d\n",dist[i]);
        }
    }
}