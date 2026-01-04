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
/**
 * Purpose of correct() function is to make sure that every word/sentence begins with upper letter.
 * It makes everything look better, but also guarantees that there will be no copies of intended same object.
 */
}