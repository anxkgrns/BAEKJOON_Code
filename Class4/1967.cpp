#include<iostream>
#include<vector>

#define MAX_N 10000

using namespace std;

vector< pair<int,int> > Nodes[MAX_N+1];
vector<int> visited(MAX_N+1,0);
vector<int> dist(MAX_N+1,0);

int dfs(int Node,int length){
    
    visited[Node] = 1;
    for(int i = 0; i<Nodes[Node].size();i++){
        int nextNode = Nodes[Node][i].first;
        int nextLength = Nodes[Node][i].second;
        if(visited[nextNode] == 0){
            dist[nextNode] = length + nextLength;
            dfs(nextNode,dist[nextNode]);
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    for(int i =0; i<n-1;i++){
        int weight;
        int startNode;
        int endNode;
        cin >> startNode >> endNode >> weight;
        Nodes[startNode].push_back(make_pair(endNode,weight));
        Nodes[endNode].push_back(make_pair(startNode,weight));
    }

    int startNode = 1;
    dfs(startNode,0);
    int max = 0;
    int maxNode = 0;
    for(int i = 1; i<=n;i++){
        if(max < dist[i]){
            max = dist[i];
            maxNode = i;
        }
    }
    for(int i = 1; i<=n;i++){
        visited[i] = 0;
        dist[i] = 0;
    }
    dfs(maxNode,0);
    max = 0;
    for(int i = 1; i<=n;i++){
        if(max < dist[i]){
            max = dist[i];
        }
    }
    cout << max;

}
