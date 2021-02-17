#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>


bool canConstruct(std::string str, std::vector<std::string> list, std::unordered_map<std::string,bool> &memo)
{
    if(memo.find(str) != memo.end())
        return memo[str];

    if(str == "")
        return true;

    for(std::string word : list){

        if(str.find(word) == 0){
            std::string suffics = str.substr(word.size());
            //std::cout<<suffics << " ";
            //std::cout<<suffics.size()<<" ";
            bool x = canConstruct(suffics,list,memo);
            if(x){
                memo[suffics] = true;
                return true;
            }
            else
                memo[suffics] = false;
        
        }
             
    }  
    
    return false;  
}

bool canConstruct(std::string str, std::vector<std::string> list)
{
    std::unordered_map<std::string,bool> memo = {};
    return canConstruct(str,list,memo);
}

int main()
{
    std::cout << canConstruct("abcdef",{"def","ab","cd","f","ef"})<<std::endl;
    std::cout << canConstruct("abcdef", {"ab", "abc", "cd", "ef", "abcd"}) << std::endl;                            // 1 (1 is true)
    std::cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << std::endl;            // 0 (0 is false)
    std::cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << std::endl;
    std::cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"});
    return 0;
}