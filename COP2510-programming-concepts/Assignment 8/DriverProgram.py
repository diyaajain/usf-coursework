#Driver Program
#Driver - Dustin Carmelo (U64292924)
#Navigator - Diya Jain (U81673988)
#This module is a driver program that starts a Trivia game for two players
#It includes one function (main) and imports another module with the trivia questions and answers
#The program also counts the points and declares who wins

#import TriviaQuestions module
import TriviaQuestions

def main():
    #stored list of objects from TriviaQuestions into trivia
    trivia = TriviaQuestions.listques
    #initialized counters for each players points
    player1pnts = 0
    player2pnts = 0
    
    #for loop to alternate between players
    for i in range(0, 10):
        if i % 2 != 0: #conditional statement that checks and prints 'Player 2' for even indices
            print('Question for the second player')
        else: #prints 'Player 1' for odd indices
            print('Question for the first player')

        #prints the question and choices of the object based on their index
        print()
        print(trivia[i].getquestion())
        print(trivia[i].getanswer1())
        print(trivia[i].getanswer2())
        print(trivia[i].getanswer3())
        print(trivia[i].getanswer4())


        #conditional statement for Player 2
        if i % 2 != 0: 
            #variable specifying Player 2's choice
            p2choice = int(input('Enter your solution (a number between 1 and 4): '))

            #if-else statement for Player 2 counter
            if p2choice == trivia[i].getcorrectAnswer():
                print('That is the correct answer')
                player2pnts += 1 #incrementation of Player 2 points
            else:
                #prints the right answer if answer wrong
                print('That is the incorrect answer. The correct answer is {}'.format(trivia[i].getcorrectAnswer()))

        else:
            #variable specifying Player 1's choice
            p1choice = int(input('Enter your solution (a number between 1 and 4): '))

            #if-else statement for Player 1 counter
            if p1choice == trivia[i].getcorrectAnswer():
                print('That is the correct answer')
                player1pnts += 1 #incrementation of Player 1 points
            else:
                #prints the right answer if answer wrong
                print('That is the incorrect answer. The correct answer is {}'.format(trivia[i].getcorrectAnswer()))
        print()

    #prints the players points
    print('The first player earned', player1pnts, 'points.')
    print('The second player earned', player2pnts, 'points')
    
    #if-else statements to state which player wins or if it's a tie
    if player1pnts > player2pnts:
        print('The first player wins the game.')
    elif player1pnts == player2pnts:
        print("It's a tie")
    else:
        print('The second player wins the game')

        

#call to main
main()
