// Variable, um den Messwert vom Photowiderstand zu speichern
int sensorValue;
// Variable für den tiefsten Sensorwert
int sensorLow = 1023;
// Variable für den höchsten Sensorwert
int sensorHigh = 0;
// Konstante für die integrierte LED an Pin 13
const int ledPin = 13;

void setup() {
  // Der Modus der LED an Pin 13 wird zu Output geändert
  // und die LED wird eingeschaltet
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // Nachdem das Programm auf dem Arduino gestartet wurde,
  // wird während den ersten 5 Sekunden eine Schleife ausgeführt,
  // die zum Kalibrieren des höchsten und tiefsten Sensorwerts dient. 
  while (millis() < 5000) {
    // Aktualisierung des höchsten Sensorwerts
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // Aktualisierung des tiefsten Sensorwerts
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // die LED an Pin 13 wird ausgeschaltet und signalisiert das Ende der Kalibrierung
  digitalWrite(ledPin, LOW);
}

void loop() {
  // der von Pin A0 abgerufene Messwert wird in einer Variable gespeichert
  sensorValue = analogRead(A0);

  // Mit der Ftk. map() werden die Sensorwerte in verschiedene Tonhöhen umgewandelt
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // Mit der Fkt. tone() wird der Ton für 20 ms über Pin 8 ausgegeben
  tone(8, pitch, 20);

  // 10 ms Wartezeit, um die Töne etwas klingen zu lassen
  delay(10);
}