#ifndef MEMBEROFPARLIAMENT_H
#define MEMBEROFPARLIAMENT_H

#include <string>

class MemberOfParliament {
private:
    std::string Name;
    std::string Party;

public:
    MemberOfParliament(std::string Name, std::string Party){
        this->Name = Name;
        this->Party = Party;
    }

    std::string getMPDetails() const {
        return "Name: " + Name + "\n  Party: " + Party;
    }
};

#endif 