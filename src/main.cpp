#include <Arduino.h>
#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWERSIZE 5

String answer = "hello";

void receiveEvent(int)
{
  while (0 < Wire1.available())
  {
    byte x = Wire1.read();
    Serial.print(x);
  }

  Serial.println('\n');
  Serial.println("Revceive event");
}
void requestEvent()
{
  byte response[ANSWERSIZE];
  for (byte i = 0; i < ANSWERSIZE; i++)
  {
    response[i] = (byte)answer.charAt(i);
  }
  Wire1.write(response, sizeof(response));

  Serial.println("request event");
}

void setup()
{
  Wire1.begin(SLAVE_ADDR);
  Wire1.onRequest(requestEvent);
  Wire1.onReceive(receiveEvent);

  Serial.begin(9600);
  Serial.println("I2C slave");
}

void loop()
{
  delay(1000);
}
