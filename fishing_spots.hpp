#pragma once
#include <iostream>
#include <string>
#include "corrector.hpp"
std::string spot_global_name;
std::string spot_global_bank_type;
std::string spot_global_bottom_type;
double spot_global_average_depth;
namespace jk{

class Fishing_spot{
private:

    double m_average_depth;
    std::string m_name;
    std::string m_bank_type;
    std::string m_bottom_type;

public:

    Fishing_spot(){
        m_name = "";
        m_bank_type = "";
        m_bottom_type = "";
        m_average_depth = 0.0;
    }

    Fishing_spot(std::string name, std::string bank, std::string bottom, double depth): m_name(correct(name)), m_bank_type(correct(bank)), m_bottom_type(correct(bottom)){

        if(depth>0){
            m_average_depth = depth;
        }

        else{
            throw std::invalid_argument("Depth must be greater than 0!\n");
        }
    }

    ~Fishing_spot(){}

    void setName(std::string name){
        if(!(name.empty())){
            m_name = correct(name);
        }

        else{
            throw std::invalid_argument("Spot name can't be empty!\n");
        }
    }

    void setBankType(std::string bank){
        if(!(bank.empty())){
            m_bank_type = correct(bank);
        }

        else{
            throw std::invalid_argument("Bank type can't be empty!\n");
        }
    }

    void setBottomType(std::string bottom){
        if(!(bottom.empty())){
            m_bottom_type = correct(bottom);
        }

        else{
            throw std::invalid_argument("Bottom type can't be empty!\n");
        }
    }

    void setDepth(double depth){
        if(depth>0){
            m_average_depth = depth;
        }

        else{
            throw std::invalid_argument("Depth must be greater than 0!\n");
        }
    }

    std::string getName() const{
        return m_name;
    }

    std::string getBankType() const{
        return m_bank_type;
    }

    std::string getBottomType() const{
        return m_bottom_type;
    }

    double getDepth() const{
        return m_average_depth;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fishing_spot& spot) {
        os << spot.m_name;
        return os;
    }
};

jk::Fishing_spot* createSpot(){
    if(!spot_global_name.empty() && !spot_global_bank_type.empty() && !spot_global_bottom_type.empty() && spot_global_average_depth !=0.0){
        return new Fishing_spot(spot_global_name, spot_global_bank_type, spot_global_bottom_type, spot_global_average_depth);
    }
    else{
        return new Fishing_spot();
    }
}

void display_spot_global_choices(){
    std::cout << "Name: " << correct(spot_global_name) << std::endl;
    std::cout << "Bank type: " << correct(spot_global_bank_type) << std::endl;
    std::cout << "Bottom type: " << correct(spot_global_bottom_type) << std::endl;
    std::cout << "Average depth: " << spot_global_average_depth << "m" << std::endl;
}

}