#include<iostream>

int memo[50][2] = {0,};

using namespace std;

int fibonacci(int n,int i) {
    if (n == 0 ) {
        return memo[0][i];
    } else if (n == 1) {
        return memo[1][i];
    } else if(memo[n][i]!=0){
        return memo[n][i];
    } else {
        memo[n][i] = fibonacci(n-1,i) + fibonacci(n-2,i);
        return memo[n][i];
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    int N[T];
    int max = 0;
    for(int i=0;i<T;i++){
        scanf("%d",&N[i]);
        if(max < N[i]){
            max = N[i];
        }
    }
    memo[0][0] = 1;
    memo[0][1] = 0;
    memo[1][0] = 0;
    memo[1][1] = 1;
    fibonacci(max,0);
    fibonacci(max,1);
    for(int i =0;i<T;i++){
        printf("%d %d\n",memo[N[i]][0],memo[N[i]][1]);
    }
}