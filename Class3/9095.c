#include<iostream>


using namespace std;

int main()
{
    int T;
    scanf("%d",&T);
    int N[T+5];
    int max = 0;
    for(int i = 0;i<T;i++){
        scanf("%d",&N[i]);
        if(max < N[i]) max = N[i];
    }
    int num[15];
    num[1] = 1;
    num[2] = 2; //1+1,2
    num[3] = 4; //1+1+1 : 1개 ,1+2 : 2개 , 3 : 1개
    for(int i= 4;i < 11;i++){
        num[i] = num[i-1] + num[i-2] + num[i-3];
    }
    for(int i = 0;i<T;i++){
        printf("%d\n",num[N[i]]);
    }
}