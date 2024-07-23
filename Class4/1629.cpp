#include<iostream>

using namespace std;

int A,B,C;
long long f(long long X){
    if(X == 0) return 1;
    if(X == 1) return A % C;
    long long temp = f(X/2) % C;
    if(X%2 == 0) return temp * temp % C;
    return temp * temp % C * A % C;
}

int main()
{
    cin >> A >> B >> C;
    
    cout << f(B) << endl;
}