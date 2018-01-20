// Sett pins for LEDs. Green=yes, Yellow=maybe, Red=no
int redl = 6; 
int greenl = 7;
int yellowl = 8;

// Set button pin
int btn = 3;
int buttonState = 0;
// Setting delays
int animdelay = 100; // Rolling animation delay. How fast should LEDs flicker.
int rollduration = 0; // How long should animation last
int rollsteps = 20;

int candleduration = 500; // Candle flickering animation duration
int flicker = 0;


int beginloop = 0;
int pingo;


void setup()
{
pinMode(redl, OUTPUT); 
pinMode(greenl, OUTPUT); 
pinMode(yellowl, OUTPUT); 
pinMode(12, INPUT); 
randomSeed(analogRead(0));
digitalWrite(yellowl, LOW);
digitalWrite(greenl, LOW);
digitalWrite(redl, LOW);

}

void loop(){
buttonState = digitalRead(12);

if (beginloop == 1) {
  Animation ();
} 
 
if (beginloop == 2) {
  flickerled ();
} 
  
if (buttonState == HIGH) {
 beginloop = 1 ;
 rollduration = 0;
 flicker=0;
 randomSeed(analogRead(12));
} 
 
}

void Animation (){

if (rollduration >= rollsteps){
  beginloop = 2;
  rollduration=0;
  digitalWrite(yellowl, LOW);
  digitalWrite(greenl, LOW);
  digitalWrite(redl, LOW);
}else{
  pingo = random (1,3000);
  digitalWrite (redl, HIGH);
  digitalWrite (greenl, LOW);
  digitalWrite (yellowl, LOW);
  delay (animdelay);
  digitalWrite (redl, LOW);
  digitalWrite (greenl, HIGH);
  digitalWrite (yellowl, LOW);
  delay (animdelay);
  digitalWrite (redl, LOW);
  digitalWrite (greenl, LOW);
  digitalWrite (yellowl, HIGH);
  delay (animdelay);
  digitalWrite (redl, LOW);
  digitalWrite (greenl, HIGH);
  digitalWrite (yellowl, LOW);
  delay (animdelay);
  rollduration ++;
}

}

void flickerled () {

if (flicker >= candleduration){
  beginloop = 0;
  digitalWrite(yellowl, LOW);
  digitalWrite(greenl, LOW);
  digitalWrite(redl, LOW);
  pingo=0;
}else{
  if (pingo>1 and pingo<1000)
  {
    analogWrite(redl, random (100,255));
  }
  else if (pingo>1000 and pingo<2000)
  {
    analogWrite(greenl, random (100,255));
  }
  else
  {
    analogWrite(yellowl, random (100,255));
  }
int delayh = random(1,100);
delay (delayh);
flicker ++;
}

}
