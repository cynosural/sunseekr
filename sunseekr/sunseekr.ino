#define LEDpin  13                   // LED connected to digital pin 13
#define LDRpin  0                    // LDR connected to analog pin 0

const int minDuration = 10;         // Minimum delay between blinks
const int maxDuration = 800;        // Maximum delay between blinks

void setup()
{
  pinMode(LEDpin, OUTPUT);           // Set LED pin as an output
  Serial.begin(57600);               // Initialize serial port
}

void loop()
{
  int rate = analogRead(LDRpin);     // Read analog input
  float volts = (rate/1023.0) * 5.0;
  int rawRate = rate;                // Save raw analog input value

  if (rate < 300) rate = 800;        // Scale minimum limit
  if (rate > 1000) rate = 10;      // Scale maximum limit

  // Scale blink rate between min and max duration
  rate = map(rate, 300, 1000, minDuration, maxDuration);

  Serial.print("Raw Rate: ");
  Serial.println(rawRate);           // Send raw analog value to serial port

  Serial.print("Map Rate: ");
  Serial.println(rate);              // Send scaled analog value to serial port

  Serial.print("Volts DC: ");
  Serial.println(volts);
  Serial.println();

  digitalWrite(LEDpin, HIGH);        // Turn on LED
  delay(rate);                       // Delay is based on light level
  digitalWrite(LEDpin, LOW);         // Set LED off
  delay(rate);                       // Delay is based on light level
}

