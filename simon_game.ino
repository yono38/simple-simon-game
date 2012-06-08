// Simon Memory Game
// TODO
// Create abstraction for sequences
// Create abstraction for sequence checker
// Add small button to allow replay of sequence

// NOTE: buttons and leds referred to from 0 to 3

// set pin numbers:
const int button[] = {3, 5, 7, 9};     // the number of the pushbutton pin
const int led[] =  {4, 6, 8, 10};      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status
// end sequences with -1

const int num_sequences = 5;
const int length_sequence = 9;
int sequence[num_sequences][length_sequence] = {
  {0,0,1,-1,-1,-1,-1,-1,-1},
  {0,3,1,3,-1,-1,-1,-1,-1},
  {3,2,0,3,0,-1,-1,-1,-1},
  {2,1,3,1,0,3,2,-1,-1},
  {3,0,2,1,1,2,3,0,2}
}; // turn into multidimensional array holding the seqs 
int seqCounter = 0; // holds which sequence is current
int counter = 0; // holds which place in sequence is current

void setup() {
    Serial.begin(9600);      // open the serial port at 9600 bps:    
  // initialize the LED pin as an output:
  for (int i=0; i<4; i++){
    pinMode(led[i], OUTPUT);
  }
  // initialize the pushbutton pin as an input:
  for (int i=0; i<4; i++){
    pinMode(button[i], INPUT);
  }
  
  // Start Sequence
  flashSequence(seqCounter);
}

void loop(){
   // check button state 
  for (int i=0; i<4; i++){
    buttonState = digitalRead(button[i]);
    // you hit a button..
    if(buttonState == HIGH){
      flashLed(i);
      // you hit the right one!
      if(i == sequence[seqCounter][counter]){
//          Serial.print("\n Counter: ");
//          Serial.print(counter);
//          Serial.print("\n length_sequence: ");
//          Serial.print(length_sequence);   
        // increment counter
          counter++;
        // cheat mode
        Serial.print("\nNext press: ");
        Serial.print(sequence[seqCounter][counter]); 
        // you finished the sequence  
        if (counter == length_sequence || sequence[seqCounter][counter] == -1){
          // you finished the game!
          seqCounter++;
          if (seqCounter == num_sequences){
            win(); 
            reset();
          }
          // next sequence
          else {
            counter = 0;
            flashSequence(seqCounter);
          }
        }
      }
      // you hit the wrong one!
      else {
        lose();
        counter = 0;
        flashSequence(seqCounter);
      }
    }
    // reset after pressing
    buttonState = 0;
  }
  delay(200);
}

// both LEDs on for 3 seconds
void lose(){
  digitalWrite(led[0], HIGH); 
  digitalWrite(led[2], HIGH);     
  delay(3000);              // wait for a second 
  digitalWrite(led[0], LOW); 
  digitalWrite(led[2], LOW); 
  
}

// flash LEDs on for a few seconds
void win(){
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j<4; j++) {
      digitalWrite(led[j], HIGH);  
    }   
    delay(200); 
    for (int j = 0; j<4; j++) {
      digitalWrite(led[j], LOW);  
    }   
    delay(50);
  }
}

void reset(){
  counter = 0;
  seqCounter = 0;
  delay(1000);
  flashSequence(seqCounter);
}

// plays out a sequence for you
void flashSequence(int seq_num){
  int ctr = 0;
  while (sequence[seq_num][ctr] != -1){
    flashLed(sequence[seq_num][ctr]); 
    ctr++;
    if (ctr == length_sequence) break;
  }
}

// flash one LED
// used for sequence
void flashLed(int num){
  // validation woot
  if (num < 0 || num > 3){
    return;
  }
  digitalWrite(led[num], HIGH); 
  delay(1000); // wait for a second 
  digitalWrite(led[num], LOW); 
  delay(200);     
}
