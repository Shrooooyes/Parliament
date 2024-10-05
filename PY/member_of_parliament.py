# member_of_parliament
class Member_Of_Parliament:
    def __init__(self, name, party):
         self.name = name
         self.party = party
    
    def get_mp_details(self):
        return "Name: " + self.name + "\n  Party: "+self.party