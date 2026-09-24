#Pair Programming

#Driver : Diya Jain (U81673988)
#Navigator : Fibi Shoukry (U43930747)

#This program turns an entered string into Morse code

#morse code dictionary 
morse_code = {" ":" ", ",":"--..--", ".":".-.-.-", "?":"..--..", "0":"-----",
              "1":".----", "2":"..---", "3":"...--", "4":"....-", "5":".....",
              "6":"-....", "7":"--....", "8":"---..", "9":"----.", "A":".-",
              "B":"-...", "C":"-.-.", "D":"-..", "E":".", "F":"..-.", "G":"--.",
              "H":". ...", "I":". .", "J":".---", "K":"-.-", "L": ".-..", "M":"--",
              "N": "-.", "O":"---", "P":".---.", "Q":"--.-",
              "R":".-.", "S":"...", "T":"-", "U":"..-", "V":"...-",
              "W":".--", "X":"-..-", "Y":"-.--", "Z":"--.."}

sentence = input("Type a message to convert in morse code: ").upper()
encodedsentence = ""

#converts each letter of the sentence into morse code
for character in sentence:
  #checks if the letter is in the Morse Code dictionary
  if character in morse_code:
    encodedsentence += morse_code[character]
  else:
    #replaces unrecognised characters with a space
    encodedsentence += " "
    
#displaying the message in Morse Code:
print("Your message in morse code is:")
print(encodedsentence)

#The morse code is displayed.
