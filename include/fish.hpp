#pragma once
#include <fstream>
#include "json.hpp"
#include "fishing_spots.hpp"
std::string fish_global_species;
double fish_global_length;
double fish_global_weight;
std::string fish_global_bait;
std::string fish_global_spot_name;

namespace jk{

class Fish{
protected:
    double m_length {0};
    double m_weight {0};
    std::string m_species {};
    std::string m_bait {};
    jk::Fishing_spot m_spot {};
public:
    Fish(){
        m_species = "";
        m_bait = "";
        m_length = 0.0;
        m_weight = 0.0;
    }

    Fish(std::string name, double length, double weight, std::string bait, std::string spot_name) : m_species(correct(name)), m_bait(correct(bait)){

        m_spot.setName(correct(spot_name));

        if(length > 0){
            m_length = length;
        }

        else{
            throw std::invalid_argument("Length must be greater than 0!\n");
        }

        if(weight > 0){
            m_weight = weight;
        }

        else{
            throw std::invalid_argument("Weight must be greater than 0!\n");
        }
    }
    ///Depending on whether user filled every fish's attribute. The different constructors are used.

    virtual std::string getFishType() = 0;
    virtual ~Fish(){}
    ///Virtual destructor and function because there are derived classes.

    void setSpecies(std::string name){
        if(!(name.empty())){
            m_species = correct(name);
        }

        else{
            throw std::invalid_argument("Species can't be empty!\n");
        }
    }

    void setLength(double length){
        if(length > 0){
            m_length = length;
        }

        else{
            throw std::invalid_argument("Length must be greater than 0!\n");
        }
    }

    void setWeight(double weight){
        if(weight > 0){
            m_weight = weight;
        }

        else{
            throw std::invalid_argument("Weight must be greater than 0!\n");
        }
    }

    void setBait(std::string bait){
        if(!(bait.empty())){
            m_bait = correct(bait);
        }

        else{
            throw std::invalid_argument("Bait can't be empty!\n");
        }
    }

    void setSpotName(std::string spot_name){
        if(!(spot_name.empty())){
            m_spot.setName(correct(spot_name));
        }

        else{
            throw std::invalid_argument("Spot name can't be empty!\n");
        }
    }

    std::string getSpecies() const{
        return m_species;
    }

    double getLength() const{
        return m_length;
    }

    double getWeight() const{
        return m_weight;
    }

    std::string getBait() const{
        return m_bait;
    }

    std::string getSpotName() const{
        return m_spot.getName();
    }
};

class Predatory : public Fish{
private:
    std::string m_fish_type {};
public:
    Predatory() : Fish(){
        m_fish_type = "Predatory";
    }
    Predatory(std::string name, double length, double weight, std::string fish_type, std::string bait, std::string spot_name) : Fish(name, length, weight, bait, spot_name), m_fish_type(fish_type){}
    
    std::string getFishType() override{
        return m_fish_type;
    }

    ~Predatory(){}
};
///Derived class, reserved for predatory fish. It adds fish type.

class Coarse : public Fish{
private:
    std::string m_fish_type {};
public:
    Coarse() : Fish(){
        m_fish_type = "Coarse";
    }
    Coarse(std::string name, double length, double weight, std::string fish_type, std::string bait, std::string spot_name) : Fish(name, length, weight, bait, spot_name), m_fish_type(fish_type){}
    
    std::string getFishType() override{
        return m_fish_type;
    }


    ~Coarse(){}
};
///Derived class, reserved for coarse fish. It adds fish type.

jk::Fish* checkFishType(const std::string& name){
    std::ifstream jsonIn("./jsonFiles/fish_types.json");
    nlohmann::json jsonData = nlohmann::json::parse(jsonIn);

    for(const auto& fish : jsonData["Predatory fish"]){
        if(fish == name){
            if(!fish_global_species.empty() && fish_global_length != 0.0 && fish_global_weight != 0.0 && !fish_global_bait.empty() && !fish_global_spot_name.empty()){
                return new Predatory(fish_global_species, fish_global_length, fish_global_weight, "Predatory", fish_global_bait, fish_global_spot_name);
            }
            else{
                return new Predatory();
            }
        }
    }
   
    for(const auto& fish : jsonData["Coarse fish"]){
        if(fish == name){
            if(!fish_global_species.empty() && fish_global_length != 0.0 && fish_global_weight != 0.0 && !fish_global_bait.empty() && !fish_global_spot_name.empty()){
                return new Coarse(fish_global_species, fish_global_length, fish_global_weight, "Coarse", fish_global_bait, fish_global_spot_name);
            }
            else{
                return new Coarse();
            }
        }
    }
    
    throw std::invalid_argument("Fish not found\n");
    
}
/**
 * Function allows automatic detection of the fish type (predatory or coarse), based on its species.
 * Species are stored in separate json file.
 * Function also checks whether every attribute has been filled, then creates new object using either
 * default or parametrized constructor.
 */

void display_fish_global_choices(){
    std::cout << "Species: " << correct(fish_global_species) << std::endl;
    std::cout << "Length: " << fish_global_length << "cm" << std::endl;
    std::cout << "Weight: " << fish_global_weight << "kg" << std::endl;
    std::cout << "Bait: " << correct(fish_global_bait) << std::endl;
    std::cout << "Spot: " << correct(fish_global_spot_name) << std::endl;
}
/**
 * Function displays attributes of the fish. It isn't connected with object creation on purpose.
 * By that, any changes won't affect the object, unless they are saved with save_fish() function.
 */
}
