# Operating System Design
The main focus of this course was creating a Linux system using OpenSuse, but it also entailed emulating certain Operating System functions. 

## Access
This program illustrates file access rights. It implements a Users struct that contains two boolean arrays that hold three values each, representing Read, Write, and Execute access for two separate files. The program then checks User A's access to execute the second file, User B's access to read both files, and User C's access to write to the first file. All values are hardcoded per the assignment, and no user interaction is necessary.

### Compilation:
gcc access.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignAccess.JPG "File Access")

## (FCFS) First-Come-First-Served Scheduling Algorithm
This program illustrates a first-come-first-served scheduling algorithm implemented by an operating system. It contains a hardcoded array of times for each process, which are handled in a first-come-first-served basis. The program requires no user input, and outputs the average waiting time, and average turn around time for all processes.

### Compilation:
gcc fcfs.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignfcfs.JPG "FCFS Scheduling")

## (FIFO) First-In-First-Out Page Replacement Algorithm
This program illustrates the frame replacement and page faults that occur during a first-in-first-out page replacement algorithm. With this algorithm, the oldest page is the first to be replaced. The program contains hardcoded page reference strings, as per the assingment instructions, as well as a hardcoded frame alotment. It will print out three columns representing each frame and what it currently holds, as well as illustrating which page will be replaced. When a page is removed from a frame to make room for a new one, it counts as a page fault, which is tallied and displayed at the end.

### Compilation:
gcc fifo.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignfifo.JPG "FIFO Page Replacement")

## Files
This program illustrates I/O operations for adding a file to the end of a contiguous file system and linked list file system. The assignment assumes the linked list does not implement FAT, and it is given that there are 100 files in the system. It calculates the number of operations necessary to add a file to the end of each type of file system and displays the results.

### Compilation:
gcc files.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignFiles.JPG "I/O Operation count")

## (LRU) Least-Recently-Used Page Replacement Algorithm
This program illustrates the frame replacement and page faults that occur during a least-recently-used page replacement algorithm. With this algorithm, the least recently used page is the first one to be replaced. The program contains hardcoded page reference strings, as per the assignment instructions, as well as a hardcoded frame alotment. It will print three columns representing the frames and what reference string each holds at that point in the program, as well as illustrating the replacements that occur at each step. When a page is removed from a frame to make room for a new one, it counts as a page fault, which is tallied and displayed at the end.

### Compilation:
gcc lru.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignlru.JPG "Least-Recently-Used Page Replacement")

## Priority Scheduling 
This program illustrates a Priority Scheduling algorithm. This algorithm chooses jobs in the order of a given priority. The code includes hardcoded process times, as well as an array representing their priority, as per the assignment instructions. The average wait time and average turn around time is then calculated and displayed. There is no input required from the user.

### Compilation:
gcc priority.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignpriority.JPG "Priority Scheduling")

## (SJF) Shortest-Job-First Scheduling
This program illustrates the Shortest-Job-First Scheduling algorithm. This approach orders jobs by time to process, shortest to longest. The program contains an array of process times, calculates the average wait time and average turn around time, and displays the results to the user.

### Compilation:
gcc sjf.c

### Execution:
a.exe

![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/osDesignsjf.JPG "Shortest Job First Scheduling")
