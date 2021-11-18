#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#include<SoftwareSerial.h>
SoftwareSerial GSM(2,3);

int led=6;
int buzz=4;

unsigned int MEMSX;
unsigned int MEMSY;
void initModule(String cmd,char *res,int t)
{
  while(1)
  {
    Serial.println(cmd);
    delay(100);
    while(Serial.available()>0)
    {
      if(Serial.find(res))
      {
        Serial.println(res);
        delay(t);
        return;
      }
      else

      {
        Serial.println("error");
      }
    }
    delay(t);
    
  }
}
void send()
{
  
  Serial.begin(9600);
  GSM.begin(9600);
  GSM.println("AT+CMGF=1");
  delay(1000);
  GSM.println("AT+CMGS=\"+919079800458\"\r");
  delay(1000);
  GSM.println("help accident happened");
  delay(100);
  GSM.println((char)26);
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:


  //**************
  String cmd;
  char *res;
  int t;
  //************
 

lcd.begin(16,2);
Serial.begin(9600);

pinMode(buzz,OUTPUT);
pinMode(led,OUTPUT);

lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("vehicle accident");
lcd.setCursor(0,1);
lcd.print("DETECTION USING");
delay(5000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("MEMS,GSM");
lcd.setCursor(0,1);
lcd.print("AND ARDUINO UNO");
delay(5000);
lcd.clear();
lcd.print("initializing");
lcd.setCursor(0,1);
lcd.print("GSM MODEM");
delay(1000);


/*initModule("AT","OK",1000);
initModule("ATE1","OK",1000);
initModule("AT+CPIN?","READY",1000);
initModule("AT+CMGF=1","OK",1000);
initModule("AT+CNMI=2,2,0,0,0","OK",1000);*/


lcd.clear();
lcd.print("initialized");
lcd.setCursor(0,1);
lcd.print("Successfully");
delay(2000);
lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
st:
lcd.clear();
MEMSX=analogRead(0);MEMSX=MEMSX/2;
lcd.setCursor(0,0);lcd.print("X:");lcd.setCursor(3,0);lcd.print(MEMSX);delay(1000);
MEMSY = analogRead(1);
MEMSY =MEMSY/2;
lcd.setCursor(0,1);lcd.print("Y:");lcd.setCursor(3,1);lcd.print(MEMSY);delay(1000);
if((MEMSX >= 160 ) & (MEMSX <= 175) & ((MEMSY >=160) &(MEMSY<=175)))
{
   lcd.setCursor(8,0);
   lcd.print("NORMAL");
   delay(500);
   digitalWrite(buzz,LOW);
   digitalWrite(led,LOW);
}
if(((MEMSX >=130) & (MEMSX<=150)) & ((MEMSY>=160) & (MEMSY<=175)))

{
  
  lcd.setCursor(8,0);lcd.print("RIGHT ");lcd.setCursor(8,1);lcd.print("ACCIDENT ");
  digitalWrite(buzz,HIGH);digitalWrite(led,HIGH);delay(2000);
  lcd.clear();lcd.setCursor(6,0);lcd.print("PRESS RST");lcd.setCursor(6,1);lcd.print("SWITCH");
  delay(5000);delay(5000);
  lcd.clear();lcd.setCursor(8,0);lcd.print("RIGHT ");lcd.setCursor(8,1);lcd.print("ACCIDENT");
  delay(2000);lcd.clear();lcd.print("Sending SMS");delay(2000);
  
  send();delay(2000);goto st;

}
if(((MEMSX>=185)&(MEMSX<=200))&((MEMSY>=160)&(MEMSY<=175)))
{
  lcd.setCursor(8,0);lcd.print("LEFT");
  lcd.setCursor(8,1);
  lcd.print("ACCIDENT");
  digitalWrite(buzz,HIGH);digitalWrite(led,HIGH);delay(2000);
  lcd.clear();lcd.setCursor(6,0);lcd.print("PRESS RST");lcd.setCursor(6,1);lcd.print("SWITCH");
  delay(5000);delay(5000);
  lcd.clear();lcd.setCursor(8,0);lcd.print("left");lcd.setCursor(8,1);lcd.print("accident");
  delay(2000);lcd.clear();lcd.print("SENDING SMS");
  delay(2000);send();delay(2000);goto st;
}
if(((MEMSX>=160)&(MEMSX<=175))&((MEMSY>=130)&(MEMSY<=150)))

{
  lcd.setCursor(8,0);lcd.print("FRONT");lcd.setCursor(8,1);lcd.print("ACCIDENT");
  digitalWrite(buzz,HIGH);digitalWrite(led,HIGH);delay(2000);
  lcd.clear();lcd.setCursor(6,0);lcd.print("PRESS RST");lcd.setCursor(6,1);lcd.print("SWITCH");
  delay(5000);delay(5000);
  lcd.clear();lcd.setCursor(8,0);lcd.print("FRONT");lcd.setCursor(8,1);lcd.print("ACCIDENT");
  delay(2000);lcd.clear();lcd.print("sending SMS");delay(2000);send();delay(2000);goto st;
}

if(((MEMSX>=160)&(MEMSX<=175))&((MEMSY>=180)&(MEMSY<=195)))
{
  lcd.setCursor(8,0);lcd.print("BACK");lcd.setCursor(8,1);lcd.print("ACCIDENT");
  digitalWrite(buzz,HIGH);digitalWrite(led,HIGH);delay(2000);
  lcd.clear();lcd.setCursor(6,0);lcd.print("PRESS RST");lcd.setCursor(6,1);lcd.print("SWITCH");
  delay(5000);delay(5000);
  lcd.clear();lcd.setCursor(8,0);lcd.print("BACK");lcd.setCursor(8,1);lcd.print("ACCIDENT");
  delay(2000);lcd.clear();lcd.print("SENDING SMS");delay(2000);send();delay(2000);goto st;
}
}


