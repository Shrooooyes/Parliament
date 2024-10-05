/*
 * @author: Shreyash Sawant
 * Roll no.:45
 */
public class Bill {
    private String billId;
    private String title;
    private String description;

    private boolean loksabhaPass;
    private boolean rajyasabhaPass;

    public Bill(String billID, String title, String description){
        this.billId = billID;
        this.title = title;
        this.description = description;
    }

    public void billLokSabha(boolean loksabhaPass){
        this.loksabhaPass = loksabhaPass;
    }

    public void billRajyaSabha(boolean rajyasabhaPass){
        this.rajyasabhaPass = rajyasabhaPass;
    }

    public boolean billCanBePassed(){
        return this.loksabhaPass && this.rajyasabhaPass;
    }

    public String getBillID(){
        return this.billId;
    }

    public String getBill(){
        return this.billId+"\n"+this.title.toUpperCase() + "\n" + this.description;
    }
}
