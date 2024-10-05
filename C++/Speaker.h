#ifndef SPEAKER_H
#define SPEAKER_H

#include "MemberOfParliament.h"

class Speaker: public MemberOfParliament{
public:
    Speaker():MemberOfParliament("",""){}

    Speaker(const std::string& Name, const std::string& Party)
        : MemberOfParliament(Name, Party){}
};

#endif // !SPEAKER_H