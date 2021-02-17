#include<iostream>
#include<vector>
#include<unordered_map>


std::vector<int> howSum(std::vector<int>& arr, int targetSum, std::unordered_map<int, std::vector<int>> &memo)
{

    if(memo.find(targetSum) != memo.end())
        return memo[targetSum];

    if(targetSum == 0)
        return {};

    if(targetSum < 0)
        return {-1};

    for(int i : arr){
        std::vector<int> result = howSum(arr, targetSum - i,memo);

        if(result != (std::vector<int>){-1}){
            std::vector<int> combination = result;
            combination.push_back(i);
            memo[targetSum - i] = combination;
            return combination;
        }
        else
            memo[targetSum - i] = {-1};

    }  

    return {-1};
    
}

std::vector<int> howSum(std::vector<int>& arr, int targetSum)
{
    std::unordered_map<int, std::vector<int>> memo = {};
    return howSum(arr,targetSum,memo);

}

void print(std::vector<int>& v)
{
    if(v != (std::vector<int>){-1}){
    for(int i : v)
            std::cout<<i<<" ";
    std::cout<<std::endl;
    }
    else
        std::cout<<"Sum not possible"<<std::endl;

}

int main()
{
    std::vector<int> vec1 = {2, 3};
    std::vector<int> vec2 = {5, 3, 4, 7};
    std::vector<int> vec3 = {2, 4};
    std::vector<int> vec4 = {2, 3, 5};
    std::vector<int> vec5 = {14,7};

    std::vector<int> v;

    v = howSum(vec1,7);
    print(v);

    v = howSum(vec2,7);
    print(v);

    v = howSum(vec3,7);
    print(v);

    v = howSum(vec4,8);
    print(v);

    v = howSum(vec5,300);
    print(v);


    return 0;
}