#Pair Programming Assignment
#Driver - Spuritha Bhandaru U69433246
#Navigator - Diya Jain U81673988

#This program stimulates a game called Rock Paper Scissors Lizard Spock for the Computer and User to play. 

import random #importing the random module
O = ['rock', 'paper', 'scissors', 'lizard', 'spock'] #listing O with options
print("Let's play Rock, Paper, Scissors, Lizard, Spock!") #print message
user_counter = 0 #defining user, tie, computer, total counters
computer_counter = 0
tie_counter = 0
total_counter = 0
while True: #creating an infinite loop
    user = input("Enter your choice:") #takes user's input
    while True:
        if user.lower() not in O: #checking if input is in the options
            user = input("That's invalid. Please enter Rock, Paper, Scissors, Lizard or Spock:")
        else:
            break #loop breaks if input is invalid
    computer = random.choice(O)#gets random choice for computer
    print("Computer choose",computer)#print message
    if user.lower() == "scissors" and computer == "paper": #checks all possibilites for user to win
        print("Scissors cuts Paper! Human Wins")
        user_counter += 1 #increment for user counter
    elif user.lower() == "paper" and computer == "rock":
        print("Paper covers Rock! Human Wins")
        user_counter += 1 #increment for the user counter
    elif user.lower() == "rock" and computer == "lizard":
         print("Rock crushes Lizard! Human Wins")
         user_counter += 1 #increment for the user counter
    elif user.lower() == "lizard" and computer == "spock":
        print("Lizard poisons Spock! Human Wins")
        user_counter += 1 #increment for the user counter
    elif user.lower() == "spock" and computer == "scissors":
        print("Spock smashes Scissors! Human Wins")
        user_counter += 1 #increment for the user counter
    elif user.lower() == "scissors" and computer == "lizard":
        print("Scissors decapitates Lizard! Human Wins")
        user_counter += 1 #increment for the user counter
    elif user.lower() == "lizard" and computer == "paper":
        print("Lizard eats Paper! Human Wins")
        user_counter += 1 
    elif user.lower() == "paper" and computer == "spock":
        print("Paper disproves Spock! Human Wins")
        user_counter += 1 #increment for the user counter
    elif user.lower() == "spock" and computer == "rock":
        print("Spock vaporizes Rock! Human Wins")
        user_counter += 1 
    elif user.lower() == "rock" and computer == "scissors":
        print("Rock crushes Scissors! Human Wins")
        user_counter += 1 #increment for the user counter
    elif computer == "scissors" and user.lower() == "paper": #cheking all possibilities for computer to win
        print("Scissors cuts Paper! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "paper" and user.lower() == "rock":
        print("Paper covers Rock! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "rock" and user.lower() == "lizard":
        print("Rock crushes Lizard! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "lizard" and user.lower() == "spock":
        print("Lizard poisons Spock! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "spock" and user.lower() == "scissors":
        print("Spock smashes Scissors! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "scissors" and user.lower() == "lizard":
        print("Scissors decapitates Lizard! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "lizard" and user.lower() == "paper":
        print("Lizard eats Paper! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "paper" and user.lower() == "spock":
        print("Paper disproves Spock! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "spock" and user.lower() == "rock":
        print("Spock vaporizes Rock! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    elif computer == "rock" and user.lower() == "scissors":
        print("Rock crushes Scissors! Computer Wins")
        computer_counter += 1 #increment for the computer counter
    else: #if all conditions are false then it becomes a tie
        print("Its a Tie!") #print message to display it's a tie
        tie_counter += 1 #increment for the tie counter
    total_counter += 1 #increment for the total counter
    flag=0 #define flag to be 0
    choice = input("Play again? (yes/no):") #asks user again if they want to play
    while True:
        if choice.lower() == 'yes': #checks if choice is yes
            break #breaks the loop
        elif choice.lower() == 'no': #checks if choice is yes
            flag = 1 #makes flag 1
            break #breaks the loop
        else:
            choice = input("Invalid response. Play again? Enter yes or no only:") #prints message for the invalid input
    if flag == 1:
        break #breaks the output loop
    print() #print blank line
print()
print("Number of games played :",total_counter) #prints number of games playes
print("Games you won :",user_counter) #prints games user won
print("Games computer won :",computer_counter) #prints games computer won
print("Tie Games :",tie_counter) #prints the number of ties
print("Thanks for playing!") #prints thank you message


            
    
