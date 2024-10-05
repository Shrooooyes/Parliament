#ifndef RAJYASABHA_H
#define RAJYASABHA_H

#include <vector> 
#include <iostream>
#include "Chairman.h"
#include "MemberOfParliament.h"
#include "Bill.h"

class RajyaSabha{
private:
    Chairman chairman;
    std::vector<MemberOfParliament> members;

public:
    RajyaSabha(){
        this->chairman = Chairman();
    }

    RajyaSabha(Chairman chairman){
        this->chairman = chairman;
        std::cout << "Rajya Sabha created..." << std::endl;
    }

    void passBill(Bill bill) {
        std::cout << "Rajya Sabha is passing bill..." << std::endl;
    }

    void addMembers(MemberOfParliament member){
        if(members.size()<543){
            members.push_back(member);
            std::cout << member.getMPDetails() <<" added to Lok Sabha..." << std::endl;
        }
        else{
            std::cout << "Lok Sabha is full..." << std::endl;
        }
    }

    std::string getChairman(){
        std::string sp = this->chairman.getMPDetails();
        return sp;
    } 

    std::vector<MemberOfParliament> getMPsRajyaSabha(){
        return this->members;
    }
};

#endif // !RAJYASABHA_H