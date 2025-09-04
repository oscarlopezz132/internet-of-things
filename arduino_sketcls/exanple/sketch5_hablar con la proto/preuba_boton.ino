char opt;
const int LED_ROJO = 13;
const int LED_VERDE = 12;
const int LED_AMARILLO = 8;

void setup() {
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  Serial.begin(9600);
  Serial.println("::::::WELCOME:::::");
  Serial.println("Presiona una tecla para mostrar el menú");
}

void loop() {
  if (Serial.available() > 0) {
    opt = Serial.read();
    menu();
    switch(opt) {
      case '1':
        digitalWrite(LED_ROJO, HIGH);
        Serial.println("LED rojo encendido");
        break;
      case '2':
        digitalWrite(LED_ROJO, LOW);
        Serial.println("LED rojo apagado");
        break;
      case '3':
        digitalWrite(LED_VERDE, HIGH);
        Serial.println("LED verde encendido");
        break;
      case '4':
        digitalWrite(LED_VERDE, LOW);
        Serial.println("LED verde apagado");
        break;
      case '5':
        digitalWrite(LED_AMARILLO, HIGH);
        Serial.println("LED amarillo encendido");
        break;
      case '6':
        digitalWrite(LED_AMARILLO, LOW);
        Serial.println("LED amarillo apagado");
        break;
      case '7':
        Serial.println("Todos los LEDs titilando...");
        for (int i = 0; i < 3; i++) {
          digitalWrite(LED_ROJO, HIGH);
          digitalWrite(LED_VERDE, HIGH);
          digitalWrite(LED_AMARILLO, HIGH);
          delay(500);
          digitalWrite(LED_ROJO, LOW);
          digitalWrite(LED_VERDE, LOW);
          digitalWrite(LED_AMARILLO, LOW);
          delay(500);
        }
        Serial.println("Fin del titileo");
        break;
      case '8':
        Serial.println("Encendiendo LEDs en secuencia 5 veces...");
        for (int i = 0; i < 5; i++) {
          digitalWrite(LED_ROJO, HIGH);
          delay(300);
          digitalWrite(LED_ROJO, LOW);
          digitalWrite(LED_VERDE, HIGH);
          delay(300);
          digitalWrite(LED_VERDE, LOW);
          digitalWrite(LED_AMARILLO, HIGH);
          delay(300);
          digitalWrite(LED_AMARILLO, LOW);
        }
        Serial.println("Secuencia finalizada");
        break;
      case '9':
        digitalWrite(LED_ROJO, LOW);
        digitalWrite(LED_VERDE, LOW);
        digitalWrite(LED_AMARILLO, LOW);
        Serial.println("Todos los LEDs apagados");
        break;
      default:
        Serial.println("Opción no válida");
    }
  }
}

void menu() {
  Serial.println("Menú principal");
  Serial.println("[1] Encender LED Rojo");
  Serial.println("[2] Apagar LED Rojo");
  Serial.println("[3] Encender LED Verde");
  Serial.println("[4] Apagar LED Verde");
  Serial.println("[5] Encender LED Amarillo");
  Serial.println("[6] Apagar LED Amarillo");
  Serial.println("[7] Titilar todos los LEDs");
  Serial.println("[8] Encender LEDs en secuencia 5 veces");
  Serial.println("[9] Apagar todos los LEDs");
  Serial.println("Presiona una opción:");
}
