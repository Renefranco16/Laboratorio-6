import processing.serial.*;

Serial puerto; // Objeto para la comunicación serial
boolean[] ledsEstado = {false, false, false, false, false, false, false, false}; // Estado inicial de los LEDs
boolean[] btnsEstado = {false, false, false, false}; // Estado de los botones

void setup() {
  size(400, 200);
  // Inicia la comunicación serial con Arduino
  puerto = new Serial(this, Serial.list()[8], 9600);
}

void draw() {
  background(255);
  // Dibuja los LEDs
  for (int i = 0; i < 8; i++) {
    fill(ledsEstado[i] ? color(255, 0, 0) : color(150));
    ellipse(50 + i * 40, 50, 30, 30);
  }
  // Dibuja los botones
  for (int i = 0; i < 4; i++) {
    fill(btnsEstado[i] ? color(0, 255, 0) : color(150));
    rect(50 + i * 90, 120, 60, 30);
  }
}

// Enciende o apaga el LED correspondiente al presionar una elipse
void mousePressed() {
  for (int i = 0; i < 8; i++) {
    if (dist(mouseX, mouseY, 50 + i * 40, 50) < 15) {
      ledsEstado[i] = !ledsEstado[i];
      puerto.write(ledsEstado[i] ? (char)('A' + i) : (char)('E' + i));
      break;
    }
  }
}

// Actualiza el estado de los botones al presionar los rectángulos
void mouseReleased() {
  for (int i = 0; i < 4; i++) {
    if (mouseX > 50 + i * 90 && mouseX < 110 + i * 90 && mouseY > 120 && mouseY < 150) {
      btnsEstado[i] = !btnsEstado[i];
      puerto.write(btnsEstado[i] ? (char)('I' + i) : (char)('M' + i));
      break;
    }
  }
}

// Recibe los datos desde Arduino
void serialEvent(Serial p) {
  String mensaje = p.readStringUntil('\n').trim();
  if (mensaje.length() == 1) {
    char estado = mensaje.charAt(0);
    if (estado >= 'A' && estado <= 'H') {
      ledsEstado[estado - 'A'] = true;
    } else if (estado >= 'E' && estado <= 'L') {
      ledsEstado[estado - 'E'] = false;
    } else if (estado >= 'I' && estado <= 'L') {
      btnsEstado[estado - 'I'] = true;
    } else if (estado >= 'M' && estado <= 'P') {
      btnsEstado[estado - 'M'] = false;
    }
  }
}
