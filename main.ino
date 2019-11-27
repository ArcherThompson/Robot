//#include "functions.h"
#include "pi2000.h"

#define S0 5
#define S1 6
#define S2 7
#define S3 8
#define S4 9
#define S5 10
#define S6 11
#define S7 12
#define S8 14
#define S9 15



const int onTime = 100; //time to hold button
const int cycleTime = 150; // minium full cycle time
const long matchTime = 190000; //3 minutes plus 10 secound buffer
/**
 * Function to press buttons
 * 
 **/
 //generic press

void prS(int buttonValue) {
//Serial.print(buttonValue);
  if(buttonValue == 0) {
    //Press 0

    digitalWrite( S0, HIGH);
    delay(onTime);
    digitalWrite( S0, LOW);
    }

  else if(buttonValue == 1) {
  //Press 1

    digitalWrite( S1, HIGH);
    delay(onTime);
    digitalWrite( S1, LOW);
    }

  else if(buttonValue == 2) {
  //Press 2

    digitalWrite( S2, HIGH);
    delay(onTime);
    digitalWrite( S2, LOW);
    }

  else if(buttonValue == 3) {
  //Press 3
 
    digitalWrite( S3, HIGH);
    delay(onTime);
    digitalWrite( S3, LOW);
    }

  else if(buttonValue == 4) {
  //Press 4

    digitalWrite( S4, HIGH);
    delay(onTime);
    digitalWrite( S4, LOW);
  }

  else if(buttonValue == 5) {
  //Press 5

    digitalWrite( S5, HIGH);
    delay(onTime);
    digitalWrite( S5, LOW);
    }

  else if(buttonValue == 6) {
  //Press 6

    digitalWrite( S6, HIGH);
    delay(onTime);
    digitalWrite( S6, LOW);
    }

  else if(buttonValue == 7) {
  //Press 7

    digitalWrite( S7, HIGH);
    delay(onTime);
    digitalWrite( S7, LOW);
  }

  else if(buttonValue == 8) {
  //Press 8

    digitalWrite( S8, HIGH);
    delay(onTime);
    digitalWrite( S8, LOW);
    }

    else if(buttonValue == 9) {
    //Press 9

    digitalWrite( S9, HIGH);
    delay(onTime);
    digitalWrite( S9, LOW);
    }
}
//end function


/**
 * Intial variable set up
 **/
int piDigit = 0;
int buttonValue = 3;
int currentT=0;
// end varibles


void setup() {              
  Serial.begin(9600);
  
  int startTimestamp = millis();

pinMode( S0, OUTPUT );
pinMode( S1, OUTPUT );
pinMode( S2, OUTPUT );
pinMode( S3, OUTPUT );
pinMode( S4, OUTPUT );
pinMode( S5, OUTPUT );
pinMode( S6, OUTPUT );
pinMode( S7, OUTPUT );
pinMode( S8, OUTPUT );
pinMode( S9, OUTPUT );
}

void loop() {
  //millis value is 3min 10sec at 190,000 millis
    while(millis() < matchTime){
        currentT = millis();
        buttonValue = pi[piDigit] - '0'; //this is a semi reduntant assignment so if time becomes an isssue then we may need to optimize here   
        prS(buttonValue);
        //Serial.print(buttonValue); //debug only
        piDigit++;
        //check to make sure that that we do not activate next value before areana is ready
        //this will not be nessesary with solonoids most likely.
      if (millis()-currentT <cycleTime) {
        delay(150-(millis()-currentT));
      }
    }
    //Serial.print("\n");  //debug only
    //Serial.print(piDigit); //debug only
}
