# lok Sabha

class LokSabha:
    def __init__(self, speaker):
        print("Lok Sabha created..\n")
        self.speaker = speaker
        self.members = []
        
    def pass_bill(self,bill):
        print(f"Bill {bill.title} passed by the Lok Sabha.\n")
        
    def add_members(self, member):
        if(len(self.members)<543):
            self.members.append(member)
            print(f"{member.get_mp_details()} added to Lok Sabha..\n")
        else:
            print("Lok Sabha full..\n")
            
    def get_speaker(self):
        return self.speaker.get_mp_details()
    
    def get_mps_lok_sabha(self):
        return self.members