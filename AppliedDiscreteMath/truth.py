'''
Paige Eckstein
Applied Discrete Mathematics
4/12/17
'''

#=============================================================================#
#======================Expression One Simplification==========================#
#=============================================================================#
'''
(a+(~a*(~b+b))) * b

~b + b = 1 (complement)
(a+(~a*(1))) * b
~a * 1 = ~a (identity)
(a+(~a)) * b
a + ~a = 1 (complement)
(1) * b = b (identity)

(a+(~a*(~b+b))) * b == b
'''
#=========================Truth Check Expression One==========================#
def checkTruthOne(a, b):
    return(int((a or(not a and (not b or b))) and b))

#=============================================================================#
#=======================Expression Two Simplification=========================#
#=============================================================================#
'''
~(a+b*c) + a * (b+~c)

~(a+b*c) = ~(a * b + a * c) (distributivity)
~(a * b + a * c) = ~a * ~b * ~c (idempotence and DeMorgan's)
~a * ~b * ~c + a * (b + ~c)
~a * ~b + a * b + ~c (idempotence and associativity)

~(a+b*c) + a * (b+~c) == ~a * ~b + a * b + ~c
'''
#=========================Truth Check Expression Two==========================#
def checkTruthTwo(a, b, c):
    return(int(not(a or b and c) or a and (b or not c)))

#=============================================================================#
#=====================Expression Three Simplification=========================#
#=============================================================================#
'''
(a+b) * (a*c+a*~c) + a * b + b

(a * c + a * ~c) = a * (c + ~c) (distributivity)
a * (c + ~c) = a * 1 (complement)
a * 1 = a (identity)
(a+b) * a + a * b + b
a + a = a and b + b = b (idempotence)
(a+b) * a * b
a * a = a and b * b = b (idempotence)
a + b

(a+b) * (a*c+a*~c) + a * b + b == a+b
'''
#=========================Truth Check Expression Three========================#
def checkTruthThree(a, b, c):
    return(int((a or b) and (a and c or a and not c) or a and b or b))

#=============================================================================#
#======================Expression Four Simplification=========================#
#=============================================================================#
'''
(a*b*c*d)+(a*b*c*~d)+(a*b*~c*d)+(a*b*~c*~d)+(a*~b*c*d)+(a*~b*c*~d)+(a*~b*d)

a * (b + c + d) * (b + c + ~d) * (b + ~c + d) * (b + ~c + ~d) * (~b + c + d) *
(~b + c + ~d) * (~b + d) (distributivity)
Working right to left:
~b + c + ~d * ~b + d = ~b + c (Idempotence, complement)
~b + c * ~b + c + d = ~b + c + d (Idempotence)
~b + c + d * b + ~c + ~d = 0 0 0 (complement)
b + c + ~d * b + ~c + d = b (idempotence, complement)
b * b + c + d = b + c + d (idempotence)
a * (b+c+d)

(a*b*c*d)+(a*b*c*~d)+(a*b*~c*d)+(a*b*~c*~d)+(a*~b*c*d)+(a*~b*c*~d)+(a*~b*d)
== a * (b+c+d)
'''
#=========================Truth Check Expression Four=========================#
#use simplified expression for brevity's sake
def checkTruthFour(a, b, c, d):
    return(int(a and (b or c or d)))

#=============================================================================#
#=============================Print Truth Tables==============================#
#=============================================================================#

#==================================Table One==================================#
def truthTableOne():
    print("   A   |   B   | Output")
    print("-------------------------")
    for a in range(0, 2):
        for b in range(0, 2):
            print("   %d   |   %d   |   %d   " % (a, b, checkTruthOne(a, b)))
    print
    print

#==================================Table Two==================================#
def truthTableTwo():
    print("   A   |   B   |   C   | Output")
    print("---------------------------------")
    for a in range(0, 2):
        for b in range(0, 2):
            for c in range(0, 2):
                print("   %d   |   %d   |   %d   |   %d" % (a, b, c, checkTruthTwo(a, b, c)))
    print
    print

#=================================Table Three=================================#
def truthTableThree():
    print("   A   |   B   |   C   | Output")
    print("---------------------------------")
    for a in range(0, 2):
        for b in range(0, 2):
            for c in range(0, 2):
                print("   %d   |   %d   |   %d   |   %d" % (a, b, c, checkTruthThree(a, b, c)))
    print
    print

#==================================Table Four=================================#
def truthTableFour():
    print("   A   |   B   |   C   |   D   | Output")
    print("-----------------------------------------")
    for a in range(0, 2):
        for b in range(0, 2):
            for c in range(0, 2):
                for d in range(0, 2):
                    print("   %d   |   %d   |   %d   |   %d   |   %d" % (a, b, c, d, checkTruthFour(a, b, c, d)))
    print
    print

#=============================================================================#
#=====================================Main====================================#
#=============================================================================#
def main():
    print("1. (a+(~a*(~b+b))) * b")
    truthTableOne()

    print("2. ~(a+b*c) + a * (b+~c)")
    truthTableTwo()

    print("3. (a+b) * (a*c+a*~c) + a * b + b")
    truthTableThree()

    print("4. (a*b*c*d)+(a*b*c*~d)+(a*b*~c*d)+(a*b*~c*~d)+(a*~b*c*d)+(a*~b*c*~d)+(a*~b*d)")
    truthTableFour()

main()
