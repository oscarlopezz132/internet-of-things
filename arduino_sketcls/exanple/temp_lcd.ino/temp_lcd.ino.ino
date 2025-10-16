#include <LiquidCrystal.h>

// LCD RS, E, D4, D5, D6, D7
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Pines del circuito
const int sensorPin = A0;  // TMP36
const int ledPin = 13;      // LED indicador
const int motorPin = 10;    // Motor (a través de transistor)

float temperatura = 0.0;

void setup() {
  lcd_1.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp (C): ");
}

void loop() {
  // --- Lectura TMP36 ---
  int valor = analogRead(sensorPin);
  float voltaje = valor * (5.0 / 1024.0);
  temperatura = (voltaje - 0.5) * 100.0;

  // --- Mostrar temperatura en LCD ---
  lcd_1.setCursor(0, 1);
  lcd_1.print("                "); // Limpia segunda línea
  lcd_1.setCursor(0, 1);
  lcd_1.print(temperatura);
  lcd_1.print(" C");

  // --- Validaciones ---
  if (temperatura <= 10) {
    // Frío → LED parpadea, motor apagado
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else if (temperatura > 10 && temperatura <= 25) {
    // Temperatura normal → ambos apagados
    digitalWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW);
    delay(200);
  }
  else if (temperatura >= 26) {
    // Calor → ambos encendidos
    digitalWrite(ledPin, HIGH);
    digitalWrite(motorPin, HIGH);
    delay(200);
  }
}
