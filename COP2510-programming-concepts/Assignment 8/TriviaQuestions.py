#Trivia Questions module
#Driver - Dustin Carmelo (U64292924)
#Navigator - Diya Jain (U81673988)
#This is a module that contains the function TriviaQuestions that returns a list of objects

#imports the module for class Questions
import questionclass

def TriviaQuestions():
    questions = [] #empty list to append the objects too
    
    #object created for the first question and for each question after
    ques1 = questionclass.Questions("How many days are in a lunar year?", "1. 354", "2. 365", "3. 243", "4. 379", 1)
    #appends the new object to the list
    questions.append(ques1)

    ques2 = questionclass.Questions("What is the largest planet?", "1. Mars", "2. Jupiter", "3. Earth", "4. Pluto", 2)
    questions.append(ques2)

    ques3 = questionclass.Questions("What is the largest kind of whale?", "1. Orca whale", "2. Humpback whale", "3. Beluga whale", "4. Blue whale", 4)
    questions.append(ques3)

    ques4 = questionclass.Questions("Which dinosaur could fly?", "1. Triceratops", "2. Tyrannosaurus Rex", "3. Pteradactyl", "4. Diplodocus", 3)
    questions.append(ques4)

    ques5 = questionclass.Questions("Which of these Winnie the Pooh characters is a donkey?", "1. Pooh", "2. Eeyore", "3. Piglet", "4. Kanga", 2)
    questions.append(ques5)

    ques6 = questionclass.Questions("What is the hottest planet?", "1. Mars", "2. Pluto", "3. Earth", "4. Venus", 4)
    questions.append(ques6)

    ques7 = questionclass.Questions("Which dinosaur had the largest brain compared to body size?", "1. Troodon", "2. Stegosaurus", "3. Ichthyosaurus", "4. Gigantoraptor", 1)
    questions.append(ques7)

    ques8 = questionclass.Questions("What is the largest type of penguins?", "1. Chinstrap penguins", "2. Macaroni penguins", "3. Emperor penguins", "4. White-flippered penguins", 3)
    questions.append(ques8)

    ques9 = questionclass.Questions("Which children's story character is a monkey?", "1. Winnie the Pooh", "2. Curious George", "3. Horton", "4. Goofy", 2)
    questions.append(ques9)

    ques10 = questionclass.Questions("How long is a year on Mars?", "1. 550 Earth days", "2. 498 Earth days", "3. 126 Earth days", "4. 687 Earth days", 4)
    questions.append(ques10)

    return questions #returns the list of objects

#stores the list in a variable
listques = TriviaQuestions()
    



    





