////Collision Warning System////

const int trigPin = 7;

const int echoPin = 8;

int buzz = 10;
int led = 13;

long duration;

int distance;

// the setup function runs once when you press reset or power the board

//********wheels************
const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;
//***************************

void setup() {

// initialize digital pin 13 as an output.

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(13, OUTPUT);  //led

pinMode(10, OUTPUT);  //buzzer

Serial.begin(9600);

//************wheels************
 pinMode(leftForward , OUTPUT);
  pinMode(leftBackward , OUTPUT);
  pinMode(rightForward , OUTPUT);
  pinMode(rightBackward , OUTPUT);
 // ********************************
}

// the loop function runs over and over again forever

void loop()

{

  //************//wheels***********
  digitalWrite(leftForward , HIGH);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , HIGH);
  digitalWrite(rightBackward , LOW);
  //******************************


  
// Clears the trigPin

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds

duration = pulseIn(echoPin, HIGH);

// Calculating the distance

distance= duration*0.034/2;

// Prints the distance on the Serial Monitor

if(distance <= 50 && distance >= 20)

{

digitalWrite(13, HIGH);



// turn the LED on (HIGH is the voltage level)

}

else

{

digitalWrite(13, LOW); // turn the LED off by making the voltage LOW

// wait for a second

}

if(distance <= 20)

{digitalWrite(13,HIGH);


  digitalWrite(leftForward , LOW);
  digitalWrite(leftBackward , LOW);
  digitalWrite(rightForward , LOW);
  digitalWrite(rightBackward , LOW);



digitalWrite(10, HIGH);

tone(buzz, 2000);

delay(100);

noTone(buzz);

delay(100);

tone(buzz, 2000);

delay(100);

noTone(buzz);

delay(100);

tone(buzz, 2000);

delay(100);

noTone(buzz);

tone(buzz, 2000);

delay(100);

noTone(buzz);

delay(100);

}

else

{

digitalWrite(13, LOW); // turn the LED off by making the voltage LOW

// wait for a second

}

}

