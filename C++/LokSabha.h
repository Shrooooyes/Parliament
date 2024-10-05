#ifndef LOKSABHA_H
#define LOKSABHA_H

#include <iostream>
#include <vector>
#include "Speaker.h"
#include "MemberOfParliament.h"
#include "Bill.h"

class LokSabha{
private:
    Speaker speaker;
    std::vector<MemberOfParliament> members;

public:
    LokSabha(){
        this->speaker = Speaker();
    }

    LokSabha(Speaker speaker){
        this->speaker = speaker;
        std::cout << "Lok Sabha created..." << std::endl;
    }

    void passBill (Bill bill){
        std::cout << "lok Sabha is passing bill: " << bill.getBill() << std::endl;
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

    std::string getSpeaker(){
        std::string sp = this->speaker.getMPDetails();
        return sp;
    } 

    std::vector<MemberOfParliament> getMPsLokSabha(){
        return this->members;
    }

};

#endif // !LOKSABHA_H