#include <AFMotor.h>

#define trig_pin1 A2
#define echo_pin1 A3
#define trig_pin2 A5
#define echo_pin2 A4
#define trig_pin3 A0
#define echo_pin3 A1
AF_DCMotor motor1(1); 
AF_DCMotor motor2(3); 
int in1 = 13, in2 = 12, in3 =8, in4 = 11;
 // Adjust threshold based on testing  
int en1=9;
int en2=10;

//int time_right_max=170;
//int time_left_max=340;
//int time_rev_max=480;
//int time_for_max=300;
//int time_for_max_2=550;


//int left=1;
//int right=1;


void setup() {
  pinMode(trig_pin1, OUTPUT);
  pinMode(echo_pin1, INPUT);
  pinMode(trig_pin2, OUTPUT);
  pinMode(echo_pin2, INPUT);
  pinMode(trig_pin3, OUTPUT);
  pinMode(echo_pin3, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(en1, OUTPUT);
  pinMode(en2, OUTPUT);
  Serial.begin(4800);
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout
  if (duration == 0) return 0; // No obstacle detected, assume clear path
  int distance = duration * 0.0343 / 2;
  
  return distance;
}

// void moveForward() {
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
//   analogWrite(en1,150);
  

//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
//   analogWrite(en2,150);
// }
void moveForward() {
    int distance2 = getDistance(trig_pin2, echo_pin2);
    int distance3 = getDistance(trig_pin3, echo_pin3);
  Serial.print(" | Sensor2: ");
  Serial.print(distance2);
  Serial.print(" | Sensor3: ");
  Serial.println(distance3);
  int baseSpeed = 110;
  int rightSpeed = baseSpeed;
  int leftSpeed = baseSpeed;
  // Base speed for both motors
  int correction = 50;  // Speed adjustment factor



  // If the right sensor (distance3) detects an obstacle, increase the left motor speed
  if (distance3 < distance2) {
    Serial.println("Right");
    leftSpeed += correction;  // Increase left motor speed (compensate right deviation)
    rightSpeed-=correction;
  }
  // If the left sensor (distance2) detects an obstacle, increase the right motor speed
  if (distance2 < distance3) {
    Serial.println("Left");
    rightSpeed += correction; // Increase right motor speed (compensate left deviation)
    leftSpeed-=correction;
  }
  if (distance2==distance3){
    Serial.println("Straight");
    rightSpeed+=0;
    leftSpeed+=0;
  }

  // Right motor control
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(en1, rightSpeed);

  // Left motor control
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(en2, leftSpeed);
}


void testmoveForward1() {
  int distance1 = getDistance(trig_pin1, echo_pin1);


  

  while(distance1!=7 && distance1!=31 && distance1!=38 && distance1!=45 && distance1!=52 ){
      Serial.print("Sensor1: ");
  Serial.print(distance1);
  Serial.println(" ");

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(en1,50);
    analogWrite(en2,50);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    distance1 = getDistance(trig_pin1, echo_pin1);
  }
  stopMotors();
}

void testmoveForward2() {
  int distance2_in = getDistance(trig_pin2, echo_pin2);
  int distance2 = getDistance(trig_pin2, echo_pin2);
  int distance3 = getDistance(trig_pin3, echo_pin3);
  int base_speed=100;
  int correction=50;

  

  while(distance2>10 || distance3>10){
    int left_motor=base_speed;
    int right_motor=base_speed;
    if (distance2>distance2_in){
      left_motor+=correction;
      right_motor-=correction;
    }
    else if(distance2<distance2_in){
      left_motor-=correction;
      right_motor+=correction;
    }
    else if(distance2==distance2_in){
      left_motor+=0;
      right_motor-=0;
    }
  

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(en1,right_motor);
    analogWrite(en2,left_motor);

    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    distance2 = getDistance(trig_pin2, echo_pin2);
    distance3 = getDistance(trig_pin3, echo_pin3);
  }
  stopMotors();
}

void stopMotors() {
 motor1.run(FORWARD);
  motor1.setSpeed(0);
  motor2.run(FORWARD);
  motor2.setSpeed(0);
}

void turnLeft() {
//   while(true){
//   motor1.run(FORWARD);
//   motor1.setSpeed(255);
//   motor2.run(FORWARD);
//   motor2.setSpeed(255);
// }
  
  // testmoveForward(time_for_max);

  // stopMotors();
  // testmoveForward1();
  Serial.println("Success1");
  stopMotors();
  delay(500);
  


  // int initial_distance=distance1;
  // int distance1 = getDistance(trig_pin1, echo_pin1);
  // int distance2 = getDistance(trig_pin2, echo_pin2);
  // int distance3_in = getDistance(trig_pin3, echo_pin3);
  // Serial.println(distance3_in);
  int distance1_in = getDistance(trig_pin1, echo_pin1);

  int distance3 = getDistance(trig_pin2, echo_pin2);
  // int distance1 = getDistance(trig_pin1, echo_pin1);
  // int distance2 = getDistance(trig_pin2, echo_pin2);


    // while (true) {  
    //   // Serial.println(distance1);
    //   distance3 = getDistance(trig_pin2, echo_pin2);
        // distance1 = getDistance(trig_pin1, echo_pin1);
        // distance2 = getDistance(trig_pin2, echo_pin2);

        // Rotate left
        // digitalWrite(in1, HIGH);
        // digitalWrite(in2, LOW);
        // analogWrite(en1, 30);
        // analogWrite(en2, 30);
        // digitalWrite(in3, HIGH);
        // digitalWrite(in4, LOW);
    int start_time=millis();
  while(millis()-start_time<150){   
  motor1.run(BACKWARD);
  motor1.setSpeed(80);
  motor2.run(FORWARD);
  motor2.setSpeed(100);
  }

    //     delay(50);  // Small delay for stability

    //     // Stop rotating when front distance matches the initial side distance
    //     if (abs(distance3 - distance1_in) <=3) {  // Allow small tolerance
    //         break;
    //     }
    // }
    // Serial.println("success");


  // }

  // while(1==1){
  // Serial.print(distance3);
  // Serial.println(" ");
  // digitalWrite(in1, HIGH);
  // digitalWrite(in2, LOW);
  // analogWrite(en1,150);
  // analogWrite(en2,150);
  // digitalWrite(in3, HIGH);
  // digitalWrite(in4,LOW);

  // delay(50);
  // distance3 = getDistance(trig_pin3, echo_pin3);
  // distance1 = getDistance(trig_pin1, echo_pin1);
  // if (distance3>26 && distance1>26){
  //   break;
  // }


  // }


  // // while(distance3>23){
  // // Serial.print(distance3);
  // // Serial.println(" ");
  // // digitalWrite(in1, HIGH);
  // // digitalWrite(in2, LOW);
  // // analogWrite(en1,150);
  // // analogWrite(en2,150);
  // // digitalWrite(in3, HIGH);
  // // digitalWrite(in4,LOW);

  // // delay(50);
  // // distance3 = getDistance(trig_pin3, echo_pin3);


  // // }
  // // Serial.println("Success2");
  // // stopMotors();
  // // delay(200);
  
  // // while(distance3<24){
  // //   Serial.print(distance3);
  // // digitalWrite(in1, HIGH);
  // // digitalWrite(in2, LOW);
  // // analogWrite(en1,150);
  // // analogWrite(en2,150);
  // // digitalWrite(in3, HIGH);
  // // digitalWrite(in4,LOW);
  // // delay(50);
  // // distance3 = getDistance(trig_pin3, echo_pin3);

  // // }
  // // Serial.println("Success3");
  delay(200);

  // testmoveForward(time_for_max_2);
  // testmoveForward2();

  stopMotors();


}

void turnRight() {

  // stopMotors();
  // testmoveForward1();
//   stopMotors();
//   // int distance1 = getDistance(trig_pin1, echo_pin1);
//   // int distance3_in = getDistance(trig_pin3, echo_pin3);
//   // Serial.println(distance3_in);
//   int distance1_in = getDistance(trig_pin1, echo_pin1);

//   int distance3 = getDistance(trig_pin3, echo_pin3);
//   while(true){
//    motor1.setSpeed(100);
//   motor1.run(FORWARD);

//   motor2.setSpeed(80);
//   motor2.run(BACKWARD);
// }
//   // int distance1 = getDistance(trig_pin1, echo_pin1);
//   // int distance2 = getDistance(trig_pin2, echo_pin2);

//     while (true) {  
//       // Serial.println(distance1);
//       distance3 = getDistance(trig_pin3, echo_pin3);
//         // distance1 = getDistance(trig_pin1, echo_pin1);
//         // distance2 = getDistance(trig_pin2, echo_pin2);

//         // Rotate left
//         motor1.setSpeed(100);
//   motor1.run(FORWARD);

//   motor2.setSpeed(80);
//   motor2.run(BACKWARD);

//         delay(50);  // Small delay for stability

//         // Stop rotating when front distance matches the initial side distance
//         if (abs(distance1_in - distance3) == 3) {  // Allow small tolerance
//             break;
//         }
//     }
 int start_time=millis();
  while(millis()-start_time<200){   
  motor1.run(FORWARD);
  motor1.setSpeed(80);
  motor2.run(BACKWARD);
  motor2.setSpeed(100);
  }
  // int distance3 = getDistance(trig_pin3, echo_pin3);
  // int initial_distance=distance1;

  // while(distance2>23){
  //   digitalWrite(in1, LOW);
  //   digitalWrite(in2, HIGH);
  //   analogWrite(en1,150);
  //   analogWrite(en2,150);

  //   digitalWrite(in3, LOW);
  //   digitalWrite(in4, HIGH);
  //   distance2 = getDistance(trig_pin2, echo_pin2);
  //   // ticks_right++;
  // }


  // while(distance2<24){
  //   digitalWrite(in1, LOW);
  //   digitalWrite(in2, HIGH);
  //   analogWrite(en1,150);
  //   analogWrite(en2,150);

  //   digitalWrite(in3, LOW);
  //   digitalWrite(in4, HIGH);
  //   distance2 = getDistance(trig_pin2, echo_pin2);
  //   // ticks_right++;
  // }
  delay(200);
  // testmoveForward(time_for_max_2);
  testmoveForward2();

  stopMotors();

}

void Reverse() {
  stopMotors();  
  int distance1 = getDistance(trig_pin1, echo_pin1);
  
  while (distance1 < 35) {  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(en1, 150);
    analogWrite(en2, 150);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    delay(50); 
    distance1 = getDistance(trig_pin1, echo_pin1); 
  }

  stopMotors();  
}

void loop() {

  int distance1 = getDistance(trig_pin1, echo_pin1);
  delay(10);
  int distance2 = getDistance(trig_pin2, echo_pin2);
  delay(10);
  int distance3 = getDistance(trig_pin3, echo_pin3);
  delay(10);
  int threshold=10;
  // delay(1000);
  // testmoveForward(550);
  // delay(1000000);

  // turnLeft();
  // delay(2000);

  // Reverse();
  // delay(2000);
  // motor1.setSpeed(227);
  // motor1.run(FORWARD);

  // motor2.setSpeed(250);
  // motor2.run(FORWARD);
 
if (distance1>threshold){
  motor1.setSpeed(100);
  motor1.run(FORWARD);

  motor2.setSpeed(90);
  motor2.run(FORWARD);

}
else if(distance3>threshold){
  turnLeft();
}
else if(distance2>threshold){
  Serial.println("high");
  turnRight();
}
else{
  stopMotors();
}
// //  motor1.setSpeed(80);
//   motor1.run(FORWARD);

//   motor2.setSpeed(100);
//   motor2.run(FORWARD);
// motor1.setSpeed(100);
//   motor1.run(FORWARD);

//   motor2.setSpeed(80);
//   motor2.run(FORWARD);

  // Serial.print("Sensor1: ");
  // Serial.print(distance1);
  // Serial.print(" | Sensor2: ");
  // Serial.print(distance2);
  // Serial.print(" | Sensor3: ");
  // Serial.println(distance3);
  // moveForward();
  // Reverse();
  // delay(10000000);

  // if(distance1 < 10 && distance2 < 10 && distance3 < 10){

  //   Reverse();
  // }
  
  
  // else if (distance3 > threshold) {
  //   int start_time=millis();
  //   while(millis()-start_time<50){
  //     Serial.print(" | Sensor3: ");
  //     Serial.println(distance3);
  //     distance3 = getDistance(trig_pin3, echo_pin3);
  //     if(distance3<threshold){
  //       left=0;
  //     }
  //   }
  //   if (left==0){

  //     left=1;

  //   }
  //   else if(left==1){
  //   Serial.println("left");


  //   turnLeft();
  //   }
    
  // }

  // else if(distance1>9){
  //   Serial.println("forward");

  //   moveForward();
    
  // }

  // else if(distance2>threshold){

  //   int start_time=millis();
  //   while(millis()-start_time<200){
  //     distance2 = getDistance(trig_pin2, echo_pin2);
  //     if(distance3<threshold){
  //       right=0;
  //     }
  //   }
  //   if (right==0){

  //     right=1;

  //   }
  //   else if(right==1){
  //   Serial.println("right");

  //   turnRight();
  //   }
  // }



  // else{
  //   stopMotors();
  // }
    

  // turnLeft();
  // delay(1000000);

  
}
