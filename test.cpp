#include "./include/fish.hpp"
#include "./include/fishing_spots.hpp"
#include "./include/save.hpp"
#include "./include/load.hpp"
#include "./include/options.hpp"


int main(){
    jk::Options status = jk::Options::Main;
    jk::Fish *fish;
    jk::Fishing_spot *spot;
    int choice;
    int fish_object_created {0};
    int spot_object_created {0};

    std::string spot_name_search;
    std::string fish_name_search;

    while(status != jk::Options::Exit){

        switch(status){

            case jk::Options::Main:
                jk::stars();
                std::cout << "What would you like to do?\n";
                std::cout << "1. Add\n";
                std::cout << "2. Display\n";
                std::cout << "0. Exit\n";
                std::cin >> choice;

                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }

                else{
                    switch(choice){
                        case 1:
                            status = jk::Options::Add;
                            break;
                        case 2:
                            status = jk::Options::Display;
                            break;
                        case 0:
                            status = jk::Options::Exit;
                            break;
                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }
                break;
                

            case jk::Options::Add:
                jk::stars();
                std::cout << "What would you like to add?\n";
                std::cout << "1. Fish\n";
                std::cout << "2. Fishing spot\n";
                std::cout << "0. Go back to main menu\n";
                std::cin >> choice;

                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }

                else{
                    switch(choice){
                        case 1:
                            status = jk::Options::AddFish;
                            break;
                        case 2:
                            status = jk::Options::AddSpot;
                            break;
                        case 0:
                            status = jk::Options::Main;
                            break;
                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }

                break;

            case jk::Options::Display:
                jk::stars();
                std::cout << "What would you like to display?\n";
                std::cout << "1. Fish\n";
                std::cout << "2. Fishing spot\n";
                std::cout << "0. Go back to main menu\n";
                std::cin >> choice;

                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }
                
                else{
                    switch(choice){
                        case 1:
                            status = jk::Options::DisplayFish;
                            break;
                        case 2:
                            status = jk::Options::DisplaySpot;
                            break;
                        case 0:
                            status = jk::Options::Main;
                            break;
                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }

                break;

            case jk::Options::AddFish:
                jk::stars();
                std::cout << "Which field would you like to fill?\n";
                std::cout << "1. Species\n";
                std::cout << "2. Length\n";
                std::cout << "3. Weight\n";
                std::cout << "4. Bait\n";
                std::cout << "5. Spot\n";
                std::cout << "7. Clear all fields\n";
                std::cout << "8. Show current choices\n";
                std::cout << "9. Save choices\n";
                std::cout << "0. Go back to main menu\n";
                std::cin >> choice;
                
                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }

                else{
                    switch(choice){
                        case 1:
                            std::cout << "Insert species: ";
                            std::getline(std::cin >> std::ws, fish_global_species);
                            break;

                        case 2:
                            while(true){
                                std::cout << "Insert length [cm]: ";
                                std::cin >> fish_global_length;
                                if(!jk::checkInputType(fish_global_length)){
                                    jk::stars();
                                    std::cout << "Must be a positive number!\n";
                                    continue;
                                }
                                else{
                                    break;
                                }
                            }
                            break;

                        case 3:
                            while(true){
                                std::cout << "Insert weight [kg]: ";
                                std::cin >> fish_global_weight;
                                if(!jk::checkInputType(fish_global_weight)){
                                    jk::stars();
                                    std::cout << "Must be a positive number!\n";
                                    continue;
                                }
                                else{
                                    break;
                                }
                            }
                            break;

                        case 4:
                            std::cout << "Insert bait: ";
                            std::getline(std::cin >> std::ws, fish_global_bait);
                            break;

                        case 5:
                            std::cout << "Insert spot name: ";
                            std::getline(std::cin >> std::ws, fish_global_spot_name);
                            break;

                        case 7:
                            jk::stars();
                            std::cout << "Clearing all fields!\n";
                            fish_global_species = "";
                            fish_global_bait = "";
                            fish_global_spot_name = "";
                            fish_global_length = 0.0;
                            fish_global_weight = 0.0;
                            if(fish_object_created){
                                delete fish;
                                fish_object_created = 0;
                            }

                            break;

                        case 8:
                            jk::stars();
                            std::cout << "Current choices:\n";
                            jk::display_fish_global_choices();
                            break;

                        case 9:
                            jk::stars();
                            fish = jk::checkFishType(jk::correct(fish_global_species));
                            if(fish_global_species.empty() || fish_global_length == 0.0 || fish_global_weight == 0 || fish_global_bait.empty() || fish_global_spot_name.empty()){
                                if(!fish_global_species.empty()){
                                    fish->setSpecies(fish_global_species);
                                }
                                if(!fish_global_bait.empty()){
                                    fish->setBait(fish_global_bait);
                                }
                                if(!fish_global_spot_name.empty()){
                                    fish->setSpotName(fish_global_spot_name);
                                }
                                if(fish_global_length != 0){
                                    fish->setLength(fish_global_length);
                                }
                                if(fish_global_weight != 0){
                                    fish->setWeight(fish_global_weight);
                                }
                            }
                            jk::save_fish(fish);
                            fish_object_created = 1;
                            break;

                        case 0:
                            status = jk::Options::Main;
                            if(fish_object_created){
                                delete fish;
                                fish_object_created = 0;
                            }
                            break;

                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }

                break;

            case jk::Options::AddSpot:
                jk::stars();
                std::cout << "Which field would you like to fill?\n";
                std::cout << "1. Name\n";
                std::cout << "2. Bank type\n";
                std::cout << "3. Bottom type\n";
                std::cout << "4. Average depth\n";
                std::cout << "7. Clear all fields\n";
                std::cout << "8. Show current choices\n";
                std::cout << "9. Save choices\n";
                std::cout << "0. Go back to main menu\n";
                std::cin >> choice;
                
                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }

                else{
                    switch(choice){
                        case 1:
                            std::cout << "Insert name: ";
                            std::getline(std::cin >> std::ws, spot_global_name);
                            break;

                        case 2:
                            std::cout << "Insert bank type: ";
                            std::getline(std::cin >> std::ws, spot_global_bank_type);
                            break;

                        case 3:
                            std::cout << "Insert bottom type: ";
                            std::getline(std::cin >> std::ws, spot_global_bottom_type);
                            break;

                        case 4:
                            while(true){
                                std::cout << "Insert average depth [m]: ";
                                std::cin >> spot_global_average_depth;
                                if(!jk::checkInputType(spot_global_average_depth)){
                                    jk::stars();
                                    std::cout << "Must be a positive number!\n";
                                    continue;
                                }
                                else{
                                    break;
                                }
                            }
                            break;

                        case 7:
                            jk::stars();
                            std::cout << "Clearing all fields!\n";
                            spot_global_name = "";
                            spot_global_bank_type = "";
                            spot_global_bottom_type = "";
                            spot_global_average_depth = 0.0;
                            if(spot_object_created){
                                delete spot;
                                spot_object_created = 0;
                            }
                            break;

                        case 8:
                            jk::stars();
                            std::cout << "Current choices:\n";
                            jk::display_spot_global_choices();
                            break;

                        case 9:
                            jk::stars();
                            spot = jk::createSpot();
                            if(spot_global_name.empty() || spot_global_bank_type.empty() || spot_global_bottom_type.empty() || spot_global_average_depth == 0.0){
                                if(!spot_global_name.empty()){
                                    spot->setName(spot_global_name);
                                }
                                else{
                                    jk::stars();
                                    std::cout << "Spot must have a name!\nSaving FAILED!\n";
                                    delete spot;
                                    spot_object_created = 0;
                                    break;
                                }
                                if(!spot_global_bank_type.empty()){
                                    spot->setBankType(spot_global_bank_type);
                                }
                                if(!spot_global_bottom_type.empty()){
                                    spot->setBottomType(spot_global_bottom_type);
                                }
                                if(spot_global_average_depth!=0){
                                    spot->setDepth(spot_global_average_depth);
                                }
                            }
                            
                            jk::save_spot(spot);
                            spot_object_created = 1;

                            break;

                        case 0:
                            status = jk::Options::Main;
                            if(spot_object_created){
                                delete spot;
                                spot_object_created = 0;
                            }
                            break;

                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }

                break;
            
            case jk::Options::DisplayFish:
                jk::stars();
                std::cout << "What do you want to do?\n";
                std::cout << "1. Search for fish by name\n";
                std::cout << "2. Display fish list\n";
                std::cout << "3. Remove fish\n";
                std::cout << "0. Go back to main menu\n";
                std::cin >> choice;
                
                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }

                else{
                    switch(choice){
                        case 1:
                            jk::stars();
                            std::cout << "Insert name of desired fish\n";
                            std::getline(std::cin >> std::ws, fish_name_search);
                            jk::load_fish(fish_name_search);

                            break;
                        
                        case 2:
                            jk::stars();
                            std::cout << "List of known fish:\n";
                            jk::load_fish_list();
                            break;
                        
                        case 3:
                            jk::stars();
                            std::cout << "Insert name of fish that you want to remove:\n";
                            std::getline(std::cin >> std::ws, fish_name_search);
                            jk::remove_fish(fish_name_search);
                            break;

                        case 0:
                            status = jk::Options::Main;
                            break;

                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }

                break;

            case jk::Options::DisplaySpot:
                jk::stars();
                std::cout << "What do you want to do?\n";
                std::cout << "1. Search for spot by name\n";
                std::cout << "2. Display spots list\n";
                std::cout << "3. Remove spot\n";
                std::cout << "0. Go back to main menu\n";
                std::cin >> choice;
                
                if(!jk::checkInputType()){
                    jk::stars();
                    std::cout << "Invalid input\n";
                    break;
                }

                else{
                    switch(choice){
                        case 1:
                            jk::stars();
                            std::cout << "Insert name of desired spot:\n";
                            std::getline(std::cin >> std::ws, spot_name_search);
                            jk::load_spot(spot_name_search);

                            break;
                        
                        case 2:
                            jk::stars();
                            std::cout << "List of known spots:\n";
                            jk::load_spot_list();
                            break;

                        case 3:
                            jk::stars();
                            std::cout << "Insert name of spot that you want to remove:\n";
                            std::getline(std::cin >> std::ws, spot_name_search);
                            jk::remove_spot(spot_name_search);
                            break;

                        case 0:
                            status = jk::Options::Main;
                            break;

                        default:
                            jk::stars();
                            std::cout << "Neither option selected!\n";
                            break;
                    }
                }

                break;
        }
    }
}