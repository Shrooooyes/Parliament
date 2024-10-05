
class RajyaSabha {
    private Chairman chairman;
    private MemberOfParliament[] members;
    private int counter = 0;


    public RajyaSabha(Chairman chairman){
        this.chairman = chairman;
        members = new MemberOfParliament[250];
    }

    public void passBill(Bill bill) {
        Console.WriteLine("Rajya Sabah is passing bill :\n"+bill.getBill());
    }

    public void addMember(MemberOfParliament member){
        if(counter<250){   
            members[counter] = member;
            counter++;
            Console.WriteLine("Memeber: "+member.getMPDetails()+ " added to Rajya Sabha...");
        }
        else{
            Console.WriteLine("Rajya Sabha is full...");
        }
    }

    public string getChairman(){
        string sp = this.chairman.getMPDetails();
        return sp;
    } 

    public MemberOfParliament[] getMPsRajyaSabha(){
        return this.members;
    }
}
