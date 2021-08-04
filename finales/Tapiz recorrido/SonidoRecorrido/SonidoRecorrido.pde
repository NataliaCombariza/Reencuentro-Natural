//Import Libraries
import processing.sound.*;
import processing.serial.*;
//Initialize sounds
SoundFile song1;
SoundFile song2;

//Arduino info
Serial myPort;
int linefeed = 10;   // Linefeed in ASCII
int numSensors = 5;  // we will be expecting for reading data from four sensors
int sensors[];       // array to read the 5 values
float amplitude = 0.00;
// actual reading with the last one


void setup() {
  size(200, 200);
  
 //Initialize connection with arduino through the computer ports
  myPort = new Serial(this, Serial.list()[2], 9600);
  // read bytes into a buffer until you get a linefeed (ASCII 10):
  myPort.bufferUntil(linefeed);

  // Create a Sound object for globally controlling the output volume.
  song1 = new SoundFile(this,"SonidoCiudad.mp3");
  song1.amp(0.01);
  song1.loop();
  song2 = new SoundFile(this,"SonidoNaturaleza.mp3");
  song2.amp(0.1);
  song2.loop();
}

void draw() {
  // Map vertical mouse position to volume.
  // Instead of setting the volume for every oscillator individually, we can just
  // control the overall output volume of the whole Sound library.
  song2.amp(amplitude);
  song1.amp(1-amplitude);
}

void serialEvent(Serial myPort) {

  // read the serial buffer:
  String myString = myPort.readStringUntil(linefeed);

  // if you got any bytes other than the linefeed:
  if (myString != null) {

    myString = trim(myString);
    println(myString);
    if(myString.equals("uno")){
      amplitude = 0.20 ;
    } else if(myString.equals("dos")) {
      amplitude = 0.40 ;
    } else if(myString.equals("tres")) {
      amplitude = 0.60;
    }else if(myString.equals("cuatro")) {
      amplitude = 0.70;
    }else if(myString.equals("cinco")) {
      amplitude = 0.99;
    }else if(myString.equals("zero")) {
      amplitude = 0.00;
    }
    
  }
}
