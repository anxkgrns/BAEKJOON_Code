#include<iostream>

using namespace std;

int main()
{
    int N,r,c;
    cin >> N >> r >> c;
    int min_r1=1,min_c1=1;
    int N_2=1;
    for(int i=0;i<N;i++){
        N_2 *=2;
    }
    long int sum = 0;
    while(true){
        long int cube = (N_2 * N_2)/4;
        if(c+1 > N_2/2){
            c -= N_2/2;
            sum += cube; 
        }        
        if(r+1 > N_2/2){
            r -= N_2/2;
            sum += cube*2;
        }        
        N_2 = N_2/2;
        if(N_2 == 1){
            break;
        }
    }
    cout << sum;
}