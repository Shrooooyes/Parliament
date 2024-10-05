/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */
class LokSabha implements INTFParliament{
    private Speaker speaker;
    private MemberOfParliament[] members;
    private boolean makeLaw;
    private int counter = 0;

    public LokSabha(Speaker speaker){
        System.out.println("Lok Sabha created....");
        this.speaker = speaker;
        members = new MemberOfParliament[543];
    }

    @Override
    public void electLeaders() {
        System.out.println("Lok Sabah is electing members...");
    }

    @Override
    public void passBill(Bill bill) {
        System.out.println("Lok Sabah is passing bill :\n"+bill.getBill());
        this.makeLaw = true;
    }

    public void addMember(MemberOfParliament member){
        if(counter<543){   
            members[counter] = member;
            counter++;
            System.out.println(members[counter-1].getMPDetails()+ " added to Lok Sabha...");
        }
        else{
            System.out.println("Lok Sabha is full...");
        }
    }

    public void rejectBill(){
        this.makeLaw = false;
        System.out.println("Bill rejected....\n");
    }

    public boolean get_makeLawStatus(){
        return this.makeLaw;
    }

    public String getSpeaker(){
        String sp = this.speaker.getMPDetails();
        return sp;
    } 

    public MemberOfParliament[] getMPsLokSabha(){
        return this.members;
    }
}
