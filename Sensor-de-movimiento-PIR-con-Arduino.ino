/*
  Created by TEOS

  Domotic with Arduino https://goo.gl/btZpjs

  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB http://bit.ly/1UvumG9
*/

const int sensorPinT = 2;

long unsigned int lowInT;
long unsigned int pauseT = 4000;
boolean lockLowT = true;
boolean takeLowTimeT;

void setup() {
  Serial.begin(9600);
  pinMode(sensorPinT, INPUT);
  Serial.print("Iniciando calibracion ");
  for (int i = 0; i < 10; i++) {
    Serial.print("x");
    delay(1000);
  }
  Serial.println(" Calibracion finalizada");
}

void loop() {
  if (digitalRead(sensorPinT) == HIGH) {
    if (lockLowT) {
      lockLowT = false;
      Serial.println("Movimiento detectado");
      delay(50);
    }
    takeLowTimeT = true;
  }
  if (digitalRead(sensorPinT) == LOW) {
    if (takeLowTimeT) {
      lowInT = millis();
      takeLowTimeT = false;
    }
    if (!lockLowT && millis() - lowInT > pauseT) {
      lockLowT = true;
      Serial.println("El Movimiento termino");
      delay(50);
    }
  }
}
