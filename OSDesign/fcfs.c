/*
   Paige Eckstein
   Operating System Design
   First-Come-First-Served Scheduling Algorithm
   Given priority excluded as priority based on first-come-first-served basis
 */
#include <stdio.h>

int main(){
        int processTime[4] = {5, 10, 3, 8};
        int waitTime[4];
        int turnAround[4];
        int averageWait = 0, averageTurnAround = 0, totalProcesses = 4;

        //wait time for first process to run is 0
        waitTime[0] = 0;

        //calculate wait time by adding each processes time
        for(int i = 1; i < totalProcesses; i++) {
                waitTime[i] = 0;
                for(int j = 0; j < i; j++) {
                        waitTime[i] += processTime[j];
                }
        }

        //calculate turnaround time
        for(int k = 0; k < totalProcesses; k++) {
                turnAround[k] = processTime[k] + waitTime[k];
                averageWait+=waitTime[k];
                averageTurnAround+=turnAround[k];
        }

        averageWait/=totalProcesses;
        averageTurnAround/=totalProcesses;

        printf("Average Waiting Time: %d.\n", averageWait);
        printf("Average Turnaround Time: %d.\n", averageTurnAround);

        return 0;

}
