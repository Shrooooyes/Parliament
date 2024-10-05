/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */
import java.util.Scanner;

public class Parliament {

    LokSabha loksabha = null;
    RajyaSabha rajyaSabha = null;
    President president = null;
    Bill[] bills = new Bill[50];
    int billCount = 0;
    


    public void createLoksabha(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Speaker Name: ");
        String speakerName = sc.nextLine();
        System.out.println("Enter Speaker Party: ");
        String speakerParty = sc.nextLine();

        loksabha = new LokSabha(new Speaker(speakerName,speakerParty));
        // sc.close();
    }

    public void createRasabha(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Chairman Name: ");
        String chairmanName = sc.nextLine();
        System.out.println("Enter Chairman Party: ");
        String chairmanParty = sc.nextLine();

        rajyaSabha = new RajyaSabha(new Chairman(chairmanName,chairmanParty));

        // sc.close();
    }

    public void electPresident(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter President Name: ");
        String presidentName = sc.nextLine();

        president = new President(presidentName);
        // sc.close();
    }

    public void addLokSabhaMembers() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Members Name");
        String memberName = sc.nextLine();
        System.out.println("Enter Members Party");
        String memberParty = sc.nextLine();

        MemberOfParliament member = new MemberOfParliament(memberName, memberParty);
        loksabha.addMember(member);

