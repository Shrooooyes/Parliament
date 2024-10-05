#ifndef CHAIRMAN_H
#define CHAIRMAN_H

#include "MemberOfParliament.h"

class Chairman : public MemberOfParliament {
public:
    Chairman():MemberOfParliament("",""){}

    Chairman(const std::string& Name, const std::string& Party)
        : MemberOfParliament(Name, Party) {}
};

#endif 