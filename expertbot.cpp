/* 
    Code by [YOUR NAME HERE]
    Date: [DATE HERE]
    Program Description:
        [DESCRIPTION HERE]
*/


#include <iostream>         // for cout, cin, endl
#include <stdlib.h>         // for rand, srand
#include <time.h>           // for time (seeding rand)
using namespace std;


// ----- GLOBAL VARIABLES AND FUNCTIONS ----- //

string USER_NAME = "";


// random number generator function
int random(int min, int max){
    return rand() % (max - min + 1) + min;
}




// ----- MAIN FUNCTION ----- //

int main(){

    srand(time(NULL)); // seed the random number generator (so that it's different each time)


    return 0;
}
// ----- END OF PROGRAM ----- //