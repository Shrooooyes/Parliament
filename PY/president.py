#president

class President:
    
    def __init__(self, name):
        self.name = name
        
    def make_law(self, bill):
        
        while True:
            president_make_law = input("Does President want to sign the bill?(yes/no)").lower()
        
            if president_make_law == "yes":
                print(f"{self.name} signed the bill.")
                return True
            elif president_make_law == "no":
                print(f"{self.name} did not sign the bill.")
                return False
            else:
                print("Invalid input. Please enter 'yes' or 'no'.")
            
    def get_name(self):
        return self.name