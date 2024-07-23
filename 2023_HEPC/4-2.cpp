#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

const int MOD = 1000000007;

long long power(int a, int b) {
    long long result = 1;
    if (b == 0) {
        return 1;
    }
    if(b == 1) {
        return a;
    }
    if(b % 2 == 0) {
        result = (power(a, b/2)%MOD);
        result = (result * result)%MOD;
    }
    
    else {
        result = (power(a, b-1)*a)%MOD;
    }
    return (result);
}
long long D(int p, int c, const std::vector<long long> &D_n, int X) {
    long long result = 0;
    for (int i = 1; i < p; i++) {
        result = result - ((power(c, p - i)) * (D_n[i + X - 1]));
        //result += (-static_cast<long long>(std::pow(c, p - i) * (D_n[i + X - 1])))%MOD;
    }
    if(result < 0) {
        return result;
    }
    else{
        return result;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, c, k;
    std::cin >> p >> c >> k;

    std::vector<int> money(p);
    for (int i = 0; i < p; i++) {
        std::cin >> money[i];
    }

    std::vector<long long> D_n(k+1);
    for (int i = 0; i < p-1 ; i++) {
        D_n[i] = (money[i + 1] - money[i]);
    }

    // for (int i = p-1; i < k; i++) {
    //     D_n[i] = D(p, c, D_n, i - p + 1);
    //     cout << D_n[i] << endl;
    // }
    D_n[p-1] = D(p, c, D_n, 0);
    for (int i = p; i < k; i++) {
        D_n[i] = power(c,p-1)*D_n[i-(p-1)];
    }
    for(int i = 0; i < k; i++) {
        cout << D_n[i] << endl;
    }   
    int answer = D_n[k-1];
    if(D_n[k-1] < 0) {
        answer = (-1)*D_n[k-1];
    }   
    answer %= MOD;
    
    std::cout << answer << std::endl;

    return 0;
}