        // sc.close();
    }

    public void addRajyaSabhaMembers() {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Members Name");
        String memberName = sc.nextLine();
        System.out.println("Enter Members Party");
        String memberParty = sc.nextLine();

        MemberOfParliament member = new MemberOfParliament(memberName, memberParty);
        rajyaSabha.addMember(member);

        // sc.close();
    }

    public void loksabhaPassBill(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Bill ID: ");
        String billId = sc.nextLine();
        System.out.println("Enter Bill Title: ");
        String billTitle = sc.nextLine();
        System.out.println("Enter Bill Description: ");
        String billDescription = sc.nextLine();

        Bill bill = new Bill(billId,billTitle, billDescription);
        bill.billLokSabha(true);

        // Edit Here

        if(billCount<bills.length){
            bills[billCount] = bill;
            billCount++;
            loksabha.passBill(bill);

            while(true){
                System.out.println("\n\nDoes Rajya Sabha want to pass the bill?");
                String passLaw = sc.nextLine();
                if(passLaw.equalsIgnoreCase("yes")){
                    System.out.println("Bill: \n"+bill.getBill()+"\npassed by both parties...");
                    bill.billRajyaSabha(true);
                    break;
                }
                else if(passLaw.equalsIgnoreCase("no")){
                    System.out.println("\nRajya Sabha doesnt want to pass so bill...\n");
                    bill.billRajyaSabha(false);
                    break;
                }
                else{
                    System.out.println("Invalid Input");
                }
            }
        }
        else{
            System.out.println("50 Bills are pending....");
        }
        // sc.close();
    }

    public void rajyasabhaPassBill(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Bill ID: ");
        String billId = sc.nextLine();
        System.out.println("Enter Bill Title: ");
        String billTitle = sc.nextLine();
        System.out.println("Enter Bill Description: ");
        String billDescription = sc.nextLine();

        Bill bill = new Bill(billId,billTitle, billDescription);
        bill.billRajyaSabha(true);

        if(billCount<bills.length){
            bills[billCount] = bill;
            billCount++;
            rajyaSabha.passBill(bill);

            while(true){
                System.out.println("\n\nDoes Lok Sabha want to pass the bill?");
                String passLaw = sc.nextLine();
                if(passLaw.equalsIgnoreCase("yes")){
                    System.out.println("Bill: \n"+bill.getBill()+"\npassed by both parties...");
                    bill.billLokSabha(true);
                    break;
                }
                else if(passLaw.equalsIgnoreCase("no")){
                    System.out.println("\nLok Sabha doesnt want to pass so bill...\n");
                    bill.billLokSabha(false);
                    break;
                }
                else{
                    System.out.println("Invalid Input");
                }
            }
        }
        else{
            System.out.println("50 Bills are pending....");
        }
        // sc.close();
    }

    public void presidentPassBill(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter Bill ID");
        String billId = sc.nextLine();
        Bill thisBill = null;

        for (Bill billObject : bills) {
            if(billObject != null && billObject.getBillID().equalsIgnoreCase(billId)){
                thisBill = billObject;
                break;
            }
        }

        if(thisBill != null){    
            if(thisBill.billCanBePassed()){
                president.makeLaw(thisBill);
            }
            else{
                System.out.println("Bill cannot be passed...");
            }
        }
        else{
            System.out.println("Bill not found...");
        }
    }

    public void displayLokSabha(){
        System.out.println("Lok Sabha: ");
        System.out.println("Speaker: " + loksabha.getSpeaker());

        System.out.println("Members of Lok Sabha:");

        MemberOfParliament[] members = new MemberOfParliament[543];
        members = loksabha.getMPsLokSabha();

        int i = 0;
        for (MemberOfParliament member : members) {
            if(member != null){
                System.out.println(i+". "+member.getMPDetails());
                i++;
            }
        }
    }

    public void displayRajyaSabha(){
        System.out.println("Rajya Sabha: ");
        System.out.println("Chairman: "+rajyaSabha.getChairman());

        System.out.println("Members of Rajya Sabha:");

        MemberOfParliament[] members = new MemberOfParliament[250];
        members = rajyaSabha.getMPsRajyaSabha();

        int i = 0;
        for (MemberOfParliament member : members) {
            if(member != null){
                System.out.println(i+". "+member.getMPDetails());
            }
        }
    }

    public void displayPresident(){
        System.out.println("President: "+president.getName());
    }

    public void displayBills(){
        System.out.println("Bills: ");
        for (Bill BillObject : bills) {
            if(BillObject != null){
                System.out.println(BillObject.getBill());
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Parliament parliament = new Parliament();

        int input;
        do{ 
            System.out.println("\n\nEnter Option");
            System.out.println("1. Create Lok Sabha");
            System.out.println("2. Create Rajya Sabha");
            System.out.println("3. Elect President");
            System.out.println("4. Add Loksabha members");
            System.out.println("5. Add Rajyasabha members");

            System.out.println("6. Pass bill by loksabha");
            System.out.println("7. Pass bill by rajyasabha");
            System.out.println("8. Pass Bill to Law by president");

            System.out.println("9. Display Lok Sabha");
            System.out.println("10. Display Rajya Sabha");
            System.out.println("11. Display President");
            System.out.println("12. Display Bills");
            System.out.println("13. Exit");


            System.out.println("\n\nEnter Your Choice: ");
            input = Integer.parseInt(scanner.nextLine());
                
            if(input == 13){
                System.out.println("Thank you for using the Parliament System");
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
                    System.out.println("Create LokSabah to Add Members...");
                    break;
                case 5:
                    if(parliament.rajyaSabha != null){
                        parliament.addRajyaSabhaMembers();
                        break;
                    }
                    System.out.println("Create RajyaSabha to Add Members...");
                    break;
                case 6:
                    if(parliament.loksabha != null){
                        parliament.loksabhaPassBill();

                        break;
                    }
                    System.out.println("Create Lok Sabha to pass bill...");
                    break;
                case 7:
                    if(parliament.rajyaSabha != null){
                        parliament.rajyasabhaPassBill();
                        break;
                    }
                    System.out.println("Create Rajya Sabha to pass bill...");
                    break;
                case 8:
                    if(parliament.loksabha != null && parliament.rajyaSabha != null && parliament.billCount != 0){
                        parliament.presidentPassBill();
                        break;
                    }
                    System.out.println("Legislative bodies not properly defined...");
                    break;
                case 9:
                    if(parliament.loksabha != null){
                        parliament.displayLokSabha();

                        break;
                    }
                    System.out.println("Create Lok Sabha...");
                    break;
                case 10:
                    if(parliament.rajyaSabha != null){
                        parliament.displayRajyaSabha();

                        break;
                    }
                    System.out.println("Create Rajya Sabha...");
                    break;
                case 11:
                    if(parliament.president != null){
                        parliament.displayPresident();
                        break;
                    }
                    System.out.println("Elect President...");
                    break;
                case 12:
                    if(parliament.billCount == 0){
                        System.out.println("No bills to display...");
                        break;
                    }
                    parliament.displayBills();
                default:
                    System.out.println("Invalid input");
                    break;
            }
        }while(input!=13);

        scanner.close();
    }
}
