#include<iostream>

using namespace std;

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    int arr[N+5];
    int sumArr[N+5];
    for(int i =0;i<N;i++){
        scanf("%d",&arr[i]);
        if(i ==0) sumArr[i] = arr[i];
        else sumArr[i] = arr[i]+ sumArr[i-1];
    }
    for(int i =0;i<M;i++){
        int sum = 0;
        int a,b;
        scanf("%d %d",&a,&b);
        if(a==1) sum = sumArr[b-1];
        else sum = sumArr[b-1]-sumArr[a-2];
        printf("%d\n",sum);
    }
}