#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int arr[N+5][N+5]={0,};
    for(int i=0;i<M;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr[x][y] = 1;
        arr[y][x] = 1;
    }
    int visited[N+5] = {0,};
    int ans = 0;
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            q.push(i);
            ans++;
        }
        while(!q.empty()){
            int a = q.front();
            q.pop();
            for(int j = 1;j<=N;j++){
                if(arr[a][j] == 1 && visited[j] == 0){
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }   
    }
    printf("%d",ans);
}