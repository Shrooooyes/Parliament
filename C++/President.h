// #ifndef PRESIDENT_H
// #define PRESIDENT_H

#include <string>
#include <iostream>

#include "Bill.h"

class President{
private:
    std::string Name;

public:
    President(std::string Name){
        this->Name = Name;
    }

    bool makeLaw(Bill bill){
        while (true){
            std::cout << "Does President want to sign the bill? (yes/no)";
            std::string answer;
            std::cin >> answer;
            if (answer == "yes"){
                std::cout << "Bill: "<< bill.getBill() << " made to law..." << std::endl;
                return true;
            }
            else if (answer == "no"){
                std::cout << "Bill: "<< bill.getBill() << " rejected..." << std::endl;
                return false;
            }
            else{
                std::cout << "Invalid input.." << std::endl;
            }
        }
    }

    std::string getName(){
        return this-> Name;
    }

};

// #endif // !PRESIDENT_H