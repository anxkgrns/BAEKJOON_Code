#include<iostream>
#include<stack>
#include<cstring>

using namespace std;

int main()
{
    string str;
    cin >> str;
    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            printf("%c", str[i]);
        }
        else {
            if (str[i] == '(') {
                s.push(str[i]);
            }
            else if (str[i] == ')') {
                while (!s.empty() && s.top() != '(') {
                    printf("%c", s.top());
                    s.pop();
                }
                if (!s.empty()) {
                    s.pop();
                }
            }
            else if (str[i] == '*' || str[i] == '/') {
                while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
                    printf("%c", s.top());
                    s.pop();
                }
                s.push(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-') {
                while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-')) {
                    printf("%c", s.top());
                    s.pop();
                }
                s.push(str[i]);
            }
            else {
                printf("%c", str[i]);
            }
        }
    }
    while (!s.empty()) {
        printf("%c", s.top());
        s.pop();
    }
}
