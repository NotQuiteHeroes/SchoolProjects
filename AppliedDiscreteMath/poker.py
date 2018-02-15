from collections import Counter
import itertools

'''
Paige Eckstein
4/30/17
Applied Discrete Mathematics

This Program simulates a simplified two-player version of
Texas Hold'em at the end of a round.
It will calculate, given a player's cards and the community
cards, the probabilities of the opponent's holding a hand
of each possible type as well as the probability of victory.

Player cards:     (P1, P2)
Opponent's Cards: (O1, O2)
Community Cards:  (C1, C2, C3, C4, C5)
types of hands:   (straight flush, four of a kind, full house,
                   flush, straight, three of a kind, two pair,
                   one pair, nothing)
Simplify poker rules by assuming all hands of equal rank are
equivalent, with no high card rules.
     For Example, any two one-pair hands tie without regard
     to rank of cards
'''

#------------------------------------------------------------------------------
#- find_most_common(hand)
#-
#- Input:  (hand) is list of cards
#- Output: (handData.most_common(1)[0]) is tuple containing most common element
#-         and its number of occurrences
#-
#- handData is Counter object
#- most_common method returns list of tuples of the form word, count
#- passing 1 to most_common signifies returning top most common element
#- indexing with [0] returns tuple instead of list containing one tuple
#-
#------------------------------------------------------------------------------


def find_most_common(hand):
    handData = Counter(hand)
    return handData.most_common(1)[0]

#------------------------------------------------------------------------------
#- get_rank(hand)
#-
#- Input:  (hand) is list of cards
#- Output: hand, still in list form, converted so that K, Q, J, T, and A
#-         are replaced with their numerical value
#-
#- numbers acts as dictionary look up to convert face cards to their value
#- Checks first character of each card string
#- If first character is T(for ten), J, Q, K, or A then convert to its
#- numerical value
#- Does not change card with numerical first character
#-
#------------------------------------------------------------------------------


def get_rank(hand):
    numbers = {'T': 10, 'J': 11, 'Q': 12, 'K': 13, 'A': 14}
    for i in range(len(hand)):
        if(hand[i][0]) in numbers.keys():
            hand[i] = str(numbers[hand[i][0]]) + hand[i][1]
    return hand

#------------------------------------------------------------------------------
#- is_straightFlush(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if hand is both a straight and a flush, otherwise False
#-
#------------------------------------------------------------------------------


def is_straightFlush(hand):
    convertedHand = get_rank(hand)

    if is_sequence(convertedHand):
        if is_flush(convertedHand):
            return True, hand
    else:
        return False

#------------------------------------------------------------------------------
#- is_sequence(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if hand is a straight, otherwise False along with hand
#-
#- [x[:-1] for x in get_rank(h)] will return list of string values of hand
#- [int(x) for x in hand] will convert the above strings to integers
#- Sort hand then check for sequence
#- if none found, change ace from 14 to 1 to check for sequence other way
#- if still none found, return false. If sequence found, return true
#-
#------------------------------------------------------------------------------


def is_sequence(hand):
    sequence = True
    ace = False
    handCopy = hand[:]

    hand = [x[:-1] for x in get_rank(hand)]
    hand = [int(x) for x in hand]

    hand.sort()
    for x in range(0, len(hand) - 1):
        if not hand[x] + 1 == hand[x + 1]:
            sequence = False

    if sequence:
        return True, handCopy

    aces = [i for i in hand if str(i) == "14"]
    if len(aces) == 1:
        for x in range(len(hand)):
            if str(hand[x]) == "14":
                hand[x] = 1

    hand.sort()
    for x in range(0, len(hand) - 1):
        if not hand[x] + 1 == hand[x + 1]:
            return False

    return sequence, handCopy

#------------------------------------------------------------------------------
#- is_flush(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if hand is all of same suit, False otherwise
#-
#- [x[-1] for x in hand] will return list of just suit information from hand
#- calling set on suits gives only unique suits
#- if length of that set is 1, then all the suits are the same
#-
#------------------------------------------------------------------------------


def is_flush(hand):
    suits = [x[-1] for x in hand]
    if len(set(suits)) == 1:
        return True, hand
    else:
        return False

#------------------------------------------------------------------------------
#- is_fourOfAKind(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if four of a kind, False otherwise
#-
#- [x[:-1] for x in hand] returns list of card values as strings
#- mostCommon finds the most common element in the list of card values
#- mostCommon[1] is number of occurrences of value
#- if its four, then there is a four of a kind
#- mostCommon[0] is the most common value
#-
#------------------------------------------------------------------------------


