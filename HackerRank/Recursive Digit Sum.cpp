#include <bits/stdc++.h>
using namespace std;

int superDigit(string n, int k)
{
    long long int sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        sum+=(n.at(i)-'0');
    }
    sum = sum * k;
    if (sum<10)
    {
        return sum;
    }
    n=to_string(sum);
    return superDigit(n, 1);
}

int main()
{
    string n = "9875";
    long long int k = 4;
    long long int ans = superDigit(n, k);
    cout <<endl<< ans << endl;
    return 0;
}