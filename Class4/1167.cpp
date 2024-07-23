#include<iostream>
#include<vector>

using namespace std;

int N;
vector< pair<int,int> > Nodes[100000+2];
int visited[100000 + 2];
int leafs[100000+2];
int dist[100000+2];

void dfs(int x,int length){
    visited[x] = 1; 
    for(int i = 0; i<Nodes[x].size();i++){
        int next = Nodes[x][i].first;
        int nextlength = Nodes[x][i].second;
        if(visited[next] == 0){
            dist[next] = length + nextlength;
            dfs(next,dist[next]);
        }    
    }
    return;
}

int main()
{
    cin >> N ;
    int randomNode = 0;
    for(int i =1;i<=N;i++){
        int sNode ,fNode, cm;
        cin >> sNode;
        
        while(true){
            cin >> fNode;
            if(fNode == -1) break;
            cin >> cm;
            Nodes[sNode].push_back(make_pair(fNode,cm));
        }
        randomNode = sNode;
    }
    //randomNode
    
    dfs(randomNode,0);
    int max = 0;
    int maxNode = 0;
    for(int i = 1 ;i<=N;i++){
        if(max < dist[i]){
            max = dist[i];
            maxNode = i;
        }
    }
    //maxNode
    for (int i = 1; i <= N; i++) {
		visited[i] = 0;
        dist[i] = 0;
	}
	
    dfs(maxNode,0);
    max = 0;
    maxNode = 0;
    for(int i = 1 ;i<=N;i++){
        if(max < dist[i]){
            max = dist[i];
        }
    }
    
    printf("%d",max);
    
    
}