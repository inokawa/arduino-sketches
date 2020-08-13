// for anode common 7 segment display
#define DIGIT_ON HIGH
#define DIGIT_OFF LOW
#define SEGMENT_ON HIGH
#define SEGMENT_OFF LOW

const int digitPin = 8;
// A B C D E F G DP
const int segmentPins[] = {6, 5, 12, 10, 9, 7, 13, 11};
const int numberOfSegmentPins = sizeof(segmentPins) / sizeof(segmentPins[0]);

const int digits[] = {
    0b00111111, // 0
    0b00000110, // 1
    0b01011011, // 2
    0b01001111, // 3
    0b01100110, // 4
    0b01101101, // 5
    0b01111101, // 6
    0b00100111, // 7
    0b01111111, // 8
    0b01101111, // 9
};
const int dot = 0b10000000;

void displayNumber(int n)
{
  for (int i = 0; i < numberOfSegmentPins; i++)
  {
    pinMode(segmentPins[i], digits[n] & (1 << i) ? SEGMENT_ON : SEGMENT_OFF);
  }
}

void setup()
{
  pinMode(digitPin, OUTPUT);
  for (int i = 0; i < numberOfSegmentPins; i++)
  {
    int pin = segmentPins[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, SEGMENT_OFF);
  }
}

void loop()
{
  digitalWrite(digitPin, DIGIT_ON);
  for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); i++)
  {
    displayNumber(i);
    delay(500);
  }
}
