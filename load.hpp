#include "fish.hpp"

namespace jk{
void load_spot(std::string& spot){
    spot = correct(spot);
    std::ifstream jsonIn("./fishing_spots.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);

    if(jsonData.contains(spot)){
        std::cout << "Loading: " << spot << std::endl << std::endl;

        std::cout << "Spot name: " << spot << std::endl;
        std::cout << "Bank type: " << jsonData[spot]["Bank type"].get<std::string>() << std::endl;
        std::cout << "Bottom type: " << jsonData[spot]["Bottom type"].get<std::string>() << std::endl;
        std::cout << "Average depth: " << jsonData[spot]["Average depth"].get<double>() << "m" << std::endl;
    }

    else{
        std::cout << "Spot named "<< spot << " isn't on the list!\n";
    }
}

void load_spot_list(){
    std::ifstream jsonIn("./fishing_spots.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);
    int just_a_number_for_visual_effect {1};
    for(const auto& i : jsonData.items()){
        std::cout << just_a_number_for_visual_effect << ". " << i.key() << std::endl;
        just_a_number_for_visual_effect++;
    }
}

void load_fish(std::string& fish){
    fish = correct(fish);
    std::ifstream jsonIn("./fish.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);

    if(jsonData.contains(fish)){
        std::cout << "Loading: " << fish << std::endl << std::endl;

        std::cout << "Species: " << jsonData[fish]["Species"].get<std::string>() << std::endl;
        std::cout << "Length: " << jsonData[fish]["Length"].get<double>() << "cm" << std::endl;
        std::cout << "Weight: " << jsonData[fish]["Weight"].get<double>() << "kg" << std::endl;
        std::cout << "Type: " << jsonData[fish]["Type"].get<std::string>() << std::endl;
        std::cout << "Bait: " << jsonData[fish]["Bait"].get<std::string>() << std::endl;
        std::cout << "Spot: " << jsonData[fish]["Spot name"].get<std::string>() << std::endl;
    }

    else{
        std::cout << "Fish named "<< fish << " isn't on the list!\n";
    }
}

void load_fish_list(){
    std::ifstream jsonIn("./fish.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);
    int just_a_number_for_visual_effect {1};
    for(const auto& i : jsonData.items()){
        std::cout << just_a_number_for_visual_effect << ". " << i.key() << std::endl;
        just_a_number_for_visual_effect++;
    }
}

void stars(){
    std::cout <<"**********\n";
}

}