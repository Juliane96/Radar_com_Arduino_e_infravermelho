
#include <Servo.h>

#define infra1 A2
#define infra2 A0

long sensor1;
long sensor2;
float voltage;
long distancia;
int posicao = 0;
long valores[2];

Servo servo;

void setup() {
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {
  delay (750);
  
  /* Armazena na variavel sensor1 o valor lido pelo infravermelho 1 */
  sensor1 = analogRead(infra1);
  /* Tranforma o valor lido pelo infravermelho 1 em voltagem */
  voltage = sensor1 * (5.0 / 1023.0); 
  /* Calcula a distancia atraves da formula gerada */
  distancia = 25.4412619453*pow(voltage,-1.083008889);

  valores[0] = distancia;

  Serial.println(valores[0]);
  
   /* Armazena na variavel sensor2 o valor lido pelo infravermelho 2 */
  sensor2 = analogRead(infra2);
  /* Tranforma o valor lido pelo infravermelho 2 em voltagem */
  voltage = sensor2 * (5.0 / 1023.0); 
  /* Calcula a distancia atraves da formula gerada */
  distancia = 25.4412619453*pow(voltage,-1.083008889);

  valores[1] = distancia;

  Serial.println(valores[1]);

  MexeServo();

}

void MexeServo()
{
    if (posicao <= 180)
    {
       servo.write(posicao);
       posicao+=20;
       /* Enquanto a posicao do servo for menor que 180, ele ira
       incrementar 20 na posicao */
    }
    else
    {
      posicao = 0;
      servo.write(posicao);
      posicao+=20;
      /* Quando a posicao do servo chegar em 180, ele ira retornar 
      para a posicao 0 */
    }
}

