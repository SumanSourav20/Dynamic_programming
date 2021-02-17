#include<iostream>
#include<unordered_map>
#include<string>

std::unordered_map<std::string,long long> memo;

long long grid(int h,int w)
{
    if(memo.find(std::to_string(h) + "," + std::to_string(w)) != memo.end())
        return memo[std::to_string(h) + "," + std::to_string(w)];

    if(h == 0 and w == 0)
        return 0;

    if(w == 1 or h == 1)
        return 1;

    long long ways = grid(h-1,w) + grid(h,w-1);
    
    memo[std::to_string(h) + "," + std::to_string(w)] = ways;
    return ways;        
}

int main()
{
    std::cout<<grid(18,20);
    return 0;
}