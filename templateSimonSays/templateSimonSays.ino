 // This is a template for a SIMON-SAYS game for the arduino
// The pins are already set up, so what you need to do is finish the functions.

// lets us access pins through their grouping
// ex: digitalWrite(ledPins[2], HIGH);  // writes pin4 to high
#define NUM_LEDS 4
int ledPins[NUM_LEDS] = {2,3,4,5};
int buttonsPins[NUM_LEDS] = {6,7,8,9};

// our game will go up to 10 turns
int sequence[10];

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

}

// generates a new sequence to follow
// functions -
//      random(int num) -> return random number within 0->num
void startNewGame() {
    // insert code here

}

// shows the sequence made by the computer up to sequenceLength
void showSequence() {
    // insert code here

}

// checks player input to make sure if they mess up, return false, or if they succeed, return true
bool checkPlayerInput() {
    // insert code here

}

// flashes all leds on and off and then starts a new game.
void gameOver() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < NUM_LEDS; j++) 
            digitalWrite(ledPins[i], HIGH);
        delay(300);

        for(int j = 0; j < NUM_LEDS; j++) 
            digitalWrite(ledPins[i], LOW);
        delay(200);
    }
    startNewGame();
}