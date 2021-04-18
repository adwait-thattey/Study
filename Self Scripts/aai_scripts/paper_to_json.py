import json
import sys

FILENAME = "s4.tsv"
MODULE = 4
MARKS_PER_QUESTION = 1.5
JSON_NAME = "p1m4.json"

def isTitleLine(split_line):
    if(len(split_line)!=3):
        return False
    
    if(split_line[2].isnumeric()):
        return False

    if(not split_line[2]):
        return False

    return True

def parseArgs():
    global FILENAME, MODULE, MARKS_PER_QUESTION, JSON_NAME

    arguments = sys.argv
    if(len(arguments) > 0):
        try:
            ix = arguments.index('--filename')
            FILENAME = arguments[ix+1]
        except ValueError:
            pass
        
        try:
            ix = arguments.index('--jsonName')
            JSON_NAME = arguments[ix+1]
        except ValueError:
            pass

        try:
            ix = arguments.index('--module')
            MODULE = int(arguments[ix+1])
        except ValueError:
            pass

        try:
            ix = arguments.index('--marks')
            MARKS_PER_QUESTION = float(arguments[ix+1])
        except ValueError:
            pass


if __name__ == "__main__":

    parseArgs()
    print(f"Values of global variables. Filename:{FILENAME}, JSONName:{JSON_NAME}, MODULE:{MODULE}, MARKS:{MARKS_PER_QUESTION} ")
    class Question:
        def __init__(self):
            self.number = 0
            self.title = "LOREM IPSUM"
            self.module = MODULE
            self.marks = MARKS_PER_QUESTION
            self.difficulty = 0
            self.options = []
            self.correct_option = 0

        def serialized(self):
            return {
                "number": self.number,
                "title": self.title,
                "module": self.module,
                "marks": self.marks,
                "difficulty": self.difficulty,
                "options": self.options,
                "correctOption": self.correct_option 
            }

        def check_defaults(self):
            if self.number == 0 or self.title == "LOREM IPSUM" or self.module ==0 or self.difficulty == 0 or self.marks == 0 or len(self.options)==0 or self.correct_option == 0:
                return False
            
            return True

    ALL_QUESTIONS = {}

    f = open(FILENAME, mode = "r")
    lines = f.readlines()
    f.close()

    bflag = 1
    ix=0
    while ix < len(lines):
        bflag = 1
        l = lines[ix].strip('\n').split('\t')
        if(not isTitleLine(l)):
            print(f"ERROR: {l} is not the title line")
            break
        
        ques = Question()
        ques.number = int(l[0])
        ques.title = l[1]
        difficulty = l[2]
        if difficulty.upper() == 'E':
            ques.difficulty = 1
        elif difficulty.upper() == 'M':
            ques.difficulty = 2
        elif difficulty.upper() == 'D':
            ques.difficulty = 3
        else:
            print(f"Unknown difficulty {difficulty} on line {l}")
            break
        
        # now get questions
        cur = 1
        ix+=1
        l = lines[ix].strip('\n').split('\t')
        if isTitleLine(l):
            print(f"Title line encountered. Expe3cted question line. l = {l}")
            break

        ques.options.append(l[1])
        if(len(l) > 2 and l[2] == '1'):
            ques.correct_option = cur
        
        ###########
        cur = 2
        ix+=1
        l = lines[ix].strip('\n').split('\t')
        if isTitleLine(l):
            print(f"Title line encountered. Expe3cted question line. l = {l}")
            break

        ques.options.append(l[1])
        if(len(l) > 2 and l[2] == '1'):
            ques.correct_option = cur

        ###########
        cur = 3
        ix+=1
        l = lines[ix].strip('\n').split('\t')
        if isTitleLine(l):
            print(f"Title line encountered. Expe3cted question line. l = {l}")
            break

        ques.options.append(l[1])
        if(len(l) > 2 and l[2] == '1'):
            ques.correct_option = cur

        ##############
        cur = 4
        ix+=1
        l = lines[ix].strip('\n').split('\t')
        if isTitleLine(l):
            print(f"Title line encountered. Expe3cted question line. l = {l}")
            break

        ques.options.append(l[1])
        if(len(l) > 2 and l[2] == '1'):
            ques.correct_option = cur

        #######
        ix+=1

        if not ques.check_defaults():
            print(f"ERROR: Default values retained in question {ques.serialized()}")
            break

        if ques.number in ALL_QUESTIONS:
            print(f"ERROR: question  {ques.number} already in ALL_QUESTIONS")
            break
        
        ALL_QUESTIONS[ques.number] = ques.serialized()

        bflag = 0


    if(bflag == 0):
        # no error


        f = open(JSON_NAME, mode = "w")
        f.write(json.dumps(ALL_QUESTIONS))
        f.close()

