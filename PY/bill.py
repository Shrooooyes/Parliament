#Bill

class Bill:
    
    def __init__(self, bill_id, title, descp) -> None:
        self.bill_id = bill_id
        self.title = title
        self.descp = descp
        self.loksabha_pass = False
        self.rajyasabha_pass = False
        
    def bill_loksabha(self, loksabha_pass):
        self.loksabha_pass = loksabha_pass
    
    def bill_rajyasabha(self, rajyasabha_pass):
        self.rajyasabha_pass = rajyasabha_pass
        
    def bill_can_be_passed(self):
        return self.loksabha_pass and self.rajyasabha_pass
    
    def get_bill_id(self):
        return self.bill_id
    
    def get_bill(self):
        return self.bill_id+"\n"+self.title.upper()+"\n"+self.descp