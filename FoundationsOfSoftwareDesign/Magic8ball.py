import random

def main():
    count = 0
    answered = []
    while(count < 9):
        getQuestion()
        answer = answerSelection(answered)
        giveAnswer(answer)
        count+=1
    print("The magic must recharge. Come back later for more wisdom of the magic 8-Ball.")

def getQuestion():
    raw_input("Enter your question for the wisdom of the magic 8-Ball:\n")

def answerSelection(answered):
    answers = ["Yes.", "No.", "Without a doubt.", "Yes, definitely.", "Outlook good.", "Don't count on it." , "My sources say no.", "Very doubtful.", "Ask again later.", "Concentrate and ask again."]
    size = 9

    tempAnswer = random.choice(answers)
    while(tempAnswer in answered):
        tempAnswer = random.choice(answers)
    answered.append(tempAnswer)
    return tempAnswer

def giveAnswer(answer):
    print(answer + "\n")

main()
