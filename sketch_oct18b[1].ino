// Pin Definitions
const int soundSensorPin = 2;   // Digital output from sound sensor
const int ledPin = 3;           // LED pin
const int buzzerPin = 4;        // Buzzer pin

void setup() {
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // For debugging (optional)
}

void loop() {
  int soundDetected = digitalRead(soundSensorPin);

  if (soundDetected == HIGH) {
    // Noise detected
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
    delay(200); // Keep LED and buzzer on for 200ms
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    delay(100); // Small delay to avoid continuous triggering
  } else {
    // No noise
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
}
