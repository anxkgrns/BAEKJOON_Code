#include<iostream>

using namespace std;


void find_dfs(int x,int y,int (*maps)[55])
{
    maps[y][x]++;
    if(maps[y-1][x] == 1){
        find_dfs(x,y-1,maps);
    }
    if(maps[y+1][x] == 1){
        find_dfs(x,y+1,maps);
    }
    if(maps[y][x-1] == 1){
        find_dfs(x-1,y,maps);
    }
    if(maps[y][x+1] == 1){
        find_dfs(x+1,y,maps);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int M,N,K;
        scanf("%d %d %d",&M,&N,&K);
        int maps[55][55]={0,};
        int ans = 0;
        int X[K]={0,},Y[K]={0,};
        for(int j=0;j<K;j++){
            scanf("%d %d",&X[j],&Y[j]);
            maps[Y[j]][X[j]] = 1;
        }
        for(int j=0;j<K;j++){
            if (maps[Y[j]][X[j]] == 1){
                ans++;
                find_dfs(X[j],Y[j],maps);
            }
        }
        printf("%d\n",ans);
    }
}