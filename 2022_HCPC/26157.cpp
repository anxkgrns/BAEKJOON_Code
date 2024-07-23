#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

vector<int> graph[200001];
stack<int> s;


int DFS(int a){
    for(auto iter = graph[a].begin(); iter <= graph[a].end(); iter++){
        if( a == DFS(*iter)){
            
        }
        return *iter;
    }
}

int main()
{
    int N,M;
    cin >> N >> M;
    
    for(int i = 0; i < M; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int prob = 0;
    int prob_list[200001];
    
    

    cout << prob << endl;

    for(int i = 0; i< prob; i++){
        cout << prob_list[i] << endl;
    }

    return 0;

}
