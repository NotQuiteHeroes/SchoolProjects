'''
Paige Eckstein
Applied Discrete Math
4/22/17
We have enlisted your help to decode
an intercepted message sent from Bob to his coworker Irene.
We know Irene's public RSA key is (n = 111851429, e = 73997).
Encoded messages we have cracked between these two
in the past use an unconventional scheme, and we expect
the same scheme to be used here.
There is no random padding used.
Each line is padded at the end until its length is an integer
multiple of the plaintext block size and then encrypted.
The usual plaintext block size is 4 characters,
which they always map to a ciphertext block of 5 characters,
They encrypt using the ASCII alphanumeric characters,
such that a space (ASCII code 032) maps to 0, "!"
(ASCII code 033) maps to 1, and so on through "~" (ASCII code 126)
mapping to 94.
'''

from math import floor
from math import sqrt

BLOCK_SIZE = 4
#=======================================================================
#==================================Main=================================
#=======================================================================
def main():

    #n and e given
    n = 111851429
    e = 73997

    #calculate d
    d = getValues(n, e)

    #get ciphertext
    message = getText()

    #decode line by line
    for elem in message:
        fullDecode(elem, n, d)

#=======================================================================
#===============================Get Values==============================
#=======================================================================
def getValues(n, e):
    #find first prime factor of p
    #start at square root and work down
    #if not odd initially, subtract one to get odd number
    p = floor(sqrt(n))
    if(p % 2 == 0):
        p-=1

    #until we reach prime factor, subtract by two
    #to remain odd
    while(n % p != 0):
        p-=2

    #calculate q given values n and p
    q = n/p

    #calculate totient
    totient = (q-1)*(p-1)

    #calculate d
    #use found as flag until an appropriate d value is found
    found = False
    x = 1
    while found == False:
        d = ((1+x*totient)/e)
        #once we have a whole number, we have an appropriate d value
        if d.is_integer():
            found = True
        x+=1

    return int(d)

#=======================================================================
#==============================Get Text=================================
#=======================================================================
def getText():
    message = []
    with open("encoded.txt") as file:
        for line in file:
            #strip trailing newline from each line before appending
            #specify \n in rstrip to retain other whitespace
            message.append(line.rstrip('\n'))
    file.close()
    return message

#=======================================================================
#=============================Block Encode==============================
#=======================================================================
def block_encode(x):
    output = 0
    length = len(x)
    for i in range(length):
        #32 and 95 given for encoding scheme
        #ord maps character to ASCII
        k = ord(x[i]) - 32
        output = output + k*pow(95, length-i-1)
    return int(output)

#=======================================================================
#============================Block Decode===============================
#=======================================================================
def block_decode(x):
    output = ""
    i = BLOCK_SIZE + 1
    while i > 0:
        b1 = int(pow(95, i-1))
        y = int(x/b1)
        i = i - 1
        x = x - y * b1
        #chr maps ASCII to character
        output = output + chr(y + 32)
    return output

#=======================================================================
#===============================Full Decode=============================
#=======================================================================
def fullDecode(message, n, d):
    decodedMsg = []

    #given that messages will be padded until length is a multiple of
    #BLOCk_SIZE + 1
    length = len(message)
    while(length % 5 != 0):
        #add space to beginning of message to pad
        message = ''.join((' ', message))
        length = len(message)

    i = 0
    j = BLOCK_SIZE + 1

    for i in range(i, len(message), j):
        #get block as BLOCK_SIZE + 1 characters from message
        block = message[i:i+j]

        #encode the block
        encoded = block_encode(block)

        #use keys to get decoded numeric form
        #Note: use three value version of pow instead of
        # encoded**d % n
        # to avoid overflow and save time
        toDecode = (pow(encoded, d, n))

        #decode numeric form into character form
        decoded = block_decode(toDecode)

        #add decoded block to full decoded message
        decodedMsg.append(decoded)

    #print fully decoded message line
    print(''.join(decodedMsg)  )

main()
