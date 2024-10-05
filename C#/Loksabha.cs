
class LokSabha {
    private Speaker speaker;
    private MemberOfParliament[] members;
    private int counter = 0;

    public LokSabha(Speaker speaker){
        Console.WriteLine("Lok Sabha created....");
        this.speaker = speaker;
        members = new MemberOfParliament[543];
    }

    public void electLeaders() {
        Console.WriteLine("Lok Sabah is electing members...");
    }

    public void passBill(Bill bill) {
        Console.WriteLine("Lok Sabah is passing bill :\n"+bill.getBill());
    }

    public void addMember(MemberOfParliament member){
        if(counter<543){   
            members[counter] = member;
            counter++;
            Console.WriteLine(members[counter-1].getMPDetails()+ " added to Lok Sabha...");
        }
        else{
            Console.WriteLine("Lok Sabha is full...");
        }
    }

    public string getSpeaker(){
        string sp = this.speaker.getMPDetails();
        return sp;
    } 

    public MemberOfParliament[] getMPsLokSabha(){
        return this.members;
    }
}