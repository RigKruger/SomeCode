// Sett pins for LEDs. Green=yes, Yellow=maybe, Red=no
int redl = 5; 
int greenl = 6;
int yellowl = 7;

// Set button pin
int btn = 2;

// Setting delays
int animdelay = 100; // Rolling animation delay. How fast should LEDs flicker.
int rollduration = 50; // How long should animation last
int candleduration = 100; // Candle flickering animation duration

void setup()
{
pinMode(redl, OUTPUT); 
pinMode(greenl, OUTPUT); 
pinMode(yellowl, OUTPUT); 
pinMode(btn, INPUT); 
randomSeed(analogRead(0));
}

void loop(){
if (digitalRead(btn)){
  Animation ();
}
}

void flickerled (int led) {
int flicker = 0;

do {

    if (led==1)
    {
    analogWrite(redl, random (255));
    }
    else if (led==2)
    {
    analogWrite(greenl, random (255));
    }
    else
    {
    analogWrite(yellowl, random (255));
     }


  flicker ++;

    if (digitalRead(btn))
    {
      Animation ();
      break;
    }

  int delayh = random(1,30);
  delay (delayh);

} while (flicker == candleduration);

digitalWrite (redl, LOW);
digitalWrite (redl, LOW);
digitalWrite (redl, LOW);

}

void Animation (){
  
int rollled=0;
int pingo;
 
do
{
  pingo = random(1,3);

    if (pingo==1)
    {
      digitalWrite (redl, HIGH);
      delay (animdelay);
    }
    else if (pingo==2)
    {
      digitalWrite (greenl, HIGH);
      delay (animdelay);
    }
    else
    {
      digitalWrite (yellowl, HIGH);
      delay (animdelay);
    }
  digitalWrite (redl, LOW);
  digitalWrite (redl, LOW);
  digitalWrite (redl, LOW);


//    digitalWrite (pingo, HIGH); 
//    delay (100);
//    digitalWrite (pingo, LOW);
  rollled ++;
} while (rollled == rollduration);
//int delayh = random(5,7);
flickerled (pingo);
}
