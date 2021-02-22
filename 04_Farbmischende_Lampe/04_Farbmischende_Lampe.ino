// Für die PINs wo die LEDs und Photowiderstände angeschlossen werden, 
// werden Konstanten initialisiert
const int greenLEDPin = 9;    // LED an Pin 9
const int redLEDPin = 10;     // LED an Pin 10
const int blueLEDPin = 11;    // LED an Pin 11

const int redSensorPin = A0;  // Photowiderstand mit roter Folie an Pin A0
const int greenSensorPin = A1;   // Photowiderstand mit grüner Folie an Pin A1
const int blueSensorPin = A2;   // Photowiderstand mit blauer Folie an Pin A2

// Für die Input- und Outputwerte werden Variablen erstellt
int redValue = 0; // Outputwert für rote LED
int greenValue = 0; // Outputwert für grüne LED
int blueValue = 0; // Outputwert für blaue LED

int redSensorValue = 0; // Inputwert für Photowiderstand mit roter Folie
int greenSensorValue = 0; // Inputwert für Photowiderstand mit grüner Folie
int blueSensorValue = 0; // Inputwert für Photowiderstand mit blauer Folie

void setup() {
  // Die serielle Kommunikation wird mit einer Baudrate von 9600 initialisiert:
  Serial.begin(9600);

  // Die digitalen Pins werden als Outputs definiert.
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
}

void loop() {
  // Zu Beginn der Schleife werden die Sensorsignale gelesen:

  // Wert von Photowiderstand mit roter Folie auslesen:
  redSensorValue = analogRead(redSensorPin);
  // Da der Analog-Digital-Konverter (=ADC) nur mit einer bestimmten Geschwindigkeit liest, 
  // muss man eine kleine Verzögerung einbauen. 
  delay(5);
  // Wert von Photowiderstand mit grüner Folie auslesen:
  greenSensorValue = analogRead(greenSensorPin);
  // wieder ein paar Sekunden Verzögerung für den ADVC
  delay(5);
  // Wert von Photowiderstand mit blauer Folie auslesen:
  blueSensorValue = analogRead(blueSensorPin);

  // Die Sensormesswerte werden auf dem seriellen Monitor ausgegeben.
  Serial.print("raw sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);

  /*
    Der ADC liefert eine 10-Bit grosse Zahl, die Fkt. analogWrite() verwendet aber 8 Bits. 
    Um den Sensormesswert von einem Wert zwischen 0 - 1023 in einen Wert zwischen 0 - 255 für
    analogWrite() umzuwandeln, muss man den Sensormesswert durch 4 teilen. 
  */
  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  // Die umgewandelten Sensormesswerte werden wieder auf dem seriellen Monitor ausgegeben.
  Serial.print("Mapped sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  /*
    Die Helligkeit der LEDs wird mittels Pulsbreitenmodulation (PWM) verändert.
  */
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}