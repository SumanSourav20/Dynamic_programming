#include<iostream>
#include<vector>
#include<unordered_map>

bool canSum(std::vector<int>& arr, int sum,std::unordered_map<int,bool> &memo)
{
    if(memo.find(sum) != memo.end())
        return memo[sum];

    if(sum == 0)
        return true;

    if(sum < 0)
        return false;

    for(int i : arr){

        if(canSum(arr,sum - i,memo) == true){
            memo[sum - i] = true; 
            return true; 
        }  
        else
            memo[sum - i] = false;  
        
    }   

    return false;

}

bool canSum(std::vector<int>& arr, int targetSum)
{
    std::unordered_map<int, bool> memo = {};
    return canSum(arr,targetSum,memo);

}

int main()
{
    std::vector<int> vec1 = {2, 3};
    std::vector<int> vec2 = {5, 3, 4, 7};
    std::vector<int> vec3 = {2, 4};
    std::vector<int> vec4 = {2, 3, 5};
    std::vector<int> vec5 = {14,7};

    std::cout << canSum(vec1,7) << std::endl;

    std::cout << canSum(vec2,7) << std::endl;

    std::cout << canSum(vec3,7) << std::endl;

    std::cout << canSum(vec4,8) << std::endl;

    std::cout << canSum(vec5,300) << std::endl;
    

    return 0;
}