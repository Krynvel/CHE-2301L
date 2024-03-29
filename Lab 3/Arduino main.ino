// Lab– Joystick
int joyButton = 2; // digital pin # for joy-stick switch:2
int joyX = A0; // analog pin # for ‘x’ output: A0
int joyY = A1; // analog pin # for ‘y’ output: A1
int redPin = 9; // digital pin # for red LED; must be PWM!
int grnPin = 10; // digital pin # for green LED; must be PWM!
int bluPin = 11; // digital pin # for blue LED; must be PWM!
float posX = 0; // x-position = float from 0 to 1,023
float posY = 0; // y-position = float from 0 to 1,023
int isButtonOn = 0; // analog button state set as Boolean
float redLevel=0;
float grnLevel=0;
float bluLevel=0;

void setup() {
pinMode(joyButton, INPUT); // joy-stick button is INPUT
pinMode(joyX, INPUT); // joy-stick x-direction is INPUT
pinMode(joyY, INPUT); // joy-stick y-direction is INPUT
Serial.begin(9600); // start serial communications
}

void loop(){
isButtonOn = digitalRead(joyButton); //read button state& register
posX = analogRead(joyX); // read x-position
posY = analogRead(joyY); // read y-position
redLevel = getRedLevel(posX, posY); // find red level
grnLevel = getGrnLevel(posX, posY); // find green level
bluLevel = getBluLevel(posX,posY);
setRgb(redLevel, grnLevel, bluLevel); //'setRGB' function to update colors
Serial.print("Pos X: ");
Serial.print(posX);
Serial.print('\n');
Serial.print("Pos Y: ");
Serial.print(posY);
}

void setRgb(float redLevel, float grnLevel, float bluLevel) {
analogWrite(redPin, redLevel); // set ‘red’ channel level
analogWrite(grnPin, grnLevel); // set ‘green’ channel level
analogWrite(bluPin, bluLevel); // set ‘blue’ channel level
}
// 'getRedLevel' function b
float getRedLevel(float posX, float posY) {
float redLevel = 0;
if(posX < 171) {
redLevel = 255; // redLevel remains at 255 in this range
}
else if(posX >= 171 && posX < 341) {
redLevel = map(posX,171,340,255, 0); /* redLevel linearly decreases from 255 to 0 in this range*/
}
else if(posX >= 341 && posX < 682) {
redLevel = 0; // redLevel remains at 0 in this range
}
else if(posX >= 682 && posX < 853) {
redLevel = map(posX, 682, 852, 0, 255);/* redLevel linearly increases from 0 to 255 in this range */
}
else {
redLevel = 255; // redLevel remains at 255 in this range
}
return map(posY, 1023, 0, 128, redLevel); //y interpolation and return redLevel
}

// 'getGrnLevel' function
float getGrnLevel(float posX, float posY) {
float grnLevel = 0;
if(posX < 171) {
grnLevel = map(posX, 0, 170, 0, 255); //grnLevel linearly increases from 0 to 255 in this range
}
else if(posX>=171 && posX<512){
grnLevel=255; //greenLevel at max brightness
}
else if(posX>=512 && posX<682){
  grnLevel=map(posX, 512, 681, 255, 0);
}
else if(posX >= 341 && posX < 682) {
grnLevel = 0; // redLevel remains at 0 in this range
}
else {
grnLevel = 0; // redLevel remains at 255 in this range
}
return map(posY, 1023, 0, 128, grnLevel); //Y-interpolation return grnLevel
}
float getBluLevel(float posX, float posY){
  float bluLevel=0;
  if(posX<341){
    bluLevel=0;
    }
  else if (posX>=341 && posX<512){
    bluLevel=map(posX,341, 511, 0, 255 );
  }
  else if(posX>=512 && posX<853){
  bluLevel=255;
  }
  else if (posX>=853 && posX<=1023){
    bluLevel=map(posX,643,1022,255,0);
  }
  else{
    bluLevel=255;
  }
  return map(posY, 1023,0,128,bluLevel);
}
