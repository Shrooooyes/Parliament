#include <iostream>
#include <string>

#include "Parliament.h"


int main() {
    Parliament parliament;
    int input;

    do {
        std::cout << "\n\nEnter Option" << std::endl;
        std::cout << "1. Create Lok Sabha" << std::endl;
        std::cout << "2. Create Rajya Sabha" << std::endl;
        std::cout << "3. Elect President" << std::endl;
        std::cout << "4. Add Lok Sabha members" << std::endl;
        std::cout << "5. Add Rajya Sabha members" << std::endl;
        std::cout << "6. Pass bill by Lok Sabha" << std::endl;
        std::cout << "7. Pass bill by Rajya Sabha" << std::endl;
        std::cout << "8. Pass Bill to Law by President" << std::endl;
        std::cout << "9. Display Lok Sabha" << std::endl;
        std::cout << "10. Display Rajya Sabha" << std::endl;
        std::cout << "11. Display President" << std::endl;
        std::cout << "12. Display Bills" << std::endl;
        std::cout << "13. Exit" << std::endl;

        std::cout << "\n\nEnter Your Choice: ";
        std::cin >> input;

        if (input == 13) {
            std::cout << "Thank you for using the Parliament System";
            break;
        }

        switch (input) {
            case 1:
                parliament.createLoksabha();
                break;
            case 2:
                parliament.createRajyasabha();
                break;
            case 3:
                parliament.electPresident();
                break;
            case 4:
                if (!parliament.loksabha.getSpeaker().empty()) {
                    parliament.addLoksabhaMembers();
                } else {
                    std::cout << "Create Lok Sabha to add members...";
                }
                break;
            case 5:
                if (!parliament.rajyasabha.getChairman().empty()) {
                    parliament.addRajyasabhaMembers();
                } else {
                    std::cout << "Create Rajya Sabha to add members...";
                }
                break;
            case 6:
                if (!parliament.loksabha.getSpeaker().empty()) {
                    parliament.passBillByLoksabha();
                } else {
                    std::cout << "Create Lok Sabha to pass bill...";
                }
                break;
            case 7:
                if (!parliament.rajyasabha.getChairman().empty()) {
                    parliament.passBillByRajyasabha();
                } else {
                    std::cout << "Create Rajya Sabha to pass bill...";
                }
                break;
            case 8:
                if (!parliament.loksabha.getSpeaker().empty() && !parliament.rajyasabha.getChairman().empty() && !parliament.bills.empty()) {
                    parliament.presidentPassBill();
                } else {
                    std::cout << "Legislative bodies not properly defined...";
                }
                break;
            case 9:
                if (!parliament.loksabha.getSpeaker().empty()) {
                    parliament.displayLoksabha();
                } else {
                    std::cout << "Create Lok Sabha...";
                }
                break;
            case 10:
                if (!parliament.rajyasabha.getChairman().empty()) {
                    parliament.displayRajyasabha();
                } else {
                    std::cout << "Create Rajya Sabha...";
                }
                break;
            case 11:
                if (!parliament.president.getName().empty()) {
                    parliament.displayPresident();
                } else {
                    std::cout << "Elect President...";
                }
                break;
            case 12:
                if (parliament.bills.empty()) {
                    std::cout << "No bills to display...";
                } else {
                    parliament.displayBills();
                }
                break;
            default:
                std::cout << "Invalid input";
                break;
        }

    } while (input != 13);

    return 0;
}