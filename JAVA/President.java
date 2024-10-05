/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */
import java.util.Scanner;

public class President {
    private String Name;


    public President(String Name){
        this.Name = Name;
    }

    public boolean makeLaw(Bill bill){
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println("\n\nDoes president want to sign the bill?");
            String President_MakeLaw = sc.nextLine();
            if(President_MakeLaw.equalsIgnoreCase("yes")){
                System.out.println("Bill: \n"+bill.getBill()+"\nMade to Law...");
                // sc.close();
                return true;
            }
            else if(President_MakeLaw.equalsIgnoreCase("no")){
                System.out.println("\nPresident doesnt want to sign so bill cannot be passed....\n");
                // sc.close();
                return false;
            }
            else{
                System.out.println("Invalid Input");
            }
        }
    }

    public String getName() {
        return Name;
    }
    
}
