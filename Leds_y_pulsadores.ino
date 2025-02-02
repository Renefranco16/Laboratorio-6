void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char estadoMonitor = Serial.read();
    if (estadoMonitor == 'A') {
      digitalWrite(2, HIGH);
      digitalWrite(3, HIGH);
      Serial.println("Grupo Led A Encendidos");
    } else if (estadoMonitor == 'B') {
      digitalWrite(4, HIGH);
      digitalWrite(5, HIGH);
      Serial.println("Grupo Led B Encendidos");
    } else if (estadoMonitor == 'C') {
      digitalWrite(6, HIGH);
      digitalWrite(7, HIGH);
      Serial.println("Grupo Led C Encendidos");
    } else if (estadoMonitor == 'D') {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      Serial.println("Grupo Led D Encendidos");
    } else if (estadoMonitor == 'E') {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      Serial.println("Grupo Led A Apagados");
    } else if (estadoMonitor == 'F') {
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      Serial.println("Grupo Led B Apagados");
    } else if (estadoMonitor == 'G') {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      Serial.println("Grupo Led C Apagados");
    } else if (estadoMonitor == 'H') {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      Serial.println("Grupo Led D Apagados");
    }
  } else if (digitalRead(10) == LOW) {
    Serial.write('A');
    delay(100);
  } else if (digitalRead(11) == LOW) {
    Serial.write('B');
    delay(100);
  } else if (digitalRead(12) == LOW) {
    Serial.write('C');
    delay(100);
  } else if (digitalRead(13) == LOW) {
    Serial.write('D');
    delay(100);
  } 
}
