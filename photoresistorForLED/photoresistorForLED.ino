#include <AlaLedRgb.h>

#define REDPIN 3
#define GREENPIN 5
#define BLUEPIN 6

AlaLedRgb rgbLed;

void setup() {
  // put your setup code here, to run once:
  // pinMode(8, OUTPUT);

  Serial.begin(9600);

  rgbLed.initPWM(REDPIN, GREENPIN, BLUEPIN);                 // initialize output pins
  rgbLed.setBrightness(0x67C7EB);                            // calibrate white
  rgbLed.setAnimation(ALA_FADECOLORSLOOP, 10000, alaPalRgb);  // set the animation
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);

  // Serial.println(sensorValue);
  delay(10);

  int led_power = sensorValue / 5;

  // Serial.println(led_power);

  if (led_power > 150) {
    rgbLed.runAnimation();  // run the animation indefinitely
  } else {
    digitalWrite(REDPIN, LOW);
    digitalWrite(BLUEPIN, LOW);
    digitalWrite(GREENPIN, LOW);
  }
}
