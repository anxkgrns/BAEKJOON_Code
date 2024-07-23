#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int N;
int paper[130][130] ={0,};
int white = 0;
int blue = 0;

void cut(int paper[][130],int num,int place){
    int x[4] = {0,num,0,num};
    int y[4] = {0,0,num,num};
    if(num == 1){
        int temp = paper[y[place-1]][x[place-1]];
        if(temp == 0) white++;
        if(temp == 1) blue++;
        return;
    }
    int cuts[130][130] ={-1,};
    int sum = 0;
    for(int i = 0;i<num;i++){
        for(int j = 0 ;j<num;j++){
            sum += paper[i+y[place-1]][j+x[place-1]];
            cuts[i][j] = paper[i+y[place-1]][j+x[place-1]];
        }
    }
    if(sum == 0){
        white++;
        return;
    }
    else if(sum == num*num){
        blue++;
        return;
    }
    else{
        cut(cuts,num/2,1);
        cut(cuts,num/2,2);
        cut(cuts,num/2,3);
        cut(cuts,num/2,4);
        return;
    }
    
}

int main()
{
    scanf("%d",&N);
    int sum = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0 ;j<N;j++){
            scanf("%d",&paper[i][j]);
            sum += paper[i][j];
        }
    }
    if(sum == 0){
        white++;
    }
    else if(sum == N*N){
        blue++;
    }
    else{
        cut(paper,N/2,1);
        cut(paper,N/2,2);
        cut(paper,N/2,3);
        cut(paper,N/2,4);
    }
    printf("%d\n%d",white,blue);
    
}