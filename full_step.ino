
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5; 
int in5 = 6; 
int in6 = 7;
int in7 = 8;
int in8 = 9;
int n = 0;
int stepsperrev = 200;

void stepper_set_rpm(int rpm) {
  delayMicroseconds(60000000/(stepsperrev*rpm));
}

void full_step(uint8_t in_1, uint8_t in_2, uint8_t in_3, uint8_t in_4, uint8_t steps) {
      if (steps==0) {digitalWrite(in_1, 1); digitalWrite(in_2, 0); digitalWrite(in_3, 0); digitalWrite(in_4, 0);} // mỗi xung = 1.8
      else if (steps==1) {digitalWrite(in_1, 0); digitalWrite(in_2, 0); digitalWrite(in_3, 1); digitalWrite(in_4, 0);}
      else if (steps==2) {digitalWrite(in_1, 0); digitalWrite(in_2, 1); digitalWrite(in_3, 0); digitalWrite(in_4, 0);}
      else if (steps==3) {digitalWrite(in_1, 0); digitalWrite(in_2, 0); digitalWrite(in_3, 0); digitalWrite(in_4, 1);}
}

void counter_clockwise(uint8_t in_1, uint8_t in_2, uint8_t in_3, uint8_t in_4, uint8_t steps) {
      if (steps==0) {digitalWrite(in_1, 1); digitalWrite(in_2, 0); digitalWrite(in_3, 0); digitalWrite(in_4, 0);}
      else if (steps==1) {digitalWrite(in_1, 0); digitalWrite(in_2, 0); digitalWrite(in_3, 0); digitalWrite(in_4, 1);}
      else if (steps==2) {digitalWrite(in_1, 0); digitalWrite(in_2, 1); digitalWrite(in_3, 0); digitalWrite(in_4, 0);}
      else if (steps==3) {digitalWrite(in_1, 0); digitalWrite(in_2, 0); digitalWrite(in_3, 1); digitalWrite(in_4, 0);}
}

void full_step_angle(uint8_t in_1, uint8_t in_2, uint8_t in_3, uint8_t in_4, float angle, int dir, int rpm) {
  float a_p_s = 7.2;  
  int n_o_s = (int)(angle/a_p_s);
  for (int seq=0; seq <= n_o_s; seq++)
  {
    if (dir == 0)  // for clockwise
    {
      for (int steps = 3; steps>=0; steps--)
      {
       full_step(in_1, in_2, in_3, in_4, steps);
          stepper_set_rpm(2*rpm);
      }
    }
    else if (dir == 1)  // for counter-clockwise
    {
      for (int steps = 0; steps<4; steps++)
      {
        full_step(in_1, in_2, in_3, in_4, steps);
          stepper_set_rpm(2*rpm);
      }
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 // put your main code here, to run repeatedly:
  Serial.println("Ô số mấy?: ");
  while(Serial.available() == 0){
    }
  n = Serial.parseInt();
  Serial.print(n);
  switch(n){
case 1:
      full_step_angle(in5, in6, in7, in8, 120, 1, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 760, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 760, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 120, 0, 800);
      delay(1000);
      break;
     case 2:
      full_step_angle(in5, in6, in7, in8, 20, 0, 400);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 960, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 960, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 20, 1, 400);
      delay(1000);
      break;
     case 3:
      full_step_angle(in5, in6, in7, in8, 215, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 1100, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 1100, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 215, 1, 800);
      delay(1000);
      break;
     case 4:
      full_step_angle(in5, in6, in7, in8, 0, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 760, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 760, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 0, 1, 800);
      delay(1000);
      break;
     case 5:
      full_step_angle(in5, in6, in7, in8, 100, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 900, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 900, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 100, 1, 800);
      delay(1000);
      break;
     case 6:
      full_step_angle(in5, in6, in7, in8, 180, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 985, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 985, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 180, 1, 800);
      delay(1000);
      break;
     case 7:
      full_step_angle(in5, in6, in7, in8, 105, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 700, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 700, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 105, 1, 800);
      delay(1000);
      break;
     case 8:
      full_step_angle(in5, in6, in7, in8, 160, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 790, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 790, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 160, 1, 800);
      delay(1000);
      break;
     case 9:
      full_step_angle(in5, in6, in7, in8, 250, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 850, 0, 800);
      delay(1000);
      full_step_angle(in1, in2, in3, in4, 850, 1, 800);
      delay(1000);
      full_step_angle(in5, in6, in7, in8, 250, 1, 800);
      delay(1000);
      break;
  }
}
