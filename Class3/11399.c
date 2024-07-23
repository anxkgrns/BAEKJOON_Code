#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int N;
    scanf("%d",&N);
    int P[N+2];
    for(int i = 0 ; i < N ; i++ ){
        scanf("%d",&P[i]);        
    }
    sort(P,P+N);
    int sum = 0;
    for(int i=0;i<N;i++){
        sum += P[i]*(N-i);
    }
    printf("%d",sum);
}