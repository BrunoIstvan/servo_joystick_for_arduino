#include <Arduino.h>
#include <Servo.h>

#define SERVO_MOTOR_1 9
#define SERVO_MOTOR_2 10
// #define J1_Z 2

//Criando um objeto da classe Servo
Servo servo1;
Servo servo2;

int const ponto_inicial = 90;

int joystickX = 0;
int joystickY = 0;
// int joystickZ = 0;

int joystickRepousoX = 0;
int joystickRepousoY = 0;
// int joystickRepousoZ = 0;


//Este método é responsável apenas por imprimir no
//Serial Monitor os valores dos eixos X, Y e Z.
void imprimeEixos() {

  //imprime o valor do eixoX
  Serial.print("  X=");
  Serial.print(joystickX);
  Serial.print("  X-Repouso=");
  Serial.print(joystickRepousoX);
 
  //imprime o valor do eixoY
  Serial.print("   Y=");
  Serial.print(joystickY);
  Serial.print("  Y-Repouso=");
  Serial.print(joystickRepousoY);
 
  // //imprime o valor do eixoZ
  // Serial.print("   Z=");
  // Serial.println(joystickZ);

  Serial.print("   Angulo servo 1="); 
  Serial.print(servo1.read());

  Serial.print("   Angulo servo 2="); 
  Serial.println(servo2.read());

}

void setup() {
  
  //Ativando o Serial Monitor que exibirá os
  //valores lidos no Joystick
  Serial.begin(9600);
  
  //associando o pino digital de controle do
  //servo ao objeto da classe Servo
  servo1.attach(SERVO_MOTOR_1);
  servo2.attach(SERVO_MOTOR_2);

  //Definindo eixoZ como um pino de entrada
  //pinMode(EIXO_X, INPUT);
  //pinMode(EIXO_Y, INPUT);
  //pinMode(EIXO_Z, INPUT_PULLUP);
  
  servo1.write(ponto_inicial);

  joystickRepousoX = map(analogRead(A0), 0, 1023, 0, 180);
  joystickRepousoY = map(analogRead(A1), 0, 1023, 0, 180);

}

void loop() {
  //Lê o valor do eixoX
  joystickX = analogRead(A0);
  joystickY = analogRead(A1);
  //joystickZ = digitalRead(EIXO_Z);

  //mapeando o valor lido no joystick para a escala do
  //servo (entre 0 e 180)
  joystickX = map(joystickX, 0, 1023, 0, 180);
  //joystickY = map(joystickY, 0, 1023, 0, 180);
  //joystickZ = map(joystickZ, 0, 1, 0, 45);   

  imprimeEixos();   

  if(joystickX != joystickRepousoX){
    // x não está em repouso
    //definindo o valor/posição do servomotor
    servo1.write(joystickX);
  } 
  // se quiser voltar ao ponto inicial
  // else {
  //   servo1.write(ponto_inicial);
  // }

  // if(joystickY != joystickRepousoY){
  //   // y não está em repouso
  //   servo.write(joystickY);
  // }
  
  // z foi pressionado
  //servo.write(joystickZ);
 
  //espera 200 milisegundos.
  delay(200);
}

