#ifndef PARLIAMENT_H

#define PARLIAMENT_H

#include <iostream>
#include <string>
#include <vector>

#include "President.h"
#include "LokSabha.h"
#include "RajyaSabha.h"

class Parliament {
public:
    LokSabha loksabha;
    RajyaSabha rajyasabha;
    President president;
    std::vector<Bill> bills;

public:
    Parliament() : president(""){
        std::cout << "Parliament Opened" << std::endl;
    }

    void createLoksabha() {
        std::cout << "Enter Speaker's name: ";
        std::string speakerName;
        std::cin.ignore();
        std::getline(std::cin, speakerName);
        std::cout << "Enter Speaker's party: ";
        std::string speakerParty;
        std::getline(std::cin, speakerParty);

        loksabha = LokSabha(Speaker(speakerName, speakerParty));
    }

    void createRajyasabha() {
        std::cout << "Enter Chairman's name: ";
        std::string chairmanName;
        std::cin.ignore();
        std::getline(std::cin, chairmanName);
        std::cout << "Enter Chairman's party: ";
        std::string chairmanParty;
        std::getline(std::cin, chairmanParty);

        rajyasabha = RajyaSabha(Chairman(chairmanName, chairmanParty));
    }

    void electPresident() {
        std::cout << "Enter President's name: ";
        std::string presidentName;
        std::cin.ignore();
        std::getline(std::cin, presidentName);

        president = President(presidentName);
    }

    void addLoksabhaMembers() {
        std::cout << "Enter Member's name: ";
        std::string memberName;
        std::cin.ignore();
        std::getline(std::cin, memberName);
        std::cout << "Enter Member's party: ";
        std::string memberParty;
        std::getline(std::cin, memberParty);

        MemberOfParliament member(memberName, memberParty);
        loksabha.addMembers(member);
    }

    void addRajyasabhaMembers() {
        std::cout << "Enter Member's name: ";
        std::string memberName;
        std::cin.ignore();
        std::getline(std::cin, memberName);
        std::cout << "Enter Member's party: ";
        std::string memberParty;
        std::getline(std::cin, memberParty);

        MemberOfParliament member(memberName, memberParty);
        rajyasabha.addMembers(member);
    }

    void passBillByLoksabha() {
        std::string billId, billTitle, billDescp;
        std::cout << "Enter Bill ID: ";
        std::cin.ignore();
        std::getline(std::cin, billId);
        std::cout << "Enter Bill Title: ";
        std::getline(std::cin, billTitle);
        std::cout << "Enter Bill Description: ";
        std::getline(std::cin, billDescp);

        Bill bill(billId, billTitle, billDescp);
        bill.billLokSabha(true);

        if (bills.size() < 50) {
            bills.push_back(bill);
            loksabha.passBill(bill);

            while (true) {
                std::string answer;
                std::cout << "Does Rajya Sabha want to pass the bill? (yes/no): ";
                std::cin >> answer;

                if (answer == "yes") {
                    std::cout << "Bill: " << bill.getBill() << " passed by both houses..." << std::endl;
                    bill.billRajyaSabha(true);
                    break;
                } else if (answer == "no") {
                    std::cout << "Rajya Sabha doesn't want to pass the bill..." << std::endl;
                    bill.billRajyaSabha(false);
                    break;
                } else {
                    std::cout << "Invalid input.." << std::endl;
                }
            }
        } else {
            std::cout << "50 bills are pending..." << std::endl;
        }
    }

    void passBillByRajyasabha() {
        std::string billId, billTitle, billDescp;
        std::cout << "Enter Bill ID: ";
        std::cin.ignore();
        std::getline(std::cin, billId);
        std::cout << "Enter Bill Title: ";
        std::getline(std::cin, billTitle);
        std::cout << "Enter Bill Description: ";
        std::getline(std::cin, billDescp);

        Bill bill(billId, billTitle, billDescp);
        bill.billRajyaSabha(true);

        if (bills.size() < 50) {
            bills.push_back(bill);
            rajyasabha.passBill(bill);

            while (true) {
                std::string answer;
                std::cout << "Does Lok Sabha want to pass the bill? (yes/no): ";
                std::cin >> answer;

                if (answer == "yes") {
                    std::cout << "Bill: " << bill.getBill() << " passed by both houses..." << std::endl;
                    bill.billLokSabha(true);
                    break;
                } else if (answer == "no") {
                    std::cout << "Lok Sabha doesn't want to pass the bill..." << std::endl;
                    bill.billLokSabha(false);
                    break;
                } else {
                    std::cout << "Invalid input.." << std::endl;
                }
            }
        } else {
            std::cout << "50 bills are pending..." << std::endl;
        }
    }

    void presidentPassBill() {
        std::string billId;
        std::cout << "Enter Bill ID: ";
        std::cin.ignore();
        std::getline(std::cin, billId);

        Bill thisBill;
        for (const auto& bill : bills) {
            if (bill.getBillId() == billId) {
                thisBill = bill;
                break;
            }
        }

        if (thisBill.getBillId() != "") {
            if (thisBill.billCanBePassed()) {
                president.makeLaw(thisBill);
            } else {
                std::cout << "Bill cannot be passed..." << std::endl;
            }
        } else {
            std::cout << "Bill not found.." << std::endl;
        }
    }

    void displayLoksabha() {
        std::cout << "Lok Sabha" << std::endl;
        std::cout << "Speaker: " << loksabha.getSpeaker() << std::endl;

        std::cout << "Members of Lok Sabha:" << std::endl;
        auto members = loksabha.getMPsLokSabha();

        int i = 0;
        for (const auto& member : members) {
            std::cout << i << ". " << member.getMPDetails() << std::endl;
            i++;
        }
    }

    void displayRajyasabha() {
        std::cout << "Rajya Sabha" << std::endl;
        std::cout << "Chairman: " << rajyasabha.getChairman() << std::endl;

        std::cout << "Members of Rajya Sabha:" << std::endl;
        auto members = rajyasabha.getMPsRajyaSabha();

        int i = 0;
        for (const auto& member : members) {
            std::cout << i << ". " << member.getMPDetails() << std::endl;
            i++;
        }
    }

    void displayPresident() {
        std::cout << "President: " << president.getName() << std::endl;
    }

    void displayBills() {
        std::cout << "Bills: " << std::endl;
        for (const auto& bill : bills) {
            std::cout << bill.getBill() << std::endl;
        }
    }
};

#endif // !PARLIAMENT_H
