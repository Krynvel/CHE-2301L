// RGB LED project – 'setRGB' function

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

//INSERT your code here//

else if(posX >= 341 && posX < 682) {

grnLevel = 0; // redLevel remains at 0 in this range

}

else if(posX >= 682 && posX < 853) {

grnLevel = map(posX, 682, 852, 0, 255);/* redLevel linearly increases from 0 to 255 in this range */

}

else {
grnLevel = 255; // redLevel remains at 255 in this range

return map(posY, 1023, 0, 128, grnLevel); //Y-interpolation return grnLevel

}
