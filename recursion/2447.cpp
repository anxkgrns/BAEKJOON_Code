#include <iostream>
using namespace std;

char arr[2188][2188] = {' ',};

void makesq(int i,int j){

    arr[i][j] = '*';
    arr[i][j+1] = '*';
    arr[i][j+2] = '*';
    arr[i+1][j] = '*';
    arr[i+1][j+1] = ' ';
    arr[i+1][j+2] = '*';
    arr[i+2][j] = '*';
    arr[i+2][j+1] = '*';
    arr[i+2][j+2] = '*';
}

void draw(int x, int y, int a){
    if(a == 3){
        makesq(x,y);
        return;
    }
    int b = a/3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == 1 && j == 1){
                continue;
            }
            else{
                draw(x+b*i, y+b*j, b);

            }
        }
    }    
}

int main(){
    for(int i=0; i<2188; i++){
        for(int j=0; j<2188; j++){
            arr[i][j] = ' ';
        }
    }
    int n;
    cin >> n;
    draw(0,0,n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}
