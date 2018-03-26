#include <Servo.h>


Servo myservo1;
Servo myservo2;  // create servo object to control a servo
Servo myservo3;
Servo myservo4;
Servo myservo5;
Servo myservo6;

Servo myservo7;
Servo myservo8;
Servo myservo9;
Servo myservo10;
Servo myservo11;
Servo myservo12;

int triggerPin = 22; //triggering on pin 7
int echoPin = 24;    //echo on pin 8
int LED = 26; //led pin
int duration, distance;

char A;
int val;
int temp;
int temp1=0;
int temp2;

int val1= 2;
int val2= 50 ; // variable to read the value from the analog pin
int val3=85;
int val4=90;
int val5= 82 ;
int val6= 105 ;

int val7= 172;
int val8= 90;
int val9=100;
int val10= 100;
int val11= 100;
int val12= 100 ;

void setup()
{
   Serial.begin(9600);
   myservo1.attach(12);
  myservo2.attach(2);
  myservo3.attach(3);
  myservo4.attach(4);// attaches the servo on pin 9 to the servo object
  myservo5.attach(5);
  myservo6.attach(6);

 myservo7.attach(13);
  myservo8.attach(7);
  myservo9.attach(8);
  myservo10.attach(9);
  myservo11.attach(10);
  myservo12.attach(11);

   pinMode(triggerPin, OUTPUT); //defining pins
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);    //defining LED pin
  digitalWrite(LED, HIGH);
  
}

void loop()
{
  myservo1.write(val1);
    myservo2.write(val2);
   myservo3.write(val3); 
   myservo4.write(val4);
    myservo5.write(val5);
     myservo6.write(val6);

     myservo7.write(val7);
      myservo8.write(val8);
       myservo9.write(val9);
        myservo10.write(val10);
         myservo11.write(val11);
          myservo12.write(val12);
 
  bluetooth();
  sensor();
}

void bluetooth()
{
 Serial.flush(); //flush all previous received and transmitted data
while(!Serial.available()) ;
  A = Serial.read(); // read serial and store it in 'val' 
  }

void sensor()
{
      //Adding duration and distance
  r2:
  digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
  
  Serial.print(distance);    //printing the numbers
  Serial.print("cm");       //and the unit
  Serial.println(" ");      //just printing to a new line
walkingpose();

if(distance <= 15)
{goto r2;
  }

  switch(A)
   {

   case 0x38:
    //up
   
     walk();
     
      break;
      
 case 0x32:
    //down
    break;

  //base
 
 case 0x34:
    //left
 left();
      break;
      
case 0x36:
    //right
   right();
      break;
  }  
 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void walkingpose()
  {
       Serial.print("walk pose ");
 val3=110;
 val4=142;
 val5= 120 ;

 val9=75;
 val10= 53;
 val11= 70;

        myservo3.write(val3);
   delay(15);

 myservo9.write(val9);  
   delay(15);

      myservo4.write(val4);  
   delay(15);

 myservo10.write(val10);  
   delay(15);

      myservo5.write(val5); 
   delay(15);

 myservo11.write(val11);
   delay(15);

   delay(2000);
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

  void walk()
  {
        Serial.print("walk ");
//////////////////  L - E -  F - T   ///////////////////////////////////////////////////////////////////////////////////////////////////////////
temp1=0;

for(val = 0; val <= 15; val += 1)

{
  val6=100-val;
   myservo6.write(val6); 
   delay(3);
   
   val12=105-val;
    myservo12.write(val12);
   delay(3);

val2=50-val;
    myservo2.write(val2);
   delay(3);
   
   val8=90-val;
      myservo8.write(val8);
      delay(3); 
  }

delay(100);

////////////////// RIGHT LEG  /////////////////////////////////////
temp=0;

for(val = 0; val <= 30; val += 2)

{
  val3=val+110;
   myservo3.write(val3);
   delay(3); 

   if(val4<=162)
   {
    val4=val+142;
    myservo4.write(val4);
   delay(3);
  
   }

    if (val>=12)
    {
      val5=120-val;
       myservo5.write(val5);
       delay(3);
    }  

 }
delay(100);
 ////////////////////////// RIGHT & IDEAL STATE  /////////////////////////////////////////////////////////
robo:
for(val = 0; val <= 40; val += 2)

{

 if(val<=30)
{

      val6=85+val;
   myservo6.write(val6); 
   delay(3);
   
   val12=90+val;
    myservo12.write(val12);
   delay(3);

val2=35+val;
    myservo2.write(val2);
   
   val8=75+val;
      myservo8.write(val8);
      delay(3); 
 }   
    
if(val<=40)
{
 val3=140-val;
   myservo3.write(val3);  
   delay(3); 
}

   if(val4>=142)
   {
    val4=162-val;
    myservo4.write(val4);
   delay(3);
  
   }

    if (val<=12)
    {
      val5=val+108;
       myservo5.write(val5);  
       delay(3);
    }

}
delay(100);

/////////////////////////// LEFT LEG ////////////////////////////////////
  temp=0;
  temp2=0;
 Serial.print("///////////////////////////////////////////////////////////////////////"); 
  for(val = 0; val <= 40; val += 2)
{
if(val<=16)
{
  val11=70+val;
 myservo11.write(val11); 
       delay(3);

}

  
  val9=75-val;
  myservo9.write(val9);  
   delay(3);


if(val10>=33)
{
  val10=53-val;
 myservo10.write(val10);
   delay(3);

}

if(val<=10)
{
 
 val3=100+val;
   myservo3.write(val3);
   delay(3); 
}

}
  
delay(100);
  /////////////////////////////////// LEFT & IDEAL  ////////////////////////////////////////////


for(val = 0; val <= 40; val += 2)

{

  if(val<=30)
  { 

      val6=115-val;
   myservo6.write(val6); 
   delay(3);
   
   val12=120-val;
    myservo12.write(val12);
   delay(3);

val2=65-val;
    myservo2.write(val2);
   
   val8=105-val;
      myservo8.write(val8);
      delay(3); 
  }   
    
if(val<=40)
{
 val9=35+val;
  myservo9.write(val9); 
   delay(3);
  
}
   if(val10<=53)
   {
    val10=val+33;
   myservo10.write(val10);
   delay(3);
  
   }

    if (val<=16)
    {
     
  val11=86-val;
 myservo11.write(val11);
       delay(3);
    }  

    
}

delay(100);

////////////////// RIGHT LEG  /////////////////////////////////////
temp=0;

for(val = 0; val <= 30; val += 2)

{
  

  val3=val+110;
   myservo3.write(val3);
   delay(3); 
  
   if(val4<=162)
   {
    val4=val+142;
    myservo4.write(val4); 
   delay(3);
  
   }

    if (val<=12)
    {
      val5=120-val;
       myservo5.write(val5);      
       delay(3);
    }  
 }
delay(100);

temp1=temp1+1;

digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = (duration/2) / 29.1; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
  
  Serial.print(distance);    //printing the numbers
  Serial.print("cm");       //and the unit
  Serial.println(" ");      //just printing to a new line
 
if(distance <= 20)
{temp1=6;
  }

if(temp1<=5)
{
 goto robo;
  }
  


//r1:


    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void left()
{
  int temp4=0;
   Serial.print("left ");
robo1:
   for(val = 0; val <= 20; val += 2)

{
  val6=105-val;
   myservo6.write(val6);
   delay(3);
val2=50-val;
    myservo2.write(val2);
  
      delay(3); 
      
  }

delay(1000);

temp=0;

for(val = 0; val <=30; val += 2)

{

      val6=85+val;
   myservo6.write(val6);  
   delay(3);
   
   val2=30+val;
    myservo2.write(val2);
      delay(3); 
      
   if(val<=10)
   {
    temp=temp+2;
   val12=100+temp;
    myservo12.write(val12);
   delay(3);

    val8=90+temp;
      myservo8.write(val8);
   }
  
      
  }   
    


delay(1000);

 for(val = 0; val <= 14; val += 2)

{
  if(val<=14)
  {
  val6=115-val;
   myservo6.write(val6);
  
val2=60-val;
    myservo2.write(val2);
    delay(3); 

  }
   val12=110-val;
    myservo12.write(val12);
   delay(3);

    
   val8=100-val;
      myservo8.write(val8);
 
  
}
 temp4=temp4+1;
delay(1000);
if(temp4<=5)
{
goto robo1;
}
  }

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  void right()
  {
    int temp5=0;
     Serial.print("right ");
    robo2:
   for(val = 0; val <= 40; val += 2)

{
   val12=105+val;
    myservo12.write(val12);
   delay(3);

   
   val8=95+val;
      myservo8.write(val8);
      delay(3); 
      
  }

delay(1000);


temp=0;
for(val = 0; val <=50; val += 2)

{
   val12=145-val;
    myservo12.write(val12); 
   delay(3);

   val8=135-val;
      myservo8.write(val8);
      delay(3); 
      

      
if (val<=10)
{

 val6=90-val;
    myservo6.write(val6);
   delay(3);

    val2=50-val;
      myservo2.write(val2);
      delay(3);
}
      
  }   
    
delay(1000);



 for(val = 0; val <= 20; val += 2)

{
   val12=95+val;
    myservo12.write(val12);
   delay(3);

   val8=85+val;
      myservo8.write(val8);  
      delay(3); 
   
   if(val<=10)
   {
       val2=40+val;
      myservo2.write(val2);
      
    val6=80+val;
    myservo6.write(val6);
   delay(3);
   }

  }
temp5=temp5+1;
delay(1000);
if(temp5<=5)
{
goto robo2;
}
    }
    

