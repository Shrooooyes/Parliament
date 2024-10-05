
public class Bill{
    private string billId;
    private string title;
    private string description;

    private bool loksabhaPass;
    private bool rajyasabhaPass;

    public Bill(string billID, string title, string description){
        this.billId = billID;
        this.title = title;
        this.description = description;
    }

    public void billLokSabha(bool loksabhaPass){
        this.loksabhaPass = loksabhaPass;
    }

    public void billRajyaSabha(bool rajyasabhaPass){
        this.rajyasabhaPass = rajyasabhaPass;
    }

    public bool billCanBePassed(){
        return this.loksabhaPass && this.rajyasabhaPass;
    }

    public string getBillID(){
        return this.billId;
    }

    public string getBill(){
        return this.billId+"\n"+this.title + "\n" + this.description;
    }

}