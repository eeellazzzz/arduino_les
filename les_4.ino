#define BUZZER_PIN 3
#define LDR_PIN A0
void setup()
{
 pinMode(BUZZER_PIN, OUTPUT);
}
void loop()
{
 int val, frequency;
 val = analogRead(LDR_PIN);
 frequency = map(val, 0, 1023, 3500, 4500);
 tone(BUZZER_PIN, frequency, 20);
}
