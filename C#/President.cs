
public class President {
    private string Name;


    public President(string Name){
        this.Name = Name;
    }

    public bool makeLaw(Bill bill){
        while(true){
            Console.WriteLine("\n\nDoes president want to sign the bill?");
            string President_MakeLaw;
            President_MakeLaw = Console.ReadLine();
            if(President_MakeLaw.Equals("yes")){
                Console.WriteLine("Bill: \n"+bill.getBill()+"\nMade to Law...");
                return true;
            }
            else if(President_MakeLaw.Equals("no")){
                Console.WriteLine("\nPresident doesnt want to sign so bill cannot be passed....\n");
                return false;
            }
            else{
                Console.WriteLine("Invalid Input");
            }
        }
    }

    public string getName() {
        return Name;
    }
    
}
