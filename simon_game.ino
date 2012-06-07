// Simon Memory Game
// TODO
// Create abstraction for sequences
// Create abstraction for sequence checker

// NOTE: buttons and leds referred to from 0 to 3

// set pin numbers:
const int button[] = {3, 5, 7, 9};     // the number of the pushbutton pin
const int led[] =  {4, 6, 8, 10};      // the number of the LED pin

int buttonState[] = {0, 0, 0, 0};         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  for (int i=0; i<4; i = i+1){
    pinMode(led[1], OUTPUT);
  }
  // initialize the pushbutton pin as an input:
  for (int i=0; i<4; i = i+1){
    pinMode(button[i], INPUT);
  }
  
  // Start Sequence
  flashLed(1);
  flashLed(3);
  flashLed(0);
  flashLed(1);
  flashLed(2);
}

void loop(){/*
  // read the state of the pushbutton value:
  // RED BUTTON  
  buttonState = digitalRead(buttonPin);
  // GREEN BUTTON
  greenState = digitalRead(greenButton);
  
  // check if the RED pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) { 
    digitalWrite(ledPin, HIGH); 
    delay(500);              // wait for a second 
    digitalWrite(ledPin, LOW);     
    if (!first) { first = true; }
    else if (!second) {second = true;}
    else {
       lose();
       reset();
    }
    delay(200);
  } 

  // check if the GREEN pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (greenState == HIGH) {  
   digitalWrite(greenLed, HIGH); 
   delay(500);              // wait for a second 
   digitalWrite(greenLed, LOW);    
    if (first && second){
      win();
      reset();
    }
    else{
     lose();
     reset(); 
    }
    delay(200);
  } 
*/
}

// both LEDs on for 3 seconds
void lose(){
  digitalWrite(led[0], HIGH); 
  digitalWrite(led[1], HIGH);     
  delay(3000);              // wait for a second 
  digitalWrite(led[0], LOW); 
  digitalWrite(led[1], LOW); 
}
/*
// flash LEDs on for a few seconds
void win(){
  for (int i = 0; i < 20; i = i+1) {
    digitalWrite(ledPin, HIGH); 
    digitalWrite(greenLed, HIGH);     
    delay(200);              // wait for a second 
    digitalWrite(greenLed, LOW); 
    digitalWrite(ledPin, LOW); 
    delay(50);
  }
}
*/

// rewrite this
void reset(){
 // first = false;
 // second = false;
 // third = false; 
}

// flash one LED
// used for sequence
void flashLed(int num){
  if (num < 0 || num > 3){
    return;
  }
  digitalWrite(led[num], HIGH); 
  delay(1000); // wait for a second 
  digitalWrite(led[num], LOW); 
  delay(200);     
}
