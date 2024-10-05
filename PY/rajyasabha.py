# Chairman

class RajyaSabha:
    
    def __init__(self, chairman):
      self.chairman = chairman
      self.members = []
      
    def pass_bill(self,bill):
        print(f"Bill {bill.title} passed by the Rajya Sabha.\n")
        
    def add_members(self, member):
        if(len(self.members)<543):
            self.members.append(member)
            print(f"{member.get_mp_details()} added to Rajya Sabha..\n")
        else:
            print("Rajya Sabha full..\n")
            
    def get_chairman(self):
        return self.chairman.get_mp_details()
    
    def get_mps_rajya_sabha(self):
        return self.members