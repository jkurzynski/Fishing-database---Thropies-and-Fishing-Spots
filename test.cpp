#include "./include/choices.hpp"

int main(){
    while(jk::status != jk::Options::Exit){

        switch(jk::status){

            case jk::Options::Main:
                jk::choice_MAIN();
                break;
        
            case jk::Options::Add:
                jk::choice_ADD();
                break;

            case jk::Options::Display:
                jk::choice_DISPLAY();
                break;

            case jk::Options::AddFish:
                jk::choice_ADD_FISH();
                break;

            case jk::Options::AddSpot:
                jk::choice_ADD_SPOT();
                break;
            
            case jk::Options::DisplayFish:
                jk::choice_DISPLAY_FISH();
                break;

            case jk::Options::DisplaySpot:
                jk::choice_DISPLAY_SPOT();
                break;
        }
    }
}