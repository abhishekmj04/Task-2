// Embedded Systems Lab - Sensor Interfacing
// Motion Detection System using PIR Sensor

int pirPin = 2;      // PIR sensor OUT pin
int ledPin = 13;     // External LED pin
int motionValue;     // Variable to store sensor value

void setup() {
  pinMode(pirPin, INPUT);      // PIR as input
  pinMode(ledPin, OUTPUT);     // LED as output
  Serial.begin(9600);          // Start Serial Monitor
  
  Serial.println("=== Motion Detection System Started ===");
  delay(3000);  // PIR warm-up time
}

void loop() {

  // Read input from sensor
  motionValue = digitalRead(pirPin);

  //  Display sensor value on Serial Monitor
  Serial.print("Sensor Value: ");
  Serial.println(motionValue);

  // Trigger action when threshold passes
  // Threshold for PIR is HIGH (1)
  if (motionValue == HIGH) {
    
    digitalWrite(ledPin, HIGH);   // Turn LED ON
    Serial.println("ALERT: Motion Detected!");
    
  } else {
    
    digitalWrite(ledPin, LOW);    // Turn LED OFF
    Serial.println("No Motion Detected");
  }

  delay(1000);   // Small delay for stability
}
