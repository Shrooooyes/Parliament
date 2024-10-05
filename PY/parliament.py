# Parliament
# imprts
from bill import Bill
from chairman import Chairman
from loksabha import LokSabha
from member_of_parliament import Member_Of_Parliament
from president import President
from rajyasabha import RajyaSabha
from speaker import Speaker


# vars
loksabha = None
rajyasabha = None
president = None
bills = []


def create_lok_sabha():
    speaker_name = input("Enter Speaker name: ")
    speaker_party = input("Enter Speaker party: ")
    
    globals()['loksabha'] = LokSabha(Speaker(speaker_name,speaker_party))    

def create_rajya_sabha():
    chairman_name = input("Enter Chairman name: ")
    chairman_party = input("Enter Chairman party: ")
    
    globals()['rajyasabha'] = RajyaSabha(Chairman(chairman_name,chairman_party))

def elect_president():
    president_name = input("Enter President name: ")
    
    globals()['president'] = President(president_name)

def add_lok_sabha_member():
    member_name = input("Enter Member Name: ")
    member_party = input("Enter Member Party: ")
    
    globals()['loksabha'].add_members(Member_Of_Parliament(member_name, member_party))

def add_rajya_sabha_member():
    member_name = input("Enter Member Name: ")
    member_party = input("Enter Member Party: ")
    
    globals()['rajyasabha'].add_members(Member_Of_Parliament(member_name, member_party))

def loksabha_pass_bill():
    bill_id = input("Enter Bill ID: ")
    bill_title = input("Enter Bill Title: ")
    bill_descp = input("Enter Description: ")
    
    bill = Bill(bill_id, bill_title, bill_descp)
    bill.bill_loksabha(True)
    
    # Edit Here
    if len(bills)<50:
        globals()['loksabha'].pass_bill(bill)
        
        while True:
            pass_law = input("Does Rajya Sabha want to pass the bill? (yes/no)").lower()
            if pass_law == "yes":
                print(f"Bill: \n{bill_title}\npassed by both the parties")
                bill.bill_rajyasabha(True)
                break
            elif pass_law == "no":
                print("\nRajya sabha doesnt want to pass the bill..\n")
                bill.bill_rajyasabha(False)
                break
            else:
                print("\nInvalid input..\n")
        
        bills.append(bill)
    
    else:
        print("\n50 bills are pending..\n")
        
def rajya_pass_bill():
    bill_id = input("Enter Bill ID: ")
    bill_title = input("Enter Bill Title: ")
    bill_descp = input("Enter Description: ")
    
    bill = Bill(bill_id, bill_title, bill_descp)
    bill.bill_rajyasabha(True)
    
    # Edit Here
    if len(bills)<50:
        globals()['rajyasabha'].pass_bill(bill)
        
        while True:
            pass_law = input("Does Lok Sabha want to pass the bill? (yes/no)").lower()
            if pass_law == "yes":
                print(f"Bill: \n{bill_title}\npassed by both the parties")
                bill.bill_loksabha(True)
                break
            elif pass_law == "no":
                print("\Lok sabha doesnt want to pass the bill..\n")
                bill.bill_loksabha(False)
                break
            else:
                print("\nInvalid input..\n")
        
        bills.append(bill)
    
    else:
        print("\n50 bills are pending..\n")

def president_pass_bill():
    bill_id = input("Enter Bill ID: ")
    this_bill = None
    
    for bill in bills:
        if bill.bill_id == bill_id:
            this_bill = bill
            break
        
    if this_bill is not None:
        if this_bill.bill_can_be_passed:
            globals()['president'].make_law(this_bill)
        else:
            print("\nBill cannot be passed..\n")
            
    else:
        print("\nBill not found..\n")
        
def display_lok_sabha():
    print("\nLok Sabha:\n")
    print(f"Speaker: {globals()['loksabha'].get_speaker()}\n")
    
    print("Members of Lok Sabha:\n")
    for i in loksabha.members:
        print(f"{i.get_mp_details()} \n")
        
def display_rajya_sabha():
    print("\nRajya Sabha:\n")
    print(f"Chairman: {globals()['rajyasabha'].get_chairman()}\n")
    
    print("Members of Rajya Sabha:\n")
    for i in rajyasabha.members:
        print(f"{i.get_mp_details()} \n")
        
def display_president():
    print(f"\nPresident: {globals()['president'].get_name()}\n")

def display_bills():
    print("\nBills:\n")
    for i in bills:
        print(f"{i.get_bill()} \n")

# MAIN
print("Welcome to the Parliament of India!")

input_u = None

while(input_u != 13):
    print("\n\nEnter Option")
    print("1. Create Lok Sabha")
    print("2. Create Rajya Sabha")
    print("3. Elect President")
    print("4. Add Loksabha members")
    print("5. Add Rajyasabha members")

    print("6. Pass bill by loksabha")
    print("7. Pass bill by rajyasabha")
    print("8. Pass Bill to Law by president")

    print("9. Display Lok Sabha")
    print("10. Display Rajya Sabha")
    print("11. Display President")
    print("12. Display Bills")
    print("13. Exit")
    
    input_u = int(input("Enter your choice: "))
    
    if input_u == 1:
        create_lok_sabha()
    elif input_u == 2:
        create_rajya_sabha()    
    elif input_u == 3:
        elect_president()   
    elif input_u == 4:
        if loksabha is not None:
            add_lok_sabha_member()
        else:
            print("Create Lok Sabha to add members..\n")
    elif input_u == 5:
        if rajyasabha is not None:
            add_rajya_sabha_member()
        else:
            print("Create Rajya Sabha to add members..\n")
    elif input_u == 6:
        if loksabha is not None:
            loksabha_pass_bill()
        else:
            print("Create Lok Sabha to pass bill..\n")
    elif input_u == 7:
        if rajyasabha is not None:
            rajya_pass_bill()
        else:
            print("Create Rajya Sabha to pass bill..\n")
    elif input_u == 8:
        if president is not None and loksabha is not None and rajyasabha is not None and len(bills)>0:
            president_pass_bill()
        else:
            print("Legislative bodies not properly defined..\n")
    elif input_u == 9:
        if loksabha is not None:
            display_lok_sabha()
        else:
            print("Create Lok Sabha to display..\n")
    elif input_u == 10:
        if rajyasabha is not None:
            display_rajya_sabha()
        else:
            print("Create Rajya Sabha to display..\n")
    elif input_u == 11:
        if president is not None:
            display_president()
        else:
            print("Create President to display..\n")
    elif input_u == 12:
        if len(bills)>0:
            display_bills()
        else:
            print("No bills to display..\n")
    elif input_u == 13:
        print("Thankyou for using the Parliament..\n")
        break
        
        