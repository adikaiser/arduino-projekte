// Sobald man das Arduino mit Strom versorgt oder reset drückt wird die setup Fkt. einmal ausgeführt
void setup() {
  // LED_BUILTIN wird als output initialisiert
  pinMode(LED_BUILTIN, OUTPUT);
}

// Die Loop Fkt. wird als Endlosschleife ausgeführt 
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // LED einschalten (HIGH, da Spannung anliegt)
  delay(1000);                       // 1 Sekunde warten
  digitalWrite(LED_BUILTIN, LOW);    // LED ausschalten (LOW, da keine Spannung anliegt)
  delay(1000);                       // 1 Sekunde warten
}