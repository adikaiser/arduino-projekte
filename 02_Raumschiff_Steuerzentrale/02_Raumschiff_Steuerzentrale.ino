// Als erstes wird eine globale Variable erzeugt, welche festhält
// ob der Schalter gedrückt wird oder nicht.
int switchstate = 0;

void setup() {
  // Mit der Fkt. pinMode() konfiguriert man, ob die digitalen Pins Ein- oder Ausgänge sind.
  // Die LEDs an den Pins 3-5 werden als Output deklariert. 
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  // Der Schalter an Pin 2 wird als Input deklariert.
  pinMode(2, INPUT);
}

void loop() {

  // Mit der Fkt digitalRead() wird der Wert des Schalters ausgelesen. 
  // digitalRead() prüft, ob am Pin 2 Spannung anliegt oder nicht. 
  switchstate = digitalRead(2);

  // Wenn der Schalter nicht gedrückt wird, sollte die grüne LED aufleuchten
  // und die roten LEDs aus sein. 
  if (switchstate == LOW) {
    digitalWrite(3, HIGH); // Grüne LED an Pin 3 anschalten 
    digitalWrite(4, LOW);  // Rote LED an Pin 4 ausschalten
    digitalWrite(5, LOW);  // Rote LED an Pin 5 ausschalten
  }
  // Sonst, wenn der Schalter gedrückt wird, soll die grüne LED ausgeschaltet werden
  // und die beiden roten LEDs mit einer Viertelsekunde Verzögerung abwechselnd aufleuchten.  
  else {
    digitalWrite(3, LOW);  // Grüne LED an Pin 3 ausschalten
    digitalWrite(4, LOW);  // Rote LED an Pin 4 ausschalten 
    digitalWrite(5, HIGH); // Rote LED an Pin 5 anschalten 
    // Eine Viertelsekunde warten, bevor auf die andere LED gewechselt wird
    delay(250);
    digitalWrite(4, HIGH); // Rote LED an Pin 4 anschalten 
    digitalWrite(5, LOW);  // Rote LED an Pin 5 ausschalten 
    // Wieder eine Viertelsekunde warten, bevor auf die andere LED gewechselt wird
    delay(250);
  }
}