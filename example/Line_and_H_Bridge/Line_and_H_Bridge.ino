// Copyright : Vincent SAHLER, 2018
// GitHub Username : CofeDrink68

#include "robot.hpp"

Motor mGauche;
Motor mDroit;

int motorsPins[2][3] = {{7, 6, 5}, {2, 3, 4}};

int lCaptPins[5] = {31, 33, 35, 37, 39};
LinesCapt myLineCapt(lCaptPins);

int detectors[6][5] = {{0, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1},
                       {0, 0, 1, 0, 0},
                       {0, 1, 1, 1, 0},
                       {0, 1, 1, 0, 0},
                       {0, 0, 1, 1, 0}};

int detectorIds[6];

void setup() {
  for(int x=0;x<6;x++)
    detectorIds[x] = myLineCapt.addDetector(detectors[x]);

  for(int y=0;y<3;y++){
    pinMode(motorsPins[0][y], OUTPUT);
    mGauche.pins[y] = motorsPins[y];
  }
  mGauche.state = 20;


  for(int y=0;y<3;y++){
    pinMode(motorsPins[1][y], OUTPUT);
    mDroit.pins[y] = motorsPins[y];
  }
  mDroit.state = 20;

  Serial.begin(115200);
  actualizeMotor(mGauche, mDroit);
}

void loop() {
  Serial.println(myLineCapt.detect());
  delay(100);
}
