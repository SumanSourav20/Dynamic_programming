#include<iostream>
#include<unordered_map>

std::unordered_map<int,long long> memo;

long long fibonacci(int n)
{
    if(memo.find(n) != memo.end())
        return memo[n];

    if(n<=2)
        return 1;

    long long res = fibonacci(n-1) + fibonacci(n-2);
    memo[n] = res;
    return res;   

}

int main()
{

    std::cout<<fibonacci(49);
    return 0;

}