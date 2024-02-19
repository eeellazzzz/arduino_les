#define LED_PIN 9
String message;
void setup()
{
 pinMode(LED_PIN, OUTPUT);
 Serial.begin(9600);
}
void loop()
{
 while (Serial.available()) { 
 char incomingChar = Serial.read();
 if (incomingChar >= '0' && incomingChar <= '9') {
 message += incomingChar;
 } else if (incomingChar == '\n') {
 analogWrite(LED_PIN, message.toInt());
 message = "";
 }
 }
}
