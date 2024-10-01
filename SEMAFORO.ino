// Pines de los LEDs
const int pinLedGreen = 2;
const int pinLedYellow = 3;
const int pinLedRed = 4;

// Pin del botón
const int buttonPin = 9; // ESP32 conectado al pin del botón

// Variables para el estado del botón
int currentButtonState;  // Estado actual del botón

void setup() {
  Serial.begin(9600);                // Inicializar serial
  pinMode(buttonPin, INPUT_PULLUP);   // Configurar pin del botón en modo pull-up
  pinMode(pinLedGreen, OUTPUT);
  digitalWrite(pinLedGreen, LOW);

  pinMode(pinLedYellow, OUTPUT);
  digitalWrite(pinLedYellow, LOW);

  pinMode(pinLedRed, OUTPUT);
  digitalWrite(pinLedRed, LOW);
}

void loop() {
  // Leer el estado actual del botón
  currentButtonState = digitalRead(buttonPin);

  // Si el botón está presionado (LOW)
  if (currentButtonState == LOW) {
    Serial.println("Botón presionado, ejecutando la secuencia del semáforo...");

    // Apagar LEDs para iniciar la secuencia
    digitalWrite(pinLedRed, LOW);
    digitalWrite(pinLedYellow, LOW);

    // Encender LED verde después de parpadear
    digitalWrite(pinLedGreen, HIGH);
    delay(2000);

        // Hacer parpadear el LED verde 3 veces
    for (int i = 0; i < 3; i++) {
      digitalWrite(pinLedGreen, HIGH); // Encender verde
      delay(300);                      // Pausa de 300 ms
      digitalWrite(pinLedGreen, LOW);  // Apagar verde
      delay(300);                      // Pausa de 300 ms
    }

    // Cambiar al LED amarillo
    digitalWrite(pinLedGreen, LOW);
    digitalWrite(pinLedYellow, HIGH);
    delay(2000);

    // Cambiar al LED rojo
    digitalWrite(pinLedYellow, LOW);
    digitalWrite(pinLedRed, HIGH);
    delay(2000);
  } else {
    // Si el botón no está presionado, apagar los LEDs
    digitalWrite(pinLedGreen, LOW);
    digitalWrite(pinLedYellow, LOW);
    digitalWrite(pinLedRed, LOW);
  }

  delay(100);  // Pequeña pausa para evitar rebotes
}
