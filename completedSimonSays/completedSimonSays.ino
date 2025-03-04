// This is a template for a SIMON-SAYS game for the arduino
// The pins are already set up, so what you need to do is finish the functions.
#define MAX_SEQUENCE_LENGTH 5


// lets us access pins through their grouping
// ex: digitalWrite(ledPins[2], HIGH);  // writes pin4 to high
#define NUM_LEDS 4
int ledPins[NUM_LEDS] = {2,3,4,5};
int buttonsPins[NUM_LEDS] = {6,7,8,9};

// our game will go up to 10 turns
int sequence[MAX_SEQUENCE_LENGTH];

// variables to keep track of where we are in the game.
int sequenceLength = 0;
int playerIndex = 0;

// called on startup
void setup() {
    for (int i = 0; i < NUM_LEDS; i++) {
        pinMode(ledPins[i], OUTPUT);
        pinMode(buttonsPins[i], INPUT_PULLUP);
    }
    startNewGame();
}

// called constantly after startup
void loop() {
    // insert code here
    showSequence();
    if (checkPlayerInput()) {
        if (sequenceLength == MAX_SEQUENCE_LENGTH){
          victory();
        }
        else {
          sequenceLength++;
          delay(500);
        }

    } else {
        gameOver();
    }
}

// generates a new sequence to follow
// functions -
//      random(max) -> return random number within 0->max-1
//      random(min, max) -> return random number within min->max-1
void startNewGame() {
    // insert code here
    sequenceLength = 1;
    for (int i = 0; i < 10; i++) {
        sequence[i] = random(NUM_LEDS);
    }

}

// shows the sequence made by the computer up to sequenceLength
void showSequence() {
    // insert code here
    for (int i = 0; i < sequenceLength; i++) {
        digitalWrite(ledPins[sequence[i]], HIGH);
        delay(300);
        digitalWrite(ledPins[sequence[i]], LOW);
        delay(250);
    }
    // sets for player to begin at the beginning
    playerIndex = 0;
}

// checks player input to make sure if they mess up, return false, or if they succeed, return true
bool checkPlayerInput() {
    // insert code here
    while (playerIndex < sequenceLength) {
        for (int i = 0; i < NUM_LEDS; i++) {
            if (digitalRead(buttonsPins[i]) == LOW) {
                if (i == sequence[playerIndex]) {
                    digitalWrite(ledPins[i], HIGH);
                    delay(250);
                    digitalWrite(ledPins[i], LOW);
                    playerIndex++;
                    delay(250);
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

// flashes all leds on and off and then starts a new game.
void gameOver() {
   // for(int i = 0; i < 4; i++) {
        for(int j = 0; j < NUM_LEDS; j++) 
            digitalWrite(ledPins[j], HIGH);
        delay(300);

        for(int j = 0; j < NUM_LEDS; j++) 
            digitalWrite(ledPins[j], LOW);
        delay(200);
  //  }
    delay(700);
    startNewGame();
}

void victory() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      digitalWrite(ledPins[j], HIGH);
      delay(100);
      digitalWrite(ledPins[j], LOW);
      delay(100);
    }
  }
  delay(700);
  startNewGame();
}