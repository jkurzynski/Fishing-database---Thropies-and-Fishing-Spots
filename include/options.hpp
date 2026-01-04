namespace jk{
enum class Options{
    Main, Add, Display, AddFish, AddSpot, DisplayFish, DisplaySpot, Exit
};
/**
 * The class containing possible choices of menus, making moving between them less confusing to code.
 */

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
/**
 * Functions' checkInputType purposes are to check if there're no errors in the input given by user.
 * Difference between them is that the one with type double argument is used as verification of
 * numbers on which user has free will to decide whatever they will be ex. fish's length and weight, spot's depth.
 * The other one is just to make sure that the choice of option is a number, not ex. string. The negative numbers are
 * canceled by default case in switch.
 */
}