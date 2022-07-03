// main file of the program where supposed to run from

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "states.h"
#include "capitals.h"

#define MAX_SIZE 15
#define BUFFER_SIZE 15 // this will make an input size of 16 with the '\0' i think


typedef char Location[50][MAX_SIZE]; // typedef to easily name states and capitals

const static Location states = STATES;
static Location capitals = CAPITALS; // this cannot be const, because it changes in isCorrect()


int main() {
    bool isCorrect(char* ans, char* input, int i, int inputSize, int capitalSize);

    int score = 0; // starting score
    char input[BUFFER_SIZE]; // for a 15 length string for buffer size, the max amount for a capital

    printf("Hello, welcome to the states and capitals quiz in C!\n");
    int numberOfQ; // make size_t because https://technoteshelp.com/casting-how-to-cast-the-size_t-to-double-or-int-c/ said so
    printf("questions: ");
    scanf(" %i", &numberOfQ);

    char *buffer; // string input is stored here at this memory location
    // size_t is required for getLine()
    size_t bufsize = BUFFER_SIZE; 
    size_t characters;

    // 32 bytes of storage are assigned to handle memory location buffer
    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL) // if memory isn't available (rare)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    // get the number of questions from the user
    //printf("How many questions would you like: ");
    //numberOfQ = getline(&buffer,&bufsize,stdin); // get the line inputted from the console
    
    srand(time(NULL));   // Initialization, should only be called once.
    int r; // initialize the random number
    
    bool linePassed = false;

    while (numberOfQ > 0) {
        // give the user a state to guess its capital
        
        // % 50 generates a random number from 0 to 49
        r = rand() % 50;      // Returns a pseudo-random integer between 0 and RAND_MAX.

        // define the char array answer we use to pass to the function call
        
        // find the length of char array
        //int capitalSize = sizeof(capitals[r]) / sizeof(capitals[r][0]); 
        char answer[15];
        strcpy(answer, capitals[r]);
        
        // get the state
        const char *state = states[r];

        if (!linePassed) {
            characters = getline(&buffer,&bufsize,stdin);
            linePassed = true;
            continue;
        }
        
        printf("Enter the capital of %s: ", state);
        characters = getline(&buffer,&bufsize,stdin);
        
        strcpy(input, buffer); // enter the capital, and store it in the char array

        //use a size_t var to understand how many characters were inputted to getline
        size_t numChar = characters-1; // how to find the length of an array in c

        if (isCorrect(answer, input, r, numChar, 15)) {
            score++;
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        numberOfQ--;
    }

    printf("final score is %i, congratulations!", score);

    return 0;
}
