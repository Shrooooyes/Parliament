#ifndef BILL_H
#define BILL_H

#include <string>

class Bill {
private:
    std::string billId;
    std::string title;
    std::string descp;
    bool loksabhaPass = false;
    bool rajyaSabhaPass = false;

public:
    Bill(){
        this->billId="";
    }

    Bill(const std::string& billId, const std::string& title, const std::string& descp)
        : billId(billId), title(title), descp(descp) {}

    void billLokSabha(bool loksabhaPass) {
        this->loksabhaPass = loksabhaPass;
    }

    void billRajyaSabha(bool rajyasabhaPass) {
        this->rajyaSabhaPass = rajyasabhaPass;
    }

    bool billCanBePassed() const {
        return loksabhaPass && rajyaSabhaPass;
    }

    std::string getBillId() const {
        return billId;
    }

    std::string getBill() const {
        return billId + "\n" + title + "\n" + descp;
    }
};

#endif // BILL_H