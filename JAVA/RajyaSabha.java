/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */

class RajyaSabha implements INTFParliament{
    private Chairman chairman;
    private MemberOfParliament[] members;
    private int counter = 0;

    private boolean makeLaw;

    public RajyaSabha(Chairman chairman){
        this.chairman = chairman;
        members = new MemberOfParliament[250];
    }

    @Override
    public void electLeaders() {
        System.out.println("Rajya Sabah is electing members...");
    }

    @Override
    public void passBill(Bill bill) {
        System.out.println("Rajya Sabah is passing bill :\n"+bill.getBill());
        this.makeLaw = true;
    }

    public void addMember(MemberOfParliament member){
        if(counter<250){   
            members[counter] = member;
            counter++;
            System.out.println("Memeber: "+member.getMPDetails()+ " added to Rajya Sabha...");
        }
        else{
            System.out.println("Rajya Sabha is full...");
        }
    }

    public void rejectBill(){
        this.makeLaw = false;
        System.out.println("Bill rejected....\n");
    }

    public boolean get_makeLawStatus(){
        return this.makeLaw;
    }

    public String getChairman(){
        String sp = this.chairman.getMPDetails();
        return sp;
    } 

    public MemberOfParliament[] getMPsRajyaSabha(){
        return this.members;
    }
}
