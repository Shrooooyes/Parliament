/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */
public class MemberOfParliament {
    private String Name;
    private String Party;

    public MemberOfParliament(String name, String Party) {
        this.Name = name;
        this.Party = Party;
    }

    public String getMPDetails(){
        return "Name: " + this.Name + "\nParty: "+this.Party;
    }
}
