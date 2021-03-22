/*compile successful*/
/*data structure can be changed ,using longlong here*/

#include <iostream>
#include<math.h>
using namespace std;

long long max(long long a, long long b)
{
    return a > b ?  a : b;
}
/*karatsuba algorithm*/
long long LargeIntegerMul(long long num1, long long num2)
{
    if (num1 < 10 || num2 < 10)
        return num1 * num2;

    //拆分长度
    long long size1 = (long long)log10(num1) + 1;
    long long size2 = (long long)log10(num2) + 1;
    long long halfN = max(size1, size2) / 2;

    long long a = num1 / ( halfN * 10);
    long long b = num1 % ( halfN * 10);
    long long c = num2 / ( halfN * 10);
    long long d = num2 % ( halfN * 10);

    long long z2 = LargeIntegerMul(a, c);
    long long z0 = LargeIntegerMul(b, d);
    long long z1 = LargeIntegerMul((a + b), (c + d)) - z0 - z2;

    return (long)(z2 * pow(10, (2 * halfN)) + z1 * pow(10, halfN) + z0);

}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << LargeIntegerMul(a, b);
}
