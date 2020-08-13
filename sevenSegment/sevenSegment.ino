const int digitPin = 8;
// A B C D E F G DP
const int segmentPins[] = {6, 5, 12, 10, 9, 7, 13, 11};
const int numberOfSegmentPins = sizeof(segmentPins) / sizeof(segmentPins[0]);

void setup()
{
  pinMode(digitPin, OUTPUT);
  for (int i = 0; i < numberOfSegmentPins; i++)
  {
    int pin = segmentPins[i];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
}

void loop()
{
  digitalWrite(digitPin, HIGH);
  for (int i = 0; i < numberOfSegmentPins; i++)
  {
    digitalWrite(segmentPins[i], LOW);
    delay(500);
    digitalWrite(segmentPins[i], HIGH);
  }
}
