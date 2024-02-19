#define BUZZER_PIN 13 // пин с пищалкой (англ. «buzzer»)
#define FIRST_KEY_PIN 7 // первый пин с клавишей (англ. «key»)
#define KEY_COUNT 3 // общее количество клавиш
void setup()
{
 pinMode(BUZZER_PIN, OUTPUT);
}
void loop()
{
 for (int i = 0; i < KEY_COUNT; ++i) {
 int keyPin = i + FIRST_KEY_PIN;
 boolean keyUp = digitalRead(keyPin);
 if (!keyUp) {
 int frequency = 3500 + i * 500;
 tone(BUZZER_PIN, frequency, 20);
 }
 }
}
