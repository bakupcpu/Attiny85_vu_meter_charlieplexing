#define LINE_A 0 //Pin 5 (PB0) on ATtiny85
#define LINE_B 1 //Pin 6 (PB1) on ATtiny85
#define LINE_C 2 //Pin 7 (PB2) on ATtiny85
#define LINE_D 3 //Pin 2 (PB3) on ATtiny85


//DDRB direction config for each LED (1 = output)
const char led_dir[12] = {
  ( 1<<LINE_A | 1<<LINE_B ), //LED 0
  ( 1<<LINE_B | 1<<LINE_C ), //LED 1
  ( 1<<LINE_C | 1<<LINE_D ), //LED 2
  ( 1<<LINE_B | 1<<LINE_D ), //LED 3
  ( 1<<LINE_A | 1<<LINE_C ), //LED 4
  ( 1<<LINE_A | 1<<LINE_D ), //LED 5

  ( 1<<LINE_B | 1<<LINE_A ), //LED 6
  ( 1<<LINE_C | 1<<LINE_B ), //LED 7
  ( 1<<LINE_D | 1<<LINE_C ), //LED 8
  ( 1<<LINE_D | 1<<LINE_B ), //LED 9
  ( 1<<LINE_C | 1<<LINE_A ), //LED 10
  ( 1<<LINE_D | 1<<LINE_A ), //LED 11
};

//PORTB output config for each LED (1 = High, 0 = Low)
const char led_out[12] = {
  ( 1<<LINE_A ), //LED 0 Green
  ( 1<<LINE_B ), //LED 1 Green
  ( 1<<LINE_C ), //LED 2 Green
  ( 1<<LINE_B ), //LED 3 Green
  ( 1<<LINE_A ), //LED 4 Green
  ( 1<<LINE_A ), //LED 5 Green

  ( 1<<LINE_B ), //LED 6 Red
  ( 1<<LINE_C ), //LED 7 Red
  ( 1<<LINE_D ), //LED 8 Red
  ( 1<<LINE_D ), //LED 9 Red
  ( 1<<LINE_C ), //LED 10 Red
  ( 1<<LINE_D ), //LED 11 Red

};


void light_led(char led_num) { //led_num must be from 0 to 11
  DDRB = led_dir[led_num];
  PORTB = led_out[led_num];
}

void leds_off() {
  DDRB = 0;
  PORTB = 0; 
}
int LED = 0;
int LED2 = 0;
int IN = 0;
int SET = 0;
long Next = 0;
long pre = 0;
void setup(){

}

void loop(){
  IN = analogRead(2);

  if(IN < 900){

    LED = map( IN, 0, 600, 0, 5);
    if(LED < 0){
      LED = 0;
    }
    if(LED > 5){
      LED = 5;
    }
    if(LED2 < LED){
      LED2 = LED;
    }
    if(SET == 0){
      VU1();
    }
    if(SET == 1){ 
      VU2();
    }
    if(SET == 2){
      VU3();
    }
    if(SET == 3){
      VU4();
    }
    unsigned long cur = millis();

    if( cur - pre > 500){
      Next++;
      LED2 --; 
      pre = cur;
    }
    if(LED2 < 0){
      LED2 = 0;
    }
  }
  else {
    SET++;
    if(SET > 3) {
      SET = 0;
    }
    light_led(0);
    delay(200);
    light_led(6);
    delay(200);
    light_led(SET+2);
    delay(500);
  }


}

void VU1(){

  light_led(LED);
  delayMicroseconds(100);
  if(LED <LED2 ){
    light_led(LED2+6); 
    delayMicroseconds(10); 
  }
}

void VU2(){

  light_led(LED+6);
  delayMicroseconds(100);
  if(LED <LED2 ){
    light_led(LED2); 
    delayMicroseconds(10); 
  }
}

void VU3(){
  if(LED == 0){
    light_led(0);
  }
  if(LED == 1){
    light_led(0);
    delayMicroseconds(200);
    light_led(1);
    delayMicroseconds(200);
  }
  if(LED == 2){
    light_led(0);
    delayMicroseconds(200);
    light_led(1);
    delayMicroseconds(200);
    light_led(2);
    delayMicroseconds(200);
  }
  if(LED == 3){
    light_led(0);
    delayMicroseconds(200);
    light_led(1);
    delayMicroseconds(200);
    light_led(2);
    delayMicroseconds(200);
    light_led(3);
    delayMicroseconds(200);
    light_led(9);
    delayMicroseconds(100);
  }
  if(LED == 4){
    light_led(0);
    delayMicroseconds(200);
    light_led(1);
    delayMicroseconds(200);
    light_led(2);
    delayMicroseconds(200);
    light_led(3);
    delayMicroseconds(200);
    light_led(9);
    delayMicroseconds(100);
    light_led(4);
    delayMicroseconds(200);
    light_led(10);
    delayMicroseconds(100);
  }
  if(LED == 5){
    light_led(0);
    delayMicroseconds(200);
    light_led(1);
    delayMicroseconds(200);
    light_led(2);
    delayMicroseconds(200);
    light_led(3);
    delayMicroseconds(200);
    light_led(9);
    delayMicroseconds(100);
    light_led(4);
    delayMicroseconds(200);
    light_led(10);
    delayMicroseconds(200);
    light_led(11);
    delayMicroseconds(100);
  }
}

void VU4(){
  if(LED == 0){
    light_led(0);
  }
  if(LED == 1){
    light_led(1);
  }
  if(LED == 2){
    light_led(2);
  }
  if(LED == 3){
    light_led(3);
    delayMicroseconds(200);
    light_led(9);
    delayMicroseconds(100);
  }
  if(LED == 4){
    light_led(4);
    delayMicroseconds(200);
    light_led(10);
    delayMicroseconds(100);
  }
  if(LED == 5){
    light_led(11);

  }
}
















