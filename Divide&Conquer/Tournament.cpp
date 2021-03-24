#include <iostream>
#define MAXNUM 100
int a[MAXNUM][MAXNUM];
int b[MAXNUM];
using namespace std; 
bool odd(int n)
{
    return n & 1;
}
void copy(int n) {
    int m = n / 2;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j + m] = a[i][j] + m;
            a[i + m][j] = a[i][j + m];
            a[i + m][j + m] = a[i][j];
        }
    }
}
void copyodd(int n) {
    int m = n / 2;
    for (int i = 1; i <= m; i++) {
        b[i] = m + i; b[m + i] = b[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m+1; j++) {
            if (a[i][j] > m) {
                a[i][j] = b[i];
                a[m + i][j] = (b[i] + m) % n;
            }
            else a[m + i][j] = a[i][j] + m;
        }
        for (int j = 2; j <= m; j++) {
            a[i][m+j] = b[i+j-1];
            a[b[i+j-1]][m+j] = i;
        }
    }
}
void makecopy(int n) {
    if (n / 2 > 1 && odd(n / 2))copyodd(n);
    else copy(n);
}
void tourna(int n)
{
    if (n == 1) { 
        a[1][1] = 1;
        return;
    }
    if (odd(n)) { 
        tourna(n + 1);
        return; }
    tourna(n / 2);
    makecopy(n);
}

void print(int n) {
    cout << "比赛日程表为：" << endl;
    cout << "*代表该场没有比赛" << endl;
    int m=n;
    if (odd(n)) { m++; }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (odd(n) && a[i][j] == m)cout << "* ";
            else { cout << a[i][j] << " "; }
        }
        cout << endl;
    }
}

int main()
{
    cout << "请输入要参赛的总人数" << endl;
    int n;
    cin >> n;
    tourna(n);
    print(n);
    
}
