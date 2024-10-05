
public class MemberOfParliament {
    private string Name;
    private string Party;

    public MemberOfParliament(string Name, string Party) {
        this.Name = Name;
        this.Party = Party;
    }

    public string getMPDetails(){
        return "Name: " + this.Name + "\nParty: "+this.Party;
    }
}