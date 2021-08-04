//RGB color light values

//Initialization of variables on arduino pins
int red_light_pin_1= 2;
int green_light_pin_1 = 3;
int blue_light_pin_1 = 4;
int red_light_pin_2= 5;
int green_light_pin_2 = 6;
int blue_light_pin_2 = 7;
int red_light_pin_3= 8;
int green_light_pin_3 = 9;
int blue_light_pin_3 = 10;
int red_light_pin_d= 11;
int green_light_pin_d = 12;
int blue_light_pin_d = 13;
void setup() {
  pinMode(red_light_pin_1, OUTPUT);
  pinMode(green_light_pin_1, OUTPUT);
  pinMode(blue_light_pin_1, OUTPUT);
  pinMode(red_light_pin_2, OUTPUT);
  pinMode(green_light_pin_2, OUTPUT);
  pinMode(blue_light_pin_2, OUTPUT);
  pinMode(red_light_pin_3, OUTPUT);
  pinMode(green_light_pin_3, OUTPUT);
  pinMode(blue_light_pin_3, OUTPUT);
  pinMode(red_light_pin_d, OUTPUT);
  pinMode(green_light_pin_d, OUTPUT);
  pinMode(blue_light_pin_d, OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
}
void loop() {
  //Color combinations and patterns
  RGB_color(0,255,0); // Red
  delay(100);
  RGB_color_2(0, 255, 0); // Green
  delay(100);
  RGB_color_3(0, 255, 0); // Blue
  delay(100);
  RGB_color_d(0, 255, 0); // white
  delay(1000);
  
  RGB_color(255,255,0); // Red
  delay(100);
  RGB_color_2(255, 255, 0); 
  delay(100);
  RGB_color_3(255, 255, 0);
  delay(100);
  RGB_color_d(255, 255, 0); 
  delay(1000); 
  
  RGB_color(255,0,255); 
  delay(100);
  RGB_color_2(0, 0, 200);
  delay(100);
  RGB_color_3(0, 0, 200); 
  delay(100);
  RGB_color_d(255, 0, 255); 
  delay(1000); 

  RGB_color_d(255,255,0); 
  delay(100);
  RGB_color_3(255, 255, 0); 
  delay(100);
  RGB_color_2(255, 255, 0); 
  delay(100);
  RGB_color(255, 255, 0); 
  delay(1000); 

}
void RGB_color(int red_light_value_1, int green_light_value_1, int blue_light_value_1)
 {
  analogWrite(red_light_pin_1, red_light_value_1);
  analogWrite(green_light_pin_1, green_light_value_1);
  analogWrite(blue_light_pin_1, blue_light_value_1);
}
void RGB_color_2(int red_light_value_2, int green_light_value_2, int blue_light_value_2)
 {
  analogWrite(red_light_pin_2, red_light_value_2);
  analogWrite(green_light_pin_2, green_light_value_2);
  analogWrite(blue_light_pin_2, blue_light_value_2);
}
void RGB_color_3(int red_light_value_3, int green_light_value_3, int blue_light_value_3)
 {
  analogWrite(red_light_pin_3, red_light_value_3);
  analogWrite(green_light_pin_3, green_light_value_3);
  analogWrite(blue_light_pin_3, blue_light_value_3);
}
void RGB_color_d(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin_d, red_light_value);
  analogWrite(green_light_pin_d, green_light_value);
  analogWrite(blue_light_pin_d, blue_light_value);
}
