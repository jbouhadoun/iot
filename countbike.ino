// C++ code
//
#include <LiquidCrystal.h>
int roue1;
int roue2;
boolean frist_pass = false;
boolean second_pass = false;
double distance = 10;
int nombre_de_velo = 0;
int first_push = 0;
double sum_speed = 0.0;
LiquidCrystal lcd( 7, 6, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop()
{
  Serial.available();

  analogRead(A0);
  
  /*Serial.println(analogRead(A0));  
  Serial.println(analogRead(A1));
	*/

  analogRead(A2);

  -40 + 0.488155 * (analogRead(A3) - 20);
  
  if ((analogRead(A0) != 0 && analogRead(A0) < 700 && frist_pass == false)) {
    frist_pass = true;
    first_push = analogRead(A0);
    roue1 = millis();

  }
  else if ( (analogRead(A1) != 0 && first_push < 700 && analogRead(A1) < 700 &&  frist_pass == true && second_pass == false)){
  	roue2 = millis();
    double speed = ((distance / ((roue2 - roue1) /1000.0)) * 3.6);
    nombre_de_velo +=1 ;
    sum_speed += speed ;
    Serial.print("distance : ");
    Serial.print(distance);
    Serial.println(" m");
    
    Serial.print("delta time : ");
    Serial.print((roue2 - roue1)/1000.0);
    Serial.println(" s");
    
    Serial.print("speed : ");
    Serial.print(speed);
    Serial.println(" km/h");
    
    Serial.print("temperature : ");
    Serial.print(-40 + 0.488155 * (analogRead(A3) - 20));
    Serial.println(" c");
    
    Serial.print("nombre de velo : ");
    Serial.println(nombre_de_velo);
    
    lcd.setCursor(0,0);
    lcd.print("count bike: ");
    lcd.print(nombre_de_velo);
	lcd.setCursor(0,1);
    lcd.print("avg speed: ");
    lcd.print(sum_speed/nombre_de_velo);
    

    frist_pass = false;
  }

  // Serial.println(-40 + 0.488155 * (analogRead(A3) - 20));
  // Serial.println(analogRead(A1));
  
  delay(100); // Delay a little bit to improve simulation performance
}