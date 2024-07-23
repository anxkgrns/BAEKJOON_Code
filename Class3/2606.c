#include<iostream>

using namespace std;

int N,K;
int arr[105][105]={0,};
int visit[105] ={0,};
int num = 0;

void search(int x){
    for(int i = 1;i<=N;i++){
        if(arr[x][i] == 1 && visit[i] == 0){
            visit[i] = 1;
            num++;
            search(i);
        }
    }
}

int main()
{
    scanf("%d",&N);
    scanf("%d",&K);
    for(int i = 0 ;i<K;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        arr[t1][t2] = 1;
        arr[t2][t1] = 1;
    }
    visit[1] = 1;
    search(1);
    cout << num << endl;
}