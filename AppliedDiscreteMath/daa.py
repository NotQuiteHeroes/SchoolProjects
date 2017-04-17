'''
Paige Eckstein
Applied Discrete Mathematics
4/5/17
Example of Deferred Acceptance Algorithm
(or Gale Shapely Algorithm)
'''

#==============================================================================
#=============================Base Entity Class================================
#==============================================================================
#Base Entity for both students and instructors
#contains three fields:
#name
#priorities: list of instructors to be matched with, from most to least desired
#match: holds current Instructor the student is matched with
class BaseEntity:
    def __init__(self, name, priorities):
        self.name = name
        self.priorities = priorities
        self.match = None

#==============================================================================
#==============================Student Class===================================
#==============================================================================
#Inherits from BaseEntity, use BaseEntity's initializer for name and priorities
#matchIndex field used to iterate through list of priorities
class Student(BaseEntity):
    def __init__(self, name, priorities):
        BaseEntity.__init__(self, name, priorities)
        self.matchIndex = 0

    #goal is next instructor in priority list
    def nextMatch(self):
        goal = self.priorities[self.matchIndex]
        self.matchIndex += 1
        return goal

#==============================================================================
#==============================Instructor Class================================
#==============================================================================
#Inherits from BaseEntity, use BaseEntity's initializer for name and priorities
#ranking works as reverse lookup to save time
class Instructor(BaseEntity):
    def __init__(self, name, priorities):
        BaseEntity.__init__(self, name, priorities)
        self.ranking = {}
        for rank in range(len(priorities)):
            self.ranking[priorities[rank]] = rank

    #returns true if the instructor does not currently have a match
    #or if the student currently asking to be matched is of higher priority
    #than the instructor's currently matched student
    def evaluateMatch(self, matcher):
        return self.match==None or self.ranking[matcher]<self.ranking[self.match]

#==============================================================================
#==============================Main functions==================================
#==============================================================================
#gets list of individuals with their ranked priority lists
def getInfo(type):
    entities = []
    totalEntities = input("How many "+type+"s will you be entering?\n")
    print("Enter each " + type +" in the format Name : pref1, pref2, pref3,...,")
    for _ in range(0, totalEntities):
        fullInfo = raw_input().split(':')
        name = fullInfo[0].strip()
        if name:
            priorities = fullInfo[1].strip().split(',')
            for i in range(len(priorities)):
                priorities[i] = priorities[i].strip()
                entities.append((name, priorities))
    return entities

#print student, instructor pairings
def printPairings(students):
    print
    for student in students.values():
        print student.name, 'is paired with', str(student.match)

#==============================================================================
#====================================Main======================================
#==============================================================================
def main():
    #get list of student's along with their respective lists of priorities
    studentList = getInfo("student")

    #dictionary to hold Student objects
    students = dict()

    #fill students dictionary with Student objects, where the student's name
    #is the key and a Student object is initialized as the value
    for student in studentList:
        students[student[0]] = Student(student[0], student[1])

    #unmatchedStudents initially are all of them, so set to all student names
    unmatchedStudents = students.keys()

    #get list of instructor's along with their respective lists of priorities
    instructorList = getInfo("instructor")

    #dictionary to hold Instructor objects
    instructors = dict()

    #fill instructors dictionary with Instructor objects, where the instructor's
    #name is the key and an Instructor object is initialized as the value
    for instructor in instructorList:
        instructors[instructor[0]] = Instructor(instructor[0], instructor[1])

    print

    #main part of algorithm
    while unmatchedStudents:
        #current student to match is the first student in the list of
        #unmatched students
        currentStudent = students[unmatchedStudents[0]]

        #current instructor to match is the instructor next in the current
        #student's priority list
        currentInstructor = instructors[currentStudent.nextMatch()]

        print currentStudent.name, 'offers match with', currentInstructor.name

        #evaluate match
        #successful match:
        if currentInstructor.evaluateMatch(currentStudent.name):
            print ' ', currentInstructor.name, 'accepts the match.'

            #if the current instructor already has a match with a student
            #unmatch them, and return the student to the unmatchedStudents list
            if currentInstructor.match:
                oldStudent = students[currentInstructor.match]
                oldStudent.match = None
                unmatchedStudents.append(oldStudent.name)

            #remove the newly matched student from unmatchedStudents
            unmatchedStudents.remove(currentStudent.name)

            #set each entities match to the appropriate name
            currentInstructor.match = currentStudent.name
            currentStudent.match = currentInstructor.name

        #unsuccessful match:
        else:
            print ' ', currentInstructor.name, 'rejects the match.'

        #print tentative matches after each round
        print
        print "Tentative Matches:"
        printPairings(students)
        print

    #once there are no elements in unmatchedStudents, algorithm is complete
    #print out final matches
    print "Final Matches:"
    printPairings(students)

main()
