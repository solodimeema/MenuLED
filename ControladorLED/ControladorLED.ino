// Declaramos las entradas/salidas que vamos a usar
const int analogInPin1 = A0;  // Pin entrada analóga
const int analogInPin2 = A1;  // Pin entrada analóga
const int PWM = 9 ;           // Pin salida analóga

//Declaramos las variables que usaremos 
int pwmValue = 0;  // valor inicial del PWM

void setup() {
  pinMode(analogInPin1, INPUT);
  pinMode(analogInPin2, INPUT);
  pinMode(PWM, OUTPUT);
  
  TCCR2B = B00000110;  // frecuencia de 31250 Hz
}

void loop() {
  float voltaje = analogRead(analogInPin1); // lee el valor del potenciometro
  float salida = analogRead(analogInPin2);  // lee el valor de la alimentación

  // Si el valor deseado es mayor que el valor real, aumentamos el ancho del PWM
  if(voltaje > salida) {
    pwmValue = pwmValue + 1;
    pwmValue = constrain(pwmValue, 1, 100);
    }
  // Si el valor deseado es menor que el valor real, disminuimos el ancho del PWM
  if(voltaje < salida) {
    pwmValue = pwmValue - 1;
    pwmValue = constrain(pwmValue, 1, 100);
    }

  analogWrite(PWM, pwmValue); // Creamos la señal del PWM
}
