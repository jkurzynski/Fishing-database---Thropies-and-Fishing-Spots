namespace jk{
enum class Options{
    Main, Add, Display, AddFish, AddSpot, DisplayFish, DisplaySpot, Exit
};

bool checkInputType(){
    if(!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool checkInputType(double value_to_verify){
    if(!std::cin || value_to_verify <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}
}