# S1 = {
#     "name": "Adwait",
#     "section": "A"
# }

# S2 = {
#     "name": "Adwait",
#     "section": "A"
# }

# S3 = {
#     "name": "Adwait",
#     "section": "A"
# }

# students = [S1,S2,S3]

class Student:
    def __init__(self, incoming_name, incoming_section, ph_no):
        self._name = incoming_name
        self.section = incoming_section
        self.phno = ph_no
        # abcd = incoming_name

    @property
    def name(self):
        return self._name.title()
    
    @property
    def phno(self):
        return self.__ph_no
    
    @phno.setter
    def phno(self, ph_no):
        
        if len(ph_no)!=10:
            raise ValueError("Length not equal to 10")

        self.__ph_no = ph_no

    def change_name(self, new_name):
        self.name = new_name
        abcd = new_name

    def __str__(self):  
        return str(self.name)

S1 = Student("adwait", "A", "7507763619")
print(S1.name)
