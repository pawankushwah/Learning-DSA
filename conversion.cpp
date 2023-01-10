#include <IOSTREAM>
#include <ctype.h>
#include <CMATH>

using namespace std;

void toDecimal()
{
    // Taking input from the user
    string number;
    cout << "binary: ";
    getline(cin, number);

    // Declaration of variables
    int sum = 0;
    int posWeight = 1;
    int maxTerm = number.length();

    // loop for converting (binary, octal and hexadecimal) number to decimal number
    for (int i = 1; i <= maxTerm; i++)
    {
        int number = (isalpha((number[maxTerm - i])) != 0) ? ((number[maxTerm - i]) - 'a' + 10) : ((number[maxTerm - i]) - '0');
        sum += number * posWeight;

        // for changing number from octal and hexadecimal replace 2 with 8 and 16
        posWeight *= 2; 
    }

    // printing the decimal number or result
    cout << "Decimal = " << sum;

    // some lines for debugging the code
    // cout<<endl<<maxTerm;
    // cout<<endl<<number[0];
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