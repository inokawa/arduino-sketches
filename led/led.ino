const int ledPin = LED_BUILTIN;
const long interval = 1000;

void setup()
{
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  unsigned long ms = millis();
  if (ms % interval < interval / 2)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
