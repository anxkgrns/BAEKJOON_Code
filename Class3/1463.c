#include<iostream>
#include<vector>

using namespace std;

int minn[1000010]={0,};

int div(int x){
    if( minn[x] !=0 || x == 1){
        return minn[x];
    }
    int a1,a2,a3;
    int m1,m2,m3;
    if(x%2 == 0){
        a1 = x/2;
    }
    else{
        a1 = x-1;
    }
    if(x%3 == 0){
        a2 = x/3;
    }
    else{
        a2 = x-1;
    }
    a3 = x-1;
    
    minn[a1] = div(a1);
    minn[a2] = div(a2);
    minn[a3] = div(a3);
    minn[x] = min(min(minn[a1],minn[a2]),minn[a3])+1;
    return minn[x];
}

int main()
{
    int X;
    scanf("%d",&X);
    printf("%d",div(X));
}