def is_fourOfAKind(hand):
    handCopy = hand[:]
    hand = [x[:-1] for x in hand]
    mostCommon = find_most_common(hand)
    if mostCommon[1] == 4:
        return True, handCopy
    else:
        return False

#------------------------------------------------------------------------------
#- is_threeOfAKind(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if three of a kind, False otherwise
#-
#- [x[:-1] for x in hand] returns list of card values as strings
#- mostCommon finds the most common element in the list of card values
#- mostCommon[1] is number of occurrences of value
#- if its three, then there is a three of a kind
#- mostCommon[0] is the most common value
#-
#------------------------------------------------------------------------------


def is_threeOfAKind(hand):
    handCopy = hand[:]
    hand = [x[:-1] for x in get_rank(hand)]
    mostCommon = find_most_common(hand)
    if mostCommon[1] == 3:
        return True, handCopy
    else:
        return False

#------------------------------------------------------------------------------
#- is_fullHouse(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if full house, False otherwise
#-
#- [x[:-1] for x in hand] returns list of card values as strings
#- handData is Counter object given hand
#- a = handData.most_common(1)[0] gives most common element
#- b = handData.most_common(2)[-1] gives second most common element
#- a[1] gives occurrence of most common element, and b[1] gives count of
#- second most common element
#- if a[1] = 3 and b[1] = 2, then full house
#-
#------------------------------------------------------------------------------


def is_fullHouse(hand):
    handCopy = hand[:]
    hand = [x[:-1] for x in get_rank(hand)]
    handData = Counter(hand)
    a, b = handData.most_common(1)[0], handData.most_common(2)[-1]
    if str(a[1]) == '3' and str(b[1]) == '2':
        return True, handCopy
    return False

#------------------------------------------------------------------------------
#- is_twoPair(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if two pair, False otherwise
#-
#- [x[:-1] for x in hand] returns list of card values as strings
#- handData is Counter object given hand
#- a = handData.most_common(1)[0] gives most common element
#- b = handData.most_common(2)[-1] gives second most common element
#- a[1] gives occurrence of most common element
#- b[1] gives count of second most common element
#- if a[1] = 2 and b[1] = 2, then two pair
#-
#------------------------------------------------------------------------------


def is_twoPair(hand):
    handCopy = hand[:]
    hand = [x[:-1] for x in get_rank(hand)]
    handData = Counter(hand)
    a, b, = handData.most_common(1)[0], handData.most_common(2)[-1]
    if str(a[1]) == '2' and str(b[1]) == '2':
        return True, handCopy
    return False

#------------------------------------------------------------------------------
#- is_pair(hand)
#-
#- Input:  (hand) is list of cards
#- Output: True if pair, False otherwise
#-
#- [x[:-1] for x in hand] returns list of card values as strings
#- mostCommon gives the most commonly occuring element
#- and its count of occurrences in the hand
#- mostCommon[1] gives count of occurrences
#- if its 2, then pair found
#-
#------------------------------------------------------------------------------


def is_pair(hand):
    handCopy = hand[:]
    hand = [x[:-1] for x in get_rank(hand)]
    #mostCommon = find_most_common(hand)
    handData = Counter(hand)
    mostCommon = handData.most_common(1)[0]
    if str(mostCommon[1]) == "2":
        return True, handCopy
    else:
        return False

#------------------------------------------------------------------------------
#- get_high(hand)
#-
#- Input:  (hand) is list of cards
#- Output: highest card value in hand
#-
#- sorted sorts list, reverse = True sorts in descending order
#- [int(x[:-1]) for x in get_rank(hand)] gives list of integer values of hand
#- indexing sorted list with [0] returns the highest card value
#-
#------------------------------------------------------------------------------


def get_high(hand):
    return list(sorted([int(x[:-1]) for x in get_rank(hand)], reverse=True))[0]

#------------------------------------------------------------------------------
#- evaluate_hand(hand)
#-
#- Input:  (hand) list of cards
#- Output: Type of hand, the relevant cards for the type of hand, and the score
#-
#- '_' is throwaway variable, used to catch a return value we no longer need
#-  usually a True or False that has already been evaluated
#-
#- STRAIGHT FLUSH  = 9
#- FOUR OF A KIND  = 8
#- FULL HOUSE      = 7
#- FLUSH           = 6
#- STRAIGHT        = 5
#- THREE OF A KIND = 4
#- TWO PAIR        = 3
#- ONE PAIR        = 2
#- HIGH CARD       = 1
#-
#------------------------------------------------------------------------------


