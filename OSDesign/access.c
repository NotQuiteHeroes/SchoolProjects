#include <stdio.h>
#include <stdbool.h>


struct Users {
        //Each file holds three boolean values to represent Read, Write, and Execute access respectively
        bool fileOne[3];
        bool fileTwo[3];
};

int main()
{
        //Create Users
        struct Users A;
        struct Users B;
        struct Users C;

        //Set User A's access information.
        A.fileOne[0] = A.fileOne[1] = A.fileOne[2] = true;
        A.fileTwo[0] = A.fileTwo[1] = A.fileTwo[2] = false;

        //Set User B's access information
        B.fileOne[0] = B.fileOne[2] = true;
        B.fileOne[1] = false;
        B.fileTwo[0] = B.fileTwo[1] = true;
        B.fileTwo[2] = false;

        //Set User C's access information
        C.fileOne[0] = C.fileOne[1] = false;
        C.fileOne[2] = true;
        C.fileTwo[0] = C.fileTwo[1] = C.fileTwo[2] = true;

        //Check User A's access to execute file two
        if(A.fileTwo[2]) {
                printf("Access Granted: A - Execute file two.\n");
        }
        else{
                printf("Access Denied: A - Failed to execute file two.\n");
        }

        //Check User B's access to read file one and two
        if(B.fileOne[0] && B.fileTwo[0]) {
                printf("Access Granted: B - Read file one and two.\n");
        }
        else{
                printf("Access Denied: B - Failed to read file one and two.\n");
        }

        //Check User C's access to write to file one
        if(C.fileOne[0]) {
                printf("Access Granted: C - Write file one.\n");
        }
        else{
                printf("Access Denied: C - Failed to write file one.\n");
        }

        return 0;

}
