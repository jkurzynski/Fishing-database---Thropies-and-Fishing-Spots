#include "fish.hpp"

namespace jk{
void save_spot(jk::Fishing_spot* spot){
    std::cout << "Saving: " << spot->getName() << std::endl;

    std::ifstream jsonIn("./jsonFiles/fishing_spots.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);

    jsonData[spot->getName()] = { {"Bank type", spot->getBankType()}, {"Bottom type", spot->getBottomType()}, {"Average depth", spot->getDepth()}};

    std::ofstream jsonOut("./jsonFiles/fishing_spots.json");
    jsonOut << std::setw(4) << jsonData;
}
/**
 * Function allows to add new or overwrite already existing fishing spots. It reads whole file to
 * keep already existing objects intact and (if needed) find object to overwrite.
 */

void remove_spot(std::string& spot){
    spot = correct(spot);
    std::ifstream jsonIn("./jsonFiles/fishing_spots.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);
    int fate_of_the_saving {1};
    if(jsonData.contains(spot)){
        std::cout << "Do you realy want to remove: " << spot << "?" <<std::endl << std::endl;
        std::cout << "1. No\n";
        std::cout << "2. Yes\n";
        std::cin >> fate_of_the_saving;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input\n";
        }
        else{
            switch(fate_of_the_saving){
                case 1:
                    std::cout << spot << " has NOT been removed\n";
                    break;
                case 2:
                    jsonData.erase(spot);
                    std::cout << "Done... Don't think about it... It's easier this way...\n";
                    break;
                default:
                    std::cout << "Neither option selected!\n";
                    break;
            }
        }
    }

    else{
        std::cout << "Spot named "<< spot << " isn't on the list!\n";
    }

    std::ofstream jsonOut("./jsonFiles/fishing_spots.json");
    jsonOut << std::setw(4) << jsonData;
}
/**
 * Function allows the removal of already existing fishing spots. It reads the whole file to check if the object
 * exists, and if it does, function requires second confirmation before removing the found object.
 */

void save_fish(jk::Fish* fish){
    std::string trophy_name;
    std::cout << "How do you want to name this trophy?\n";
    std::getline(std::cin >> std::ws, trophy_name);
    trophy_name = correct(trophy_name);

    
    std::cout << "Saving: " << trophy_name << std::endl;

    std::ifstream jsonIn("./jsonFiles/fish.json");
    std::ifstream jsonSpot("./jsonFiles/fishing_spots.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);
    nlohmann::json jsonDataSpot = nlohmann::json::parse(jsonSpot);

    if(!(jsonDataSpot.contains(fish->getSpotName()))){
        std::cout << "Spot hasn't been found.\nAdding " << fish->getSpotName() << " to the list\n";
        jk::Fishing_spot spot;
        spot.setName(fish->getSpotName());
        save_spot(&spot);
    }

    jsonData[trophy_name] = {{"Type", fish->getFishType()}, {"Length", fish->getLength()}, {"Weight", fish->getWeight()}, {"Bait", fish->getBait()}, {"Spot name", fish->getSpotName()}, {"Species", fish->getSpecies()}};

    std::ofstream jsonOut("./jsonFiles/fish.json");
    jsonOut << std::setw(4) << jsonData;
}
/**
 * Function allows to add new or overwrite already existing fish. It reads whole file to
 * keep already existing objects intact and (if needed) find object to overwrite.
 * If given fish's spot was previously unknown, the function will inform about it and create empty spot object
 * so user can fill it's fields later.
 */

void remove_fish(std::string& fish){
    fish = correct(fish);
    std::ifstream jsonIn("./jsonFiles/fish.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);
    int fate_of_the_saving {1};
    if(jsonData.contains(fish)){
        std::cout << "Do you realy want to remove: " << fish << "?" <<std::endl << std::endl;
        std::cout << "1. No\n";
        std::cout << "2. Yes\n";
        std::cin >> fate_of_the_saving;
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input\n";
        }
        else{
            switch(fate_of_the_saving){
                case 1:
                    std::cout << fish << " has NOT been removed\n";
                    break;
                case 2:
                    jsonData.erase(fish);
                    std::cout << "Done... Don't think about it... It's easier this way...\n";
                    break;
                default:
                    std::cout << "Neither option selected!\n";
                    break;
            }
        }
    }

    else{
        std::cout << "Fish named "<< fish << " isn't on the list!\n";
    }

    std::ofstream jsonOut("./jsonFiles/fish.json");
    jsonOut << std::setw(4) << jsonData;
}
/**
 * Function allows the removal of already existing fish. It reads the whole file to check if the object
 * exists, and if it does, function requires second confirmation before removing the found object.
 */
}