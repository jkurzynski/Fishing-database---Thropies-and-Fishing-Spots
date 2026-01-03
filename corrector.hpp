#pragma once
#include <string>
#include <cctype>
namespace jk{

std::string correct(std::string word){
    for(int i = 0; i < word.size(); i++){
            i==0 ? word[i] = toupper(word[i]) : word[i] = tolower(word[i]);
        }
    return word;
}
}