def evaluate_hand(hand):
    if is_straightFlush(hand):
        return "STRAIGHT FLUSH", hand, 9
    elif is_fourOfAKind(hand):
        return "FOUR OF A KIND", hand, 8
    elif is_fullHouse(hand):
        return "FULL HOUSE", hand, 7
    elif is_flush(hand):
        return "FLUSH", hand, 6
    elif is_sequence(hand):
        return "STRAIGHT", hand, 5
    elif is_threeOfAKind(hand):
        return "THREE OF A KIND", hand, 4
    elif is_twoPair(hand):
        return "TWO PAIR", hand, 3
    elif is_pair(hand):
        return "PAIR", hand, 2
    else:
        return "HIGH CARD", hand, 1

#------------------------------------------------------------------------------
#- compare_hands(hand1, hand2)
#-
#- Input:  (hand1, hand2) two separate lists of cards
#- Output: Winning hand, along with the winning hand type and cards, or Tie
#-
#- sorted sorts list, reverse = True sorts in descending order
#-
#------------------------------------------------------------------------------


def compare_hands(hand1, hand2):
    hand1Eval, hand2Eval = evaluate_hand(hand1), evaluate_hand(hand2)
    if hand1Eval[2] == hand2Eval[2]:
        return "Tie", hand2Eval[0], hand2Eval[1]
    elif hand1Eval[2] > hand2Eval[2]:
        return "Hand1", hand1Eval[0], hand1Eval[1]
    else:
        return "Hand2", hand2Eval[0], hand2Eval[1]

#------------------------------------------------------------------------------
#- find_best_hand(table, hand)
#-
#- Input:  (table, hand) table is list of five table cards, hand is list of
#-         two player cards
#- Output: Best five card hand made from table and hand cards
#-
#- Hardcode possible hand combinations using one player card, or both player
#- cards rather than deal with nested loops
#- Find best hand from all possibilities using one player card
#- Then find best hand from all possibilities using both player cards
#- Finally compare best one card hand to best two card hand
#- Tie doesn't matter, so assign best hand to first card in that instance
#-
#------------------------------------------------------------------------------


def find_best_hand(table, hand):
    oneCardHands = [[hand[0], table[0], table[1], table[2], table[3]],
                    [hand[0], table[0], table[1], table[2], table[4]],
                    [hand[0], table[0], table[1], table[3], table[4]],
                    [hand[0], table[0], table[2], table[3], table[4]],
                    [hand[0], table[1], table[2], table[3], table[4]],
                    [hand[1], table[0], table[1], table[2], table[3]],
                    [hand[1], table[0], table[1], table[2], table[4]],
                    [hand[1], table[0], table[1], table[3], table[4]],
                    [hand[1], table[0], table[2], table[3], table[4]],
                    [hand[1], table[1], table[2], table[3], table[4]]]

    twoCardHands = [[hand[0], hand[1], table[0], table[1], table[2]],
                    [hand[0], hand[1], table[0], table[1], table[3]],
                    [hand[0], hand[1], table[0], table[1], table[4]],
                    [hand[0], hand[1], table[0], table[2], table[3]],
                    [hand[0], hand[1], table[0], table[2], table[4]],
                    [hand[0], hand[1], table[0], table[3], table[4]],
                    [hand[0], hand[1], table[1], table[2], table[3]],
                    [hand[0], hand[1], table[1], table[2], table[4]],
                    [hand[0], hand[1], table[1], table[3], table[4]],
                    [hand[0], hand[1], table[2], table[3], table[4]]]

    bestOneCardHand = [hand[0], table[0], table[0], table[1], table[2]]
    for i in range(0, len(oneCardHands) - 1):
        currentHand = compare_hands(oneCardHands[i], oneCardHands[i + 1])
        if currentHand[0] == "Hand2":
            comparison = compare_hands(bestOneCardHand, oneCardHands[i + 1])
            if comparison[0] == "Hand2":
                bestOneCardHand = oneCardHands[i + 1]
        else:
            comparison = compare_hands(bestOneCardHand, oneCardHands[i])
            if comparison[0] == "Hand2":
                bestOneCardHand = oneCardHands[i]

    bestTwoCardHand = [hand[0], hand[1], table[0], table[1], table[2]]
    for j in range(0, len(twoCardHands) - 1):
        currentHand = compare_hands(twoCardHands[j], twoCardHands[j + 1])
        if currentHand[0] == "Hand2":
            comparison = compare_hands(bestTwoCardHand, twoCardHands[j + 1])
            if comparison[0] == "Hand2":
                bestTwoCardHand = twoCardHands[j + 1]
        else:
            comparison = compare_hands(bestTwoCardHand, twoCardHands[j])
            if comparison[0] == "Hand2":
                bestTwoCardHand = twoCardHands[j]

    currentHand = compare_hands(bestOneCardHand, bestTwoCardHand)
    if currentHand[0] == "Hand2":
        return bestTwoCardHand
    else:
        return bestOneCardHand

#------------------------------------------------------------------------------
#- opponent_odds(table, myHand)
#-
#- Input:  (table, myHand) table is list of five table cards and hand is
#-         two cards in player's hand
#- Output: Nothing. Simply prints odds table for each hand the opponent can make
#-
#- Lists hold each type of hand that can be made
#- RemainingCards is set of all remaining cards (minus myHand and table)
#- HandCombinations list holds all possible combinations of two cards from
#- the remaining cards
#- Evaluates each hand with each possible two card combination and tallies
#- each hand evaluation
#- totalPossibleHands is total of different types of hands opponent can make
#- odds are calculated by taking each individual hand type and dividing by
#- the total possible hands
#-
#- **Note, to create set of each type of hand must first map sublists to tuples
#-
#------------------------------------------------------------------------------


def opponent_odds(table, myHand):

    straightFlush = []
    fourOfAKind = []
    fullHouse = []
    flush = []
    straight = []
    threeOfAKind = []
    twoPair = []
    onePair = []
    nothing = []

    cards = {"KH", "KD", "KS", "KC", "QH", "QD", "QS", "QC", "JH", "JD", "JS",
             "JC", "TH", "TD", "TS", "TC", "9H", "9D", "9S", "9C", "8H", "8D", "8S",
             "8C", "7H", "7D", "7S", "7C", "6H", "6D", "6S", "6C", "5H", "5D", "5S",
             "5C", "4H", "4D", "4S", "4C", "3H", "3D", "3S", "3C", "2H", "2D", "2S",
             "2C", "AH", "AD", "AS", "AC"}

    tableCopy = table[:]
    tableCopy = set(tableCopy)
    myHand = set(myHand)

    remainingCards = cards.difference(tableCopy)
    remainingCards = remainingCards.difference(myHand)

    handCombinations = list(itertools.combinations(remainingCards, 2))

    for i in range(0, len(handCombinations)):

        hand = [handCombinations[i][0], handCombinations[i][1]]

        oneCardHands = [[hand[0], table[0], table[1], table[2], table[3]],
                        [hand[0], table[0], table[1], table[2], table[4]],
                        [hand[0], table[0], table[1], table[3], table[4]],
                        [hand[0], table[0], table[2], table[3], table[4]],
                        [hand[0], table[1], table[2], table[3], table[4]],
                        [hand[1], table[0], table[1], table[2], table[3]],
                        [hand[1], table[0], table[1], table[2], table[4]],
                        [hand[1], table[0], table[1], table[3], table[4]],
                        [hand[1], table[0], table[2], table[3], table[4]],
                        [hand[1], table[1], table[2], table[3], table[4]]]

        for j in range(0, len(oneCardHands)):
            currentHand = oneCardHands[j]
            currentEval = evaluate_hand(currentHand)
            currentHandType = currentEval[0]
            if(currentHandType == "STRAIGHT FLUSH"):
                straightFlush.append(currentHand)
            elif(currentHandType == "FOUR OF A KIND"):
                fourOfAKind.append(currentHand)
            elif(currentHandType == "FULL HOUSE"):
                fullHouse.append(currentHand)
            elif(currentHandType == "FLUSH"):
                flush.append(currentHand)
            elif(currentHandType == "STRAIGHT"):
                straight.append(currentHand)
            elif(currentHandType == "THREE OF A KIND"):
                threeOfAKind.append(currentHand)
            elif(currentHandType == "TWO PAIR"):
                twoPair.append(currentHand)
            elif(currentHandType == "PAIR"):
                onePair.append(currentHand)
            elif(currentHandType == "HIGH CARD"):
                nothing.append(currentHand)

        twoCardHands = [[hand[0], hand[1], table[0], table[1], table[2]],
                        [hand[0], hand[1], table[0], table[1], table[3]],
                        [hand[0], hand[1], table[0], table[1], table[4]],
                        [hand[0], hand[1], table[0], table[2], table[3]],
                        [hand[0], hand[1], table[0], table[2], table[4]],
                        [hand[0], hand[1], table[0], table[3], table[4]],
                        [hand[0], hand[1], table[1], table[2], table[3]],
                        [hand[0], hand[1], table[1], table[2], table[4]],
                        [hand[0], hand[1], table[1], table[3], table[4]],
                        [hand[0], hand[1], table[2], table[3], table[4]]]

        for k in range(0, len(twoCardHands)):
            currentHand = twoCardHands[k]
            currentEval = evaluate_hand(currentHand)
            currentHandType = currentEval[0]
            if(currentHandType == "STRAIGHT FLUSH"):
                straightFlush.append(currentHand)
            elif(currentHandType == "FOUR OF A KIND"):
                fourOfAKind.append(currentHand)
            elif(currentHandType == "FULL HOUSE"):
                fullHouse.append(currentHand)
            elif(currentHandType == "FLUSH"):
                flush.append(currentHand)
            elif(currentHandType == "STRAIGHT"):
                straight.append(currentHand)
            elif(currentHandType == "THREE OF A KIND"):
                threeOfAKind.append(currentHand)
            elif(currentHandType == "TWO PAIR"):
                twoPair.append(currentHand)
            elif(currentHandType == "PAIR"):
                onePair.append(currentHand)
            elif(currentHandType == "HIGH CARD"):
                nothing.append(currentHand)

    straightFlush = len(set(map(tuple, straightFlush)))
    fourOfAKind = len(set(map(tuple, fourOfAKind)))
    fullHouse = len(set(map(tuple, fullHouse)))
    flush = len(set(map(tuple, flush)))
    straight = len(set(map(tuple, straight)))
    threeOfAKind = len(set(map(tuple, threeOfAKind)))
    twoPair = len(set(map(tuple, twoPair)))
    onePair = len(set(map(tuple, onePair)))
    nothing = len(set(map(tuple, nothing)))

    totalPossibleHands = straightFlush + fourOfAKind + fullHouse + \
        flush + straight + threeOfAKind + twoPair + onePair + nothing

    straightFlushOdds = float(straightFlush) / totalPossibleHands
    fourOfAKindOdds = float(fourOfAKind) / totalPossibleHands
    fullHouseOdds = float(fullHouse) / totalPossibleHands
    flushOdds = float(flush) / totalPossibleHands
    straightOdds = float(straight) / totalPossibleHands
    threeOfAKindOdds = float(threeOfAKind) / totalPossibleHands
    twoPairOdds = float(twoPair) / totalPossibleHands
    onePairOdds = float(onePair) / totalPossibleHands
    highCardOdds = float(nothing) / totalPossibleHands

    print("Opponent Hands Information: ")
    print("Total Possible Hands: ", totalPossibleHands)
    print("Straight Flush: ")
    print("     Total Hands: ", straightFlush)
    print("     Probability: ", straightFlushOdds)
    print("Four of a kind: ")
    print("     Total Hands: ", fourOfAKind)
    print("     Probability: ", fourOfAKindOdds)
    print("Full House: ")
    print("     Total Hands: ", fullHouse)
    print("     Probability: ", fullHouseOdds)
    print("Flush: ")
    print("     Total Hands: ", flush)
    print("     Probability: ", flushOdds)
    print("Straight: ")
    print("     Total Hands: ", straight)
    print("     Probability: ", straightOdds)
    print("Three of a Kind: ")
    print("     Total Hands: ", threeOfAKind)
    print("     Probability: ", threeOfAKindOdds)
    print("Two Pair: ")
    print("     Total Hands: ", twoPair)
    print("     Probability: ", twoPairOdds)
    print("One Pair: ")
    print("     Total Hands: ", onePair)
    print("     Probability: ", onePairOdds)
    print("High Card: ")
    print("     Total Hands: ", nothing)
    print("     Probability: ", highCardOdds)


def main():
    myHand = ["QC", "QS"]
    table = ["KD", "KC", "QH", "7D", "4S"]
    print("My Best Hand: ")
    print(evaluate_hand(find_best_hand(table, myHand)))
    opponent_odds(table, myHand)


main()
