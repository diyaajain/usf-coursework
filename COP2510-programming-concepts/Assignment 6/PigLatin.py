#Pig Latin Translator
#Driver: Isabella Tran U30227684
#Navigator: Diya Jain U81673988

#This program reads a text file and converts each word to Pig latin and writes
#the results to another text file

def main():
    #takes out the words from the file
    inpt = str(input('Enter the name of the input file: '))
    text = open(inpt, 'r')
    finalwords = []

    #changes the text to lowercase
    for inputline in text.read().lower().split('\n'):
        finalwords.append(inputline.split(' '))

    #translation the text into pig latin
    piglatin = []
    for x in finalwords:
        piglatinline = []
        for word in x:
            if len(word) < 1:
                piglatinword = word + 'ay'
            else:
                piglatinword = word[1:] + word[0] + 'ay'
            piglatinline.append(piglatinword)
        piglatin.append(piglatinline)
    print(piglatin)

    #gets the user to name the output file
    out = str(input('Enter the name of the output file: '))
    text = open(out, 'w')
    for piglatinline in piglatin:
        for piglatinword in piglatinline:
            text.write(piglatinword + ' ')
        text.write(' ')
    
main()

