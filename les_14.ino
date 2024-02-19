#define DATA_PIN 13 
#define LATCH_PIN 12 
#define CLOCK_PIN 11 
#define BUTTON_PIN 10
int clicks = 0;
boolean buttonWasUp = true;
byte segments[10] = {
 0b10000010, 0b11011011, 0b10000101, 0b10001001, 0b11011000, 
 0b10101000, 0b10100000, 0b10011011, 0b10000000, 010001000
};
void setup()
{
 pinMode(DATA_PIN, OUTPUT);
 pinMode(CLOCK_PIN, OUTPUT);
 pinMode(LATCH_PIN, OUTPUT);
 pinMode(BUTTON_PIN, INPUT_PULLUP);
}
void loop()
{
 if (buttonWasUp && !digitalRead(BUTTON_PIN)) {
 delay(10);
 if (!digitalRead(BUTTON_PIN))
 clicks = (clicks + 1) % 10;
 }
 buttonWasUp = digitalRead(BUTTON_PIN);
 digitalWrite(LATCH_PIN, LOW);
 shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, segments[clicks]);
 digitalWrite(LATCH_PIN, HIGH);
}
