#include<iostream>
using namespace std;

void hanio(int n, int from, int by, int to){
    if(n == 1){
        printf("%d %d\n", from, to);
        return;
    }
    else{
        hanio(n-1, from, to, by);
        printf("%d %d\n", from, to);
        hanio(n-1, by, from, to);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", (1<<n)-1);
    hanio(n, 1, 2, 3);
}