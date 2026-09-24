#Encrypting Code
#Driver - Diya Jain U81673988
#Navigator - Isabella Tran U30227684

#This program uses a dictionary to encrypt a text file.

#The required dictionary for the encryption.
Encrypt_Code ={'A': ')', 'a': '0', 'B': '(', 'b': '9', 'C': '*', 'c': '8',
               'D': '&', 'd': '7', 'E': '^', 'e': '6', 'F': '%', 'f': '5',
               'G': '$', 'g': '4', 'H': '#', 'h': '3', 'I': '@', 'i': '2',
               'J': '!', 'j': '1', 'K': 'Z', 'k': 'z', 'L': 'Y', 'l': 'y',
               'M': 'X', 'm': 'x', 'N': 'W', 'n': 'w', 'O': 'V', 'o': 'v',
               'P': 'U', 'p': 'u', 'Q': 'T', 'q': 't', 'R': 'S', 'r': 's',
               'S': 'R', 's': 'r', 'T': 'Q', 't': 'q', 'U': 'P', 'u': 'p',
               'V': 'O', 'v': 'o', 'W': 'N', 'w': 'n', 'X': 'M', 'x': 'm',
               'Y': 'L', 'y': 'l', 'Z': 'K', 'z': 'k', '!': 'J', '1': 'j',
               '@': 'I', '2': 'i', '#': 'H', '3': 'h', '$': 'G', '4': 'g',
               '%': 'F', '5': 'f', '^': 'E', '6': 'e', '&': 'D', '7': 'd',
               '*': 'C', '8': 'c', '(': 'B', '9': 'b', ')': 'A', '0': 'a',
               ':': ',', ',': ':', '?': '.', '.': '?', '<': '>', '>': '<',
               "'": '"', '"': "'", '+': '-', '-': '+', '=': ';', ';': '=',
               '{': '[', '[': '{', '}': ']', ']': '}'}
def inputfile(text):
    outfile = str(input('Enter the name of the output file:'))# getting the name for the output file
    convertedtext = open(outfile, 'w')# using write operation to save the output text
    for line in text:
        for a in line:# encrypting character by character
            output = (Encrypt_Code.get(a, a))
            convertedtext.write(output)

    convertedtext.close()# closing the file when the function is over
def main():
    infile = str(input('Enter the name of the input file:'))# getting the name of the input file
    text = open(infile, 'r')
    text = text.readlines()
    inputfile(text)


main()
