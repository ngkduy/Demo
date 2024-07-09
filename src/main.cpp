#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define red 12
#define yellow 8

// Khai bao nhiem vu
void TaskBlinkRed(void *pvParameters);
void TaskBlinkYellow(void *pvParameters);
void TaskPrint(void *pvParameters);

void setup()
{
  Serial.begin(9600);
  while (!Serial)
  {
    ;
  }

  // Thiet lap cac tac vu chay doc lap
  xTaskCreate(
      TaskBlinkRed,
      "TaskBlinkRed",
      128,
      NULL,
      2,
      NULL);
  xTaskCreate(
      TaskBlinkYellow,
      "TaskBlinkYellow",
      128,
      NULL,
      2,
      NULL);
  xTaskCreate(
      TaskPrint,
      "TaskPrint",
      128,
      NULL,
      1,
      NULL);
}

void loop()
{
}

// Thiet lap cho cac tac vu
void TaskBlinkRed(void *pvParameters)
{
  (void)pvParameters;
  pinMode(red, OUTPUT);
  for (;;)
  {
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    delay(500);
  }
}

void TaskBlinkYellow(void *pvParameters)
{
  (void)pvParameters;
  pinMode(yellow, OUTPUT);
  for (;;)
  {
    digitalWrite(yellow, HIGH);
    delay(200);
    digitalWrite(yellow, LOW);
    delay(200);
  }
}

void TaskPrint(void *pvParameters){
  (void)pvParameters;
  Serial.begin(9600);
  for(;;)
  {
    Serial.println("Xin chao. I am Duy");
    delay(1000);
  }
}