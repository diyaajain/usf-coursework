#Assignment 5 - Peer Programming - Tortoise Vs.Hare
#Driver: Diya Jain U81673988
#Navigator: Spuritha Bhandaru U69433246

#The program simulates the classical race between the tortoise and the hare. 

import random

print("ON YOUR MARK... GET SET...\nGO!\nAND THEY'RE OFF!")

#determining postion of the hare using the if else statement and the function 
def hare_position(p):
    npos = random.choices(['s','bh','bs','sh','ss'],weights = (0.2,0.2,0.1,0.3,0.2))

    if npos == ["s"]:
        return p
    elif npos == ["bh"]:
        return min(p+7,50)
    elif npos == ["bs"]:
        return max(1,p-10)
    elif npos == ["sh"]:
        return min(p+1,50)
    elif npos == ["ss"]:
        return max(p-2,1)

#determining the position of the tortoise by using the if else statement and the function
def tortoise_position(p):
    npos = random.choices(["fp","s","sp"],weights = (0.5,0.2,0.3))

    if npos ==["s"]:
        return max(0,p-5)
    elif npos == ["fp"]:
        return min(p+3,50)
    elif npos == ["sp"]:
        return min(p+1,50)

#printing and defining the positions while in the race
def display_track(ch,ct):
    for i in range(1,51):
        if i == ch:
            print("H",end = "")
            continue
        if i == ct:
            print("T",end = "")
        else:
            print(" ",end = "")
    print()

def main(): #defining track for the race using the function 
    #tracks for the hare and tortoise
    track = [" "]*51
    time = 0
    #current positions for hare and tortoise
    ch = 1
    ct = 1

    while ch < 50 and ct < 50: #using while function and limit is 50 since animals positions are between 1 and 50.
        #choosing the current position for hare and tortoise
        ch = hare_position(ch)
        ct = hare_position(ct)
        time +=1
        #printing the race track
        display_track(ch,ct)

    if ch == 50:
        print("Hare wins.Yay!") #printing the output for the hare wining. 
    elif ct == 50:
        print("Tortoise wins.Yay!") #printing output for tortoise winning 
    print(f"Time of race : {time} seconds")#printing the time taken 

main()
#end of program
