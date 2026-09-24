#Questions class
#Driver - Diya Jain (U81673988)
#Navigator - Dustin Carmelo (U64292924)
#module for the class Questions


class Questions:
    #initializer method
    def __init__(self, ques, ans1, ans2, ans3, ans4, correct):
        #hidden attributes for each parameter
        self.__question = ques
        self.__answer1 = ans1
        self.__answer2 = ans2
        self.__answer3 = ans3
        self.__answer4 = ans4
        self.__correctAnswer = correct

    #accessors that returns the variable of the attributes
    def getquestion(self):
        return self.__question

    def getanswer1(self):
        return self.__answer1

    def getanswer2(self):
        return self.__answer2

    def getanswer3(self):
        return self.__answer3

    def getanswer4(self):
        return self.__answer4

    def getcorrectAnswer(self):
        return self.__correctAnswer

    #mutators that allows the attributes of the class to be modified
    def setquestion(self, ques):
        self.__question = ques
    
    def setanswer1(self, ans1):
        self.__answer1 = ans1

    def setanswer2(self, ans2):
        self.__answer2 = ans2

    def setanswer3(self, ans3):
        self.__answer3 = ans3

    def setanswer4(self, ans4):
        self.__answer4 = ans4

    def setcorrectAnswer(self, correct):
        self.__correctAnswer = correct


