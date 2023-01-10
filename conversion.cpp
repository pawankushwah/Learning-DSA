#include <IOSTREAM>
#include <ctype.h>
#include <CMATH>

using namespace std;

void toDecimal()
{
    string binary;
    cout << "binary: ";
    getline(cin, binary);

    int sum = 0;
    int posWeight = 1;
    int maxTerm = binary.length();
    for (int i = 1; i <= maxTerm; i++)
    {
        int number = (isalpha((binary[maxTerm - i])) != 0) ? ((binary[maxTerm - i]) - 'a' + 10) : ((binary[maxTerm - i]) - '0');
        sum += number * posWeight;
        posWeight *= 2;
    }
    cout << "Decimal = " << sum;
    // cout<<endl<<maxTerm;
    // cout<<endl<<binary[0];
    return;
}

void toBinary()
{
    unsigned int decimal;
    cout << "Decimal: ";
    cin >> decimal;

    // converting to binary
    bool binary[25];
    int i;
    for (i = 0; decimal > 0; i++)
    {
        binary[i] = decimal % 8;
        decimal /= 8;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binary[j];

    return;
}

bool isPrime(int n)
{
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

bool reverseNumber(int n)
{
    int rev = 0;
    while(n > 0)
    {
        rev = (rev * 10) + (n % 10);
        n /= 10;
    }
    return rev;
}

int main(void)
{
    // toBinary();
    // (isPrime(20) == 1) ? cout << "prime" : cout << "non-prime";
    int result = reverseNumber(123);
    cout<<result;
    return 0;
}