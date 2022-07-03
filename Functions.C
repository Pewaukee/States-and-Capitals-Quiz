// helper file to run functions from 

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 15

bool inRange(int i) {
    if (i == 32 || (i >= 97 && i <= 122)) {
        return true;
    } return false;
}

bool isCorrect(char ans[], char input[], int i, int inputSize, int capitalSize) {
    if (inputSize > capitalSize) {return false;} // if the input has more characters than the result
    int inputSize2;
    // convert the strings to lower case
    for (int j = 0; j < MAX_SIZE; j++) {ans[j] = tolower(ans[j]);}
    for (int j = 0; j < MAX_SIZE; j++) {
        // if there is not a letter or space in the answer, return false
        // there is also always a new line at the end and a so get around that
        if (input[j] == 10 || input[j] == 0) {break;} // if a null value or new line is hit, then no need to check other values of input
        if (isalpha(input[j]) == 0 && !(input[j] == 32)) {
            return false;
        }
        input[j] = tolower(input[j]);
    }
    
    for (int j = 0; j < MAX_SIZE; j++) {
        // make sure the ascii values are in range of all lowercase letters and space
        // 32 is a space, 97 is 'a', and 122 is 'z'
        int a = ans[j];
        int b = input[j];

        printf("a=%i, b=%i\n", a, b);
        
        if (inRange(a) && inRange(b)) {
            
            // if in the range, evaluate
            if (a != b) { // ascii values don't match
                return false;
            }
        }
        // if either character is out of range, return false
        if (inRange(a) && !inRange(b)) {return false;}
        if (!inRange(a) && inRange(b)) {return false;}
        
        // if both are out of range, then its good
        if (!inRange(a) && !inRange(b)) {break;}
        
    }

    return true;
}