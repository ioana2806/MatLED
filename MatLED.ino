#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>
#include <SoftwareSerial.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define DATA_PIN  11 
#define CS_PIN    10 
#define CLK_PIN   6  

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

SoftwareSerial BTSerial(2, 3);

char mesajulMeu[101] = "";

void ruleazaAnimatieUnda() {
  MD_MAX72XX *pMatrix = myDisplay.getGraphicObject();
  pMatrix->clear();

  for (int pas = 0; pas < 3; pas++) {
    for (int i = 0; i < 32; i++) {
      pMatrix->setColumn(i, 0xFF);
      if (i > 0) pMatrix->setColumn(i - 1, 0x66); 
      if (i > 1) pMatrix->setColumn(i - 2, 0x00);
      delay(20);
    }
    pMatrix->clear();
  }
}

void setup() {
  BTSerial.begin(9600); 
  BTSerial.setTimeout(50);
  myDisplay.begin();
  myDisplay.setIntensity(5);
  myDisplay.displayClear();

  myDisplay.displayText("Ready", PA_CENTER, 50, 1000, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
}

void loop() {
  if (BTSerial.available() > 0) {
    String textPrimit = BTSerial.readStringUntil('\n');
    textPrimit.trim();

    if (textPrimit == "1") {
      myDisplay.displayClear();
      myDisplay.displayText("Hello World!", PA_CENTER, 40, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    }
    else if (textPrimit == "2") {
      myDisplay.displayClear();
      myDisplay.displayText("Ioana sunt eu!", PA_CENTER, 40, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
    }
    else if (textPrimit == "3") {
      myDisplay.displayClear();
      ruleazaAnimatieUnda();
      myDisplay.displayText("IOANA", PA_CENTER, 60, 1000, PA_GROW_DOWN, PA_GROW_DOWN);
    }
    else if (textPrimit == "4") {
      myDisplay.displayClear();
      myDisplay.displayText("CRIS", PA_CENTER, 60, 1000, PA_BLINDS, PA_BLINDS);
    }
    else if (textPrimit.startsWith("5")) {
      String mesajNou = textPrimit.substring(1);      
      mesajNou.trim();

      if (mesajNou.length() > 0) {
        mesajNou.toCharArray(mesajulMeu, 101);
        myDisplay.displayClear();
        myDisplay.displayText(mesajulMeu, PA_CENTER, 40, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
      }
    }
  }
  
  if (myDisplay.displayAnimate()) {
    myDisplay.displayReset();
  }
}