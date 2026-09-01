// Including the libraries
#include <MD_Parola.h>        // Library for managing text effects on the LED Matrix
#include <MD_MAX72xx.h>       // Library for controlling the MAX7219 cip inside the LED Matrix
#include <SPI.h>              // Library for SPI Communication between Arduino and the LED Matrix
#include <SoftwareSerial.h>   // Library for creating a virtual serial port on Arduino 
                              // for the communication between Arduino and the HC-05 Bluetooth Module

// Matrix Hardware Configuration
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   // FC16 is the type of optic module used
#define MAX_DEVICES 4                       // There are 4 8X8 cascading LED Matrices, creating a 32X8 display 

#define DATA_PIN  11    // Data In - transmitting from Arduino to the LED Matrix
#define CS_PIN    10    // Chip Select - activates communication with the LED Matrix by activating the MAX7219 cip inside it
#define CLK_PIN   6     // Clock - synchronizing data transfer, controls data transfer speed

// Defining myDisplay object using the MD_Parola library
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// By default, Arduino has only two programmable pins (Pin 0 and Pin 1)
// But using them for Bluetooth communication could cause conflicts when uploading code on Arduino
// To solve this issue, we created the virtual serial port BTSerial that uses Pin 2 and Pin 3
// Pin 2 - RX (Data Receiver)
// Pin 3 - TX (Data Transmitter)
SoftwareSerial BTSerial(2, 3);

// Global variable for the short text message received from the mobile app
char mesajulMeu[101] = "";

// Function used when pressing the Animatie1 button in the mobile app
void ruleazaAnimatieUnda() {
  MD_MAX72XX *pMatrix = myDisplay.getGraphicObject();   // Getting the graphic object from MD_MAX72XX
  pMatrix->clear();   // Clearing display

  for (int pas = 0; pas < 3; pas++) {   // Repeating three times for three light waves
    for (int i = 0; i < 32; i++) {      // Throughout the 32 columns of the LED Matrix display
      pMatrix->setColumn(i, 0xFF);      // Light up a vertical bar
      if (i > 0) pMatrix->setColumn(i - 1, 0x66);   // The anterior column remains partially lighted
      if (i > 1) pMatrix->setColumn(i - 2, 0x00);   // Shutting the anterior column
      delay(20);   // Short 20 ms break
    }
    pMatrix->clear();   // Clearing display
  }
}


// Function that runs only once when powering the circuit
void setup() {
  BTSerial.begin(9600);       // Beginning the Serial Communication with the HC-05 Module at a 9600 baud speed
  BTSerial.setTimeout(50);    // Data received wirelessly is being processed at a 50 ms pause, instead of a 1 s standard pause
  myDisplay.begin();          // Preparing Matrix display
  myDisplay.setIntensity(5);  // Setting display brightness at 5, medium intensity
  myDisplay.displayClear();   // Clearing display

  // Displaying "Ready" from right to left, at 50 ms speed, with a 1000 ms pause when reaching end of display
  myDisplay.displayText("Ready", PA_CENTER, 50, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

// Function that runs endlessly, waiting for user commands in the mobile app
void loop() {
  if (BTSerial.available() > 0) {   // Checking for data from mobile app
    String textPrimit = BTSerial.readStringUntil('\n');   // Reading data from mobile app
    textPrimit.trim();  // Trimming invizible characters or spaces

    if (textPrimit == "1") {      // If the first button was pressed (Hello World!)
      myDisplay.displayClear();  // Clearing display
      // Displaying "Hello World!" message at a speed of 40 ms, without pause, sliding from right to left
      myDisplay.displayText("Hello World!", PA_CENTER, 40, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    }
    else if (textPrimit == "2") {   // If the second button was pressed (Ioana sunt eu!)
      myDisplay.displayClear();     // Clearing display
      // Displaying "Ioana sunt eu!" mesage, at a speed of 40 ms, without pause, sliding from right to left
      myDisplay.displayText("Ioana sunt eu!", PA_CENTER, 40, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    }
    else if (textPrimit == "3") {   // If the third button was pressed (Animatie1)
      myDisplay.displayClear();     // Clearing display
      ruleazaAnimatieUnda();        // Running animation function
      // Displaying "IOANA" at a speed of 60 ms, with a 1000 ms pause, from top to bottom, in a slightly animated way
      myDisplay.displayText("IOANA", PA_CENTER, 60, 1000, PA_GROW_DOWN, PA_GROW_DOWN);
    }
    else if (textPrimit == "4") {   // If the fourth button was pressed (Animatie2)
      myDisplay.displayClear();     // Clearing display
      // Displaying "CRIS" at a speed of 60 ms, with a 1000 ms pause, with a special "Blinds Effect"
      myDisplay.displayText("CRIS", PA_CENTER, 60, 1000, PA_BLINDS, PA_BLINDS);
    }
    else if (textPrimit.startsWith("5")) {    // If the user sent a short text message throught the mobile app
      String mesajNou = textPrimit.substring(1);      // Cutting off the first digit character, to keep the actual message
      mesajNou.trim();    // Trimming spaces or invizible characters

      if (mesajNou.length() > 0) {    // If the message exists
        mesajNou.toCharArray(mesajulMeu, 101);  // Converting the string we read to a char vector, in order to display it
        myDisplay.displayClear();   // Clearing display
        // Displaying the short text message from user at a speed of 40 ms, without pause, form right to left
        myDisplay.displayText(mesajulMeu, PA_CENTER, 40, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
      }
    }
  }
  // Function that returns true if message display is over
  if (myDisplay.displayAnimate()) {
    // If so, the display resets to prepare for the next animation display
    myDisplay.displayReset();
  }
}