// Declaramos las entradas/salidas que vamos a usar
const int analogInPin1 = A0;  // Pin entrada analóga
const int analogOutPin = 9 ;  // Pin salida analóga

//Declaramos las variables que usaremos 
int sensorValue1 = 0;      // value read from the port

int brilloMin = 184;     // Definimos el valor minimo de brillo
int brilloMax = 500;     // Definimos el valor maximo de brillo
int brillo = 184;        // valor de la salida para el PWM
int outputValue = 0;        
int desvanecido = 5;     // cantidad de desvanecido del LED
unsigned long time1 = 0;
int temp = 1;

void setup() {
  // Inicializa comunicacion serial a 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // lee el analógo en valores:
  sensorValue1 = analogRead(analogInPin1);
  
  // cambia el brillo para la próxima vez a través del bucle:
  brillo = brillo + desvanecido;

  // invertir la dirección del desvanecido en los extremos del desvanecimiento:
  if (brillo <= brilloMin || brillo >= brilloMax) {
    desvanecido = -desvanecido;
   }

  // mapear el rango de la salida analógica:
  outputValue = map(brillo, 0, 1023, 0, 255);
  // cambia el ciclo de trabajo del PWM
  analogWrite(analogOutPin, outputValue);

  // imprimir los resultados en el monitor serial:
  Serial.println(brillo); //Envia el numero con el que se configure el PWM "variable" (0 a 1023)
  
  //Serial.println(outputValue);  
  Serial.println(sensorValue1);  //Envia lo que está midiendo la entrada anaolgica A0

  // Espere 2 milisegundos antes del siguiente bucle para la señal analógica a digital.
  time1 = millis();
    while(millis() < time1+temp){}
}
