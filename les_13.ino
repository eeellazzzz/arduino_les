#define FIRST_SEGMENT_PIN 2
#define SEGMENT_COUNT 7
byte numberSegments[10] = {
 0b11000000, 0b11110101, 0b10100010, 0b10100001, 0b10010101,
 0b10001001, 0b10001000, 0b11100101, 0b10000000, 0b10000001,
};
void setup()
{
 for (int i = 0; i < SEGMENT_COUNT; ++i)
 pinMode(i + FIRST_SEGMENT_PIN, OUTPUT);
}
void loop()
{
 int number = (millis() / 1000) % 10;
 int mask = numberSegments[number];
 for (int i = 0; i < SEGMENT_COUNT; ++i) {
 boolean enableSegment = bitRead(mask, i);
 digitalWrite(i + FIRST_SEGMENT_PIN, enableSegment);
 }
}
