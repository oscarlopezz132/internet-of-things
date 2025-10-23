// C++ code
//
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(4, OUTPUT);

  pinMode(8, OUTPUT);

  pinMode(13, OUTPUT);
}

void loop()
{
  if (0.01723 * readUltrasonicDistance(2, 3) > 240 && 0.01723 * readUltrasonicDistance(2, 3) < 320) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
 
  if (0.01723 * readUltrasonicDistance(2, 3) > 120 && 0.01723 * readUltrasonicDistance(2, 3) < 179) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if (0.01723 * readUltrasonicDistance(2, 3) > 0 && 0.01723 * readUltrasonicDistance(2, 3) < 59) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
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
