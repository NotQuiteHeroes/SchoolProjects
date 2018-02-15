# RSA 

Rivest-Shamir-Adleman public-key cryptosystem. In this system, the encryption key is public and is different from the
decryption key, which is kept secret. The asymmetry in this system is based on the practical difficulty of the factorization of
the product of two large prime numbers. [wikipedia](https://en.wikipedia.org/wiki/RSA_(cryptosystem))

For this program, the encoded message has been provided (in encoded.txt). The public key is also provided. It is known that
there is no random padding - each line is padded at the end until its lenght is an integer multiple of the plaintext block size
and then encrypted. The usual plaintext block size is 4 characters, which the message sender maps to a ciphertext block of 5 characters.
The message sender encrypts using the ASCII alphanumeric characters. 

Given information:
+ n = 111851429
+ e = 73997

Calculated during run-time:
+ p : start as square root of n and work downward until first prime factor is found.
+ q : n/p
+ totient: (q-1)*(p-1)
+ d : start with an x value of 1 and work way up. d = ((1+x*totient)/e). Add one to x and repeat until a whole number is found.

The encoded text is then pulled from the file and stripped of any trailing whitespace, while keeping pertinent whitespace. Each line
is placed in a list. 

Each line in the encoded list is then decoded. This process involves first checking the size of each element and padding with
whitespace in front until lenght is a multiple of block_size + 1 (5). The line is then broken down into block_size + 1 characters and
the characters are encoded given the encoding specifications, mapping each character to its corresponding ASCII value. These encoded
characters are then decoded, being mapped back to their character representations. This process is repeated for each line until the 
message has been fully decoded and displayed for the user.

## Compilation and Execution:
Works for both python2.7 and python3.x
python decode.py

*Note this requires the encoded message to be in the same directory as the application.

## Usage:
### Input:
None - no input is required from the user.

### Output:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/mathRSA.JPG "RSA Decoding")

