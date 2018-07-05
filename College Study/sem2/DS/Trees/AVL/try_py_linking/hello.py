class Hello :
    def __init__(self , word) :
        self.word = word

    def __str__(self) :
        return "Hello World" + str(self.word)