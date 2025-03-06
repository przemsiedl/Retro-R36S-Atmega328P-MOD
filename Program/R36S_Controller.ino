#include <Arduino.h>
#include "r36s_config.h"

unsigned long prevTime;

char buffer[80];  // for one line in console

void setup() {
    //configure pins
  for(int i=0; i < BUTTONS_LEN; i++) {
    if(Buttons[i].Mode == PIN_SKIP){
      continue;
    }
    
    if(Buttons[i].Mode == PIN_INPUT) {
      pinMode(Buttons[i].Pin, INPUT);
    }

    if(Buttons[i].Mode == PIN_OUTPUT){
      pinMode(Buttons[i].Pin, OUTPUT);
    }
  }

  Serial.begin(9600);
}

void loop() {
  unsigned long newTime = millis();
  unsigned long elapsed = newTime - prevTime;
  prevTime = newTime;

  RefreshPins(elapsed);
}

void RefreshPins(int timeElapsed) {
  for(int i=0; i<BUTTONS_LEN; i++){
    RefreshInputPin(&Buttons[i], timeElapsed);
  }
}

void RefreshInputPin(ButtonDef* button, int timeElapsed)
{
  if(button->Mode != PIN_INPUT){
    return;
  }

  if(digitalRead(button->Pin) != BUTTON_DEFAULT_STATE) {

    if(button->PressMs == 0 && Serial.available()) {
      sprintf(buffer, "PRESSED INPUT BUTTON %s", button->Name);
      Serial.println(buffer);
      button->PressMs = -1;
    }

    if(button->PressMs == -1 && timeElapsed > 0){
      button->PressMs = timeElapsed;
      return;
    }

    button->PressMs = button->PressMs + timeElapsed;

  } else {

    if(button->PressMs != 0 && Serial.available()){
      sprintf(buffer, "RELEASED INPUT BUTTON %s after %u ms", button->Name, button->PressMs);
      Serial.println(buffer);
    }

    button->PressMs = 0;
  }
}