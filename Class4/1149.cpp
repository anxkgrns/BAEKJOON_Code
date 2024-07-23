#include<iostream>

using namespace std;

int main()
{
    int N;
    cin >> N ;
    int RGB[3][N+2];
    for(int i =1;i<=N;i++){
        scanf("%d %d %d",&RGB[0][i],&RGB[1][i],&RGB[2][i]);
    }
    int min[N+2][3];
    for(int x=0;x<3;x++) min[0][x] = 0;
    for(int i =1;i<=N;i++){
        int j = 0;
        int a1 = 1,a2=2;
        int temp1 = min[i-1][a1] + RGB[j][i];
        int temp2 = min[i-1][a2] + RGB[j][i];
        if(temp1>temp2) min[i][j] = temp2;
        else min[i][j] = temp1;
        
        j = 1;
        a1 = 0,a2=2;
        temp1 = min[i-1][a1] + RGB[j][i];
        temp2 = min[i-1][a2] + RGB[j][i];
        if(temp1>temp2) min[i][j] = temp2;
        else min[i][j] = temp1;
        
        j = 2;
        a1 = 0,a2=1;
        temp1 = min[i-1][a1] + RGB[j][i];
        temp2 = min[i-1][a2] + RGB[j][i];
        if(temp1>temp2) min[i][j] = temp2;
        else min[i][j] = temp1;
        //for(int x=0;x<3;x++) printf("%d\n",min[i][x]);
    }
    int MIN = min[N][0];
    for(int x=0;x<3;x++){
        if( MIN > min[N][x]) MIN = min[N][x];
    }
    printf("%d",MIN);
}