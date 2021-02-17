// Konstante für Zugriff auf analogen Eingang, an dem der Temperatur-Sensor angeschlossen ist
const int sensorPin = A0;
// Konstante zum Speichern der Raumtemperatur, welche unserer Basislinie entspricht. 
const float baselineTemp = 21.0;

void setup() {
  // Serielle Schnittstelle öffnen, damit die Werte des analogen Eingangs auf dem Computer
  // dargestellt werden können. begin() nimmt als Argument die Baudrate, in diesem
  // Fall 9600 Bits pro Sekunde. 
  Serial.begin(9600);
  // For-Schleife wird dazu benutzt, die LED-Pins als Ausgänge zu setzen. 
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // Der analoge Wert des Sensors wird in der Variable sensorVal gespeichert.
  // Der Wert von sensorVal liegt zwischen 0 und 1023. 
  int sensorVal = analogRead(sensorPin);

  // Die Fkt. Serial.print() wird dazu verwendet die ausgelesenen Sensorwerte
  // auf dem seriellen Monitor auszugeben. 
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  // Um die tasächliche Spannung auszurechnen, wird der gelesene Sensortwert umgerechnet. 
  float voltage = (sensorVal / 1024.0) * 5.0;

  // Der umgerechnete Sensorwert wird ebenfalls auf dem seriellen Montior ausgegeben. 
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // Die Spannung wird in die Temperatur in Grad Celsius konvertiert.
  // Gemäss dem Datenblatt des Temperatursensors erhöht sich die Spannung
  // des Sensors um 10 mV bei einem Temperaturanstieg von 1 Grad Celsius. 
  // Zusätzlich besitzt der Sensor eine Abweichung von 500 mV, damit auch
  // Temperaturen unterhalb des Gefrierpunkts gemessen werden können. Diese
  // Abweichung muss man bei der Konvertiertung von Volt zu Grad berücksichtigen. 
  Serial.print(", degrees C: ");
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  // Wenn die gemessene Temperatur tiefer als die Basislinie ist, sollten alle LEDs
  // ausgeschalten werden. 
  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } // Wenn die gemessene Temperatur 2 - 4 Grad höher als die Basislinie ist, soll eine LED angeschaltet werden. 
  else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } // Wenn die gemessene Temperatur 4 - 6 Grad höher als die Basislinie ist, soll eine zweite LED angeschaltet werden. 
  else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } // Wenn die gemessene Temperatur um mehr als 6 Grad höher als die Basislinie ist, sollen alle LEDs angeschaltet werden. 
  else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  // Da der Analog-Digital-Konverter nur mit einer bestimmten Geschwindigkeit liest, 
  // muss man eine kleine Verzögerung einbauen. 
  delay(1);
}