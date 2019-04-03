#include<SoftwareSerial.h>

#include <Adafruit_Fingerprint.h>
SoftwareSerial mySerial(2,3);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

char a,e,data;
void setup()
{
   mySerial.begin(57600);
Serial.println("haii?"); //checks the softuart
  Serial.begin(57600);
  delay(500);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  collectFingerImage();
  take_image_outside();
  

}

void loop() {
  

}
void collectFingerImage(void)
{
  do{ 
      mySerial.write(0XEF);
      mySerial.write(0X01);
      mySerial.write(0XFF);
      mySerial.write(0XFF);
      mySerial.write(0XFF);
      mySerial.write(0XFF);
      mySerial.write(0X01);
      mySerial.write((byte)0X00);
      mySerial.write(0X03);
      mySerial.write(0X01);
      mySerial.write((byte)0X00);
      mySerial.write(0X05);
  //delay(500);
while(!(mySerial.available()>0));
while(a != 3){ 
a=mySerial.read(); 
 Serial.write(a);
}
if(mySerial.available()>0){ 
a=mySerial.read(); 
 Serial.write(a);
}
if(a==0) Serial.println("ok      ");  
 else if(a==1) Serial.println("error 4    "); 
 else if(a==2) Serial.println("no finger"); 
 else if(a==3) Serial.println("error 2  "); 
 else { Serial.println("error 0  ");}
e=mySerial.read(); 
e=mySerial.read();
  }while(a!=0);//
  
}
/////////////////////////
void generateCharacterFile(void)
{
  do{   
 
      mySerial.write(0XEF);
      mySerial.write(0X01);
      mySerial.write(0XFF);
      mySerial.write(0XFF);
      mySerial.write(0XFF);
      mySerial.write(0XFF);
   mySerial.write(0X01);
   mySerial.write((byte)0X00);
   mySerial.write(0X04);
   mySerial.write(0X02);
   mySerial.write(0X01); 
                       
                       
   mySerial.write((byte)0X00);
   mySerial.write(0X08);
      
 while(!(mySerial.available()>0));
while(a != 3){
a=mySerial.read(); 
 Serial.write(a);
};
if(mySerial.available()>0){ 
a=mySerial.read(); 
 Serial.write(a);
}
if(a==0) Serial.println("ok chra file generated    "); 
 else if(a==1) Serial.println("error 1    "); 
 else if(a==6) Serial.println("er 2"); 
                                          
 else if(a==7) Serial.println("error 3  "); 
                                             
                                            
  else if(a==0x15) mySerial.println("error 4  ");
                                                
 else { mySerial.println("error 5 ");}
e=Serial.read(); 
e=Serial.read(); 
  }while(a!=0);      




}

////////////////
void take_image_outside(void)
{
  do{
    mySerial.write(0XEF);
    mySerial.write(0X01);
    mySerial.write(0XFF);
    mySerial.write(0XFF);
    mySerial.write(0XFF);
    mySerial.write(0XFF);
    mySerial.write(0X01);
    mySerial.write((byte)0X00);
    mySerial.write(0X03);
    mySerial.write(0X0A);
    mySerial.write((byte)0X00);
    mySerial.write(0X0E);
     while(!(mySerial.available()>0));
while(a != 3){ 
a=mySerial.read(); 
 Serial.write(a);
};
if(mySerial.available()>0){ 
a=mySerial.read(); 
 Serial.write(a);
}
if(a==0) Serial.println("ok ready to transfer image   "); 
 else if(a==1) Serial.println("error 1    "); 
 else if(a=='f') Serial.println("er 2"); 
                      
 else if(a==7) Serial.println("error 3  "); 
                                              
                                            
  else if(a==0x15) mySerial.println("error 4  ");
                                              
 else { mySerial.println("error 5 ");}
e=Serial.read(); //avoides checksum
e=Serial.read(); //avoides che
    
    
  }while(a!=0);
///////////trying to take image?////
while(mySerial.available())
{
  data=mySerial.read();
  Serial.print(data,HEX);
}
  
}
