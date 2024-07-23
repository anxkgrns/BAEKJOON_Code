#include<iostream>
#include<queue>

using namespace std;

int n,m;
int travel[1001][1001];
int arr[1001][1001];
queue<pair<int,int>> q;

void visit(int a,int b){
    int da[4] = {1,0,-1,0};
    int db[4] = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int A = a + da[i];
        int B = b + db[i];
        if(A>=0&&A<=n-1&&B>=0&&B<=m-1){
            if(travel[A][B]==0 && arr[A][B] == 1){
                travel[A][B] = travel[a][b]+1;
                q.push(make_pair(A,B));
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==2){
                x=i;
                y=j;
            }
        }
    }
    travel[x][y] = 0;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        visit(a,b);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(travel[i][j]==0 && arr[i][j] == 1){
                printf("-1 ");
            }
            else printf("%d ",travel[i][j]);
        }
        printf("\n");
    }
    
}