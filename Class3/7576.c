#include<iostream>
#include<queue>

using namespace std;

int main()
{
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int M,N;
    scanf("%d %d",&M,&N);
    int arr[N+5][M+5];
    queue<pair<int,int>> tomato;
    for(int i=0;i<N;i++){
        for(int j =0;j<M;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j] == 1){
                tomato.push(make_pair(i,j));
            }
        }
    }
    while(!tomato.empty()){
        int x = tomato.front().first;
        int y = tomato.front().second;
        tomato.pop();
        for(int i =0 ;i<4;i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X>=0 && X<N && Y>=0 && Y<M){
                if(arr[X][Y] == 0){
                    arr[X][Y] = arr[x][y] + 1;
                    tomato.push(make_pair(X,Y));
                }
            }
        }     
    }
    int result = 0;
    for(int i=0;i<N;i++){
        for(int j =0;j<M;j++){
            if(arr[i][j] == 0){
                printf("-1");
                return 0;
            }
            if(result < arr[i][j]){
                result = arr[i][j];
            }
        }
    }
    printf("%d",result-1);
}