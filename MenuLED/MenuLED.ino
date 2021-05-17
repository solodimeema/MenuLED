#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 =4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int UP = 10;
int DOWN = 9;
int SELECT = 8;
int LED = 7;
int Menu = 1;
int temp = 1;

void setup(){
  lcd.begin(16,2);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(SELECT, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  updateMenu();
}

void loop(){
  if(!digitalRead(DOWN)){
    Menu++;
    updateMenu();
    delay(100);
  }
  
  if(!digitalRead(UP)){
    Menu--;
    updateMenu();
    delay(100);
  }
  
  if(!digitalRead(SELECT)){
    execute();
    updateMenu();
    delay(100);
  }
}

void updateMenu(){
  switch(Menu) {
    case 0:
    Menu = 1;
    break;
    case 1:
    lcd.clear();
    lcd.print("-> LED ON");
    lcd.setCursor(0,1);
    lcd.print("   LED OFF");
    break;
    case 2:
    lcd.clear();
    lcd.print("   LED ON");
    lcd.setCursor(0,1);
    lcd.print("-> LED OFF");
    break;
    case 3:
    lcd.clear();
    lcd.print("-> Desvanecido");
    lcd.setCursor(0,1);
    lcd.print("   Intermitente");
    break;
    case 4:
    lcd.clear();
    lcd.print("   Desvanecido");
    lcd.setCursor(0,1);
    lcd.print("-> Intermitente");
    break;
    case 5:
    Menu = 4;
    break;
    }
}

void execute(){
  switch(Menu) {
    case 1:
    accion1();
    break;
    case 2:
    accion2();
    break;
    case 3:
    accion3();
    break;
    case 4:
    accion4();
    break;
  }
}

void accion1(){
  lcd.clear();
  lcd.print("-> LED ON");
  delay(500);
  
  digitalWrite(LED, HIGH);
  delay(1000);
}

void accion2(){
  lcd.clear();
  lcd.print("-> LED OFF");
  delay(500);
  
  digitalWrite(LED, LOW);
  delay(1000);
}

void accion3(){
  lcd.clear();
  lcd.print("-> Desvanecido");
  delay(500);
  
  FuncionDesvanecidoLED();
  delay(1000);
}

void accion4(){
  lcd.clear();
  lcd.print("-> Intermitente");
  delay(500);
  
  FuncionIntermitenteLED();
  delay(1000);
}

void FuncionDesvanecidoLED(){
  unsigned long time1 = 0;
  unsigned long time2 = 0;
  int brillo;
  
  for(brillo = 0; brillo <= 255; brillo++){
    analogWrite(LED, brillo);
    time1 = millis();
    while(millis() < time1+temp){}
  }
  
  for(brillo = 255; brillo >= 0; brillo--){
    analogWrite(LED, brillo);
    time2 = millis();
    while(millis() < time2+temp){}
  }
}

void FuncionIntermitenteLED(){
  int i;
  for(i=0;i<=10;i++){
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
  }
}
