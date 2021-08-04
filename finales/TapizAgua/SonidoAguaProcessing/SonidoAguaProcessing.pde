//Import libraries
import processing.sound.*;
import processing.serial.*;
//Initialize constants and variables
SoundFile song1;
WhiteNoise noise;
//Arduino info
Serial myPort;
int linefeed = 10;   // Linefeed in ASCII
float amplitudeNoise = 0.01;
float amplitudeNature = 0.01;
int numSensors = 2;
int sensors[];       // array to read the 5 values
// actual reading with the last one


void setup() {
  size(200, 200);
  // Create the noise generator
  noise = new WhiteNoise(this);
  noise.amp(amplitudeNoise);
  noise.play();
  
  //Initialize connection with arduino through the computer ports
  myPort = new Serial(this, Serial.list()[2], 9600);
  // read bytes into a buffer until you get a linefeed (ASCII 10):
  myPort.bufferUntil(linefeed);

  // Create a Sound object for globally controlling the output volume.
  song1 = new SoundFile(this,"SonidoNaturaleza.mp3");
  song1.amp(amplitudeNature);
  song1.loop();
}

void draw() {
  // Map vertical mouse position to volume.
  // Instead of setting the volume for every oscillator individually, we can just
  // control the overall output volume of the whole Sound library.
  if (sensors != null) {
    amplitudeNature = (map(sensors[0],100,700,0,100))* 0.001;
    amplitudeNoise =(map(sensors[1],900,0,100,0))* 0.001;
  }
  song1.amp(amplitudeNature);
  noise.amp(amplitudeNoise);
}

void serialEvent(Serial myPort) {

  // read the serial buffer:
  String myString = myPort.readStringUntil(linefeed);

  // if you got any bytes other than the linefeed:
  if (myString != null) {
    myString = trim(myString);
    print(myString);
    // split the string at the commas
    // and convert the sections into integers:
    sensors = int(split(myString, ','));
  }
}
