// Servo-Bibliothek importieren
#include <Servo.h>

Servo myServo;  // es wird ein Servo-Objekt erzeugt

int const potPin = A0; // analoger Pin an welchem der Potentiometer angeschlossen ist
int potVal;  // Variable, um die Werte des analogen Pins auszulesen
int angle;   // Variable, um den Winkel für die Bewegung des Servomotors anzugeben

void setup() {
  myServo.attach(9); // verknüpft den Servo an Pin 9 mit dem Servo-Objekt
  Serial.begin(9600); // zum Computer wird eine serielle Verbindung hergestellt
}

void loop() {
  potVal = analogRead(potPin); // Wert des Potentiometers auslesen
  // Wert des Potentiometers auf dem seriellen Monitor ausgeben
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Mit der Fkt. map() werden die Zahlen des Potentiometers skaliert
  angle = map(potVal, 0, 1023, 0, 179);

  // Die Winkel für den Servomotor werden auf dem seriellen Monitor ausgegeben
  Serial.print(", angle: ");
  Serial.println(angle);

  // Servomotor zu dem spezifizierten Winkel bewegen
  myServo.write(angle);

  // Wartezeit, bis der Servomotor sich an die neue Position bewegt hat
  delay(15);
}