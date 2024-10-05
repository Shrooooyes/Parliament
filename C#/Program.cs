using System;
public class Parliament {

    LokSabha loksabha = null;
    RajyaSabha rajyaSabha = null;
    President president = null;
    Bill[] bills = new Bill[50];
    int billCount = 0;
    


    public void createLoksabha(){
        // Scanner sc = new Scanner(System.in);
        Console.WriteLine("Enter Speaker Name: ");
        string speakerName = Console.ReadLine();
        Console.WriteLine("Enter Speaker Party: ");
        string speakerParty = Console.ReadLine();

        loksabha = new LokSabha(new Speaker(speakerName,speakerParty));
        // sc.close();
    }

    public void createRasabha(){
        // Scanner sc = new Scanner(System.in);
        Console.WriteLine("Enter Chairman Name: ");
        string chairmanName = Console.ReadLine();
        Console.WriteLine("Enter Chairman Party: ");
        string chairmanParty = Console.ReadLine();

        rajyaSabha = new RajyaSabha(new Chairman(chairmanName,chairmanParty));

        // sc.close();
    }

    public void electPresident(){
        // Scanner sc = new Scanner(System.in);
        Console.WriteLine("Enter President Name: ");
        string presidentName = Console.ReadLine();

        president = new President(presidentName);
        // sc.close();
    }

    public void addLokSabhaMembers() {
        // Scanner sc = new Scanner(System.in);

        Console.WriteLine("Enter Members Name");
        string memberName = Console.ReadLine();
        Console.WriteLine("Enter Members Party");
        string memberParty = Console.ReadLine();

        MemberOfParliament member = new MemberOfParliament(memberName, memberParty);
        loksabha.addMember(member);

        // sc.close();
    }

    public void addRajyaSabhaMembers() {
        // Scanner sc = new Scanner(System.in);

        Console.WriteLine("Enter Members Name");
        string memberName = Console.ReadLine();
        Console.WriteLine("Enter Members Party");
        string memberParty = Console.ReadLine();

        MemberOfParliament member = new MemberOfParliament(memberName, memberParty);
        rajyaSabha.addMember(member);

        // sc.close();
    }

    public void loksabhaPassBill(){
        // Scanner sc = new Scanner(System.in);
        Console.WriteLine("Enter Bill ID: ");
        string billId = Console.ReadLine();
        Console.WriteLine("Enter Bill Title: ");
        string billTitle = Console.ReadLine();
        Console.WriteLine("Enter Bill Description: ");
        string billDescription = Console.ReadLine();

        Bill bill = new Bill(billId,billTitle, billDescription);
        bill.billLokSabha(true);

        // Edit Here

        if(billCount<bills.Length){
            bills[billCount] = bill;
            billCount++;
            loksabha.passBill(bill);

            while(true){
                Console.WriteLine("\n\nDoes Rajya Sabha want to pass the bill?");
                string passLaw = Console.ReadLine();
                if(passLaw.Equals("yes")){
                    Console.WriteLine("Bill: \n"+bill.getBill()+"\npassed by both parties...");
                    bill.billRajyaSabha(true);
                    break;
                }
                else if(passLaw.Equals("no")){
                    Console.WriteLine("\nRajya Sabha doesnt want to pass so bill...\n");
                    bill.billRajyaSabha(false);
                    break;
                }
                else{
                    Console.WriteLine("Invalid Input");
                }
            }
        }
        else{
            Console.WriteLine("50 Bills are pending....");
        }
        // sc.close();
    }

    public void rajyasabhaPassBill(){
        // Scanner sc = new Scanner(System.in);
        Console.WriteLine("Enter Bill ID: ");
        string billId = Console.ReadLine();
        Console.WriteLine("Enter Bill Title: ");
        string billTitle = Console.ReadLine();
        Console.WriteLine("Enter Bill Description: ");
        string billDescription = Console.ReadLine();

        Bill bill = new Bill(billId,billTitle, billDescription);
        bill.billRajyaSabha(true);

        if(billCount<bills.Length){
            bills[billCount] = bill;
            billCount++;
            rajyaSabha.passBill(bill);

            while(true){
                Console.WriteLine("\n\nDoes Lok Sabha want to pass the bill?");
                string passLaw = Console.ReadLine();
                if(passLaw.Equals("yes")){
                    Console.WriteLine("Bill: \n"+bill.getBill()+"\npassed by both parties...");
                    bill.billLokSabha(true);
                    break;
                }
                else if(passLaw.Equals("no")){
                    Console.WriteLine("\nLok Sabha doesnt want to pass so bill...\n");
                    bill.billLokSabha(false);
                    break;
                }
                else{
                    Console.WriteLine("Invalid Input");
                }
            }
        }
        else{
            Console.WriteLine("50 Bills are pending....");
        }
        // sc.close();
    }

    public void presidentPassBill(){
        // Scanner sc = new Scanner(System.in);

        Console.WriteLine("Enter Bill ID");
        string billId = Console.ReadLine();
        Bill thisBill = null;

        foreach (Bill billObject in bills) {
            if (billObject != null && billId.Equals(billObject.getBillID())) {
                thisBill = billObject;
                break;
            }
        }

        if(thisBill != null){    
            if(thisBill.billCanBePassed()){
                president.makeLaw(thisBill);
            }
            else{
                Console.WriteLine("Bill cannot be passed...");
            }
        }
        else{
            Console.WriteLine("Bill not found...");
        }
    }

    public void displayLokSabha(){
        Console.WriteLine("Lok Sabha: ");
        Console.WriteLine("Speaker: " + loksabha.getSpeaker());

        Console.WriteLine("Members of Lok Sabha:");

        MemberOfParliament[] members = new MemberOfParliament[543];
        members = loksabha.getMPsLokSabha();

        int i = 0;
        foreach (MemberOfParliament member in members) {
            if(member != null){
                Console.WriteLine(i+". "+member.getMPDetails());
                i++;
            }
        }
    }

    public void displayRajyaSabha(){
        Console.WriteLine("Rajya Sabha: ");
        Console.WriteLine("Chairman: "+rajyaSabha.getChairman());

        Console.WriteLine("Members of Rajya Sabha:");

        MemberOfParliament[] members = new MemberOfParliament[250];
        members = rajyaSabha.getMPsRajyaSabha();

        int i = 0;
        foreach (MemberOfParliament member in members) {
            if(member != null){
                Console.WriteLine(i+". "+member.getMPDetails());
                i++;
            }
        }
    }

    public void displayPresident(){
        Console.WriteLine("President: "+president.getName());
    }

    public void displayBills(){
        Console.WriteLine("Bills: ");
        foreach (Bill BillObject in bills) {
            if(BillObject != null){
                Console.WriteLine(BillObject.getBill());
            }
        }
    }

    public static void Main() {
        // Scanner scanner = new Scanner(System.in);
        Parliament parliament = new Parliament();

        int input;
        do{ 
            Console.WriteLine("\n\nEnter Option");
            Console.WriteLine("1. Create Lok Sabha");
            Console.WriteLine("2. Create Rajya Sabha");
            Console.WriteLine("3. Elect President");
            Console.WriteLine("4. Add Loksabha members");
            Console.WriteLine("5. Add Rajyasabha members");

            Console.WriteLine("6. Pass bill by loksabha");
            Console.WriteLine("7. Pass bill by rajyasabha");
            Console.WriteLine("8. Pass Bill to Law by president");

            Console.WriteLine("9. Display Lok Sabha");
            Console.WriteLine("10. Display Rajya Sabha");
            Console.WriteLine("11. Display President");
            Console.WriteLine("12. Display Bills");
            Console.WriteLine("13. Exit");


            Console.WriteLine("\n\nEnter Your Choice: ");
            input = int.Parse(Console.ReadLine());
                
            if(input == 13){
                Console.WriteLine("Thank you for using the Parliament System");
                break;
            }
            switch (input) {
                case 1:
                    parliament.createLoksabha();
                    break;
                case 2:
                    parliament.createRasabha();
                    break;
                case 3:
                    parliament.electPresident();
                    break;
                case 4:
                    if(parliament.loksabha != null){
                        parliament.addLokSabhaMembers();
                        break;
                    }
                    Console.WriteLine("Create LokSabah to Add Members...");
                    break;
                case 5:
                    if(parliament.rajyaSabha != null){
                        parliament.addRajyaSabhaMembers();
                        break;
                    }
                    Console.WriteLine("Create RajyaSabha to Add Members...");
                    break;
                case 6:
                    if(parliament.loksabha != null){
                        parliament.loksabhaPassBill();

                        break;
                    }
                    Console.WriteLine("Create Lok Sabha to pass bill...");
                    break;
                case 7:
                    if(parliament.rajyaSabha != null){
                        parliament.rajyasabhaPassBill();
                        break;
                    }
                    Console.WriteLine("Create Rajya Sabha to pass bill...");
                    break;
                case 8:
                    if(parliament.loksabha != null && parliament.rajyaSabha != null && parliament.billCount != 0){
                        parliament.presidentPassBill();
                        break;
                    }
                    Console.WriteLine("Legislative bodies not properly defined...");
                    break;
                case 9:
                    if(parliament.loksabha != null){
                        parliament.displayLokSabha();

                        break;
                    }
                    Console.WriteLine("Create Lok Sabha...");
                    break;
                case 10:
                    if(parliament.rajyaSabha != null){
                        parliament.displayRajyaSabha();

                        break;
                    }
                    Console.WriteLine("Create Rajya Sabha...");
                    break;
                case 11:
                    if(parliament.president != null){
                        parliament.displayPresident();
                        break;
                    }
                    Console.WriteLine("Elect President...");
                    break;
                case 12:
                    if(parliament.billCount == 0){
                        Console.WriteLine("No bills to display...");
                        break;
                    }
                    parliament.displayBills();
                    break;
                default:
                    Console.WriteLine("Invalid input");
                    break;
            }
        }while(input!=13);

    }
}
