# take_image_form_R305_to_atmega328

here RX pin of R305 is connected to pin2 of arduino and TX is conected to pin 3 of arduino



The image data is in HEX form...


Function for take image from sensor to upper computer (not included in the above code)


'''
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
  Serial.print(data,DEC);
}

'''

