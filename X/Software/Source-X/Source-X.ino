#include <ps5Controller.h>

#define SERIAL_DEBUG

#define BUILTIN_LED 2
#define BUZZER 3

#define LEFT_WHEEL_FORWARD
#define RIGHT_WHEEL_BACKWARD

#define RIGHT_WHEEL_FORWARD
#define RIGHT_WHEEL_BACKWARD

#define HAND_UP
#define HAND_DOWN

#define HAND_GRAB
#define HAND_RELEASE

#define SLOW_OFFSET 0.5
#define NORMAL_OFFSET 0.75
#define FAST_OFFSET 1

uint8_t leftForwardPWM = 0;
uint8_t leftBackwardPWM = 0;
uint8_t rightForwardPWM = 0;
uint8_t rightBackwardPWM = 0;

void buzz(uint8_t repeat = 1, uint8_t duration = 100);

void forward();

void backward();

void rotateLeft();

void rotateRight();

void handUp();

void handDown();

void handGrab();

void handRelease();

void stand();

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  ps5.begin("10:18:49:6F:39:9F"); // DualSense's MAC address
  
  Serial.begin(115200);

  Serial.println("Waiting for controller");
  
  while (ps5.isConnected() != true) {    
  }
  
  Serial.println("Ready!");
  
  buzz(3, 50);
}

void loop() {
  while (ps5.isConnected() == true) {
    if (ps5.Up()) {
      if(ps5.R1()) {
        if(ps5.RStickX() > 16) {
          Serial.println("Fast Turn Right Forward");
        }
        else if (ps5.RStickX() < -16) {
          Serial.println("Fast Turn Left Forward");
        }
        else {
          Serial.println("Fast Forward");
        }
      }
      else if (ps5.L1()) {
        if(ps5.RStickX() > 16) {
          Serial.println("Slow Turn Right Forward");
        }
        else if (ps5.RStickX() < -16) {
          Serial.println("Slow Turn Left Forward");
        }
        else {
          Serial.println("Slow Forward");
        }
      }
      else {
        if(ps5.RStickX() > 16) {
          Serial.println("Turn Right Forward");
        }
        else if (ps5.RStickX() < -16) {
          Serial.println("Turn Left Forward");
        }
        else {
          Serial.println("Forward");
        }
      }
    }
    else if (ps5.Down()) {
      if(ps5.R1()) {
        if(ps5.RStickX() > 16) {
          Serial.println("Fast Turn Right Backward");
        }
        else if (ps5.RStickX() < -16) {
          Serial.println("Fast Turn Left Backward");
        }
        else {
          Serial.println("Fast Backward");
        }
      }
      else if (ps5.L1()) {
        if(ps5.RStickX() > 16) {
          Serial.println("Slow Turn Right Backward");
        }
        else if (ps5.RStickX() < -16) {
          Serial.println("Slow Turn Left Backward");
        }
        else {
          Serial.println("Slow Backward");
        }
      }
      else {
        if(ps5.RStickX() > 16) {
          Serial.println("Turn Right Backward");
        }
        else if (ps5.RStickX() < -16) {
          Serial.println("Turn Left Backward");
        }
        else {
          Serial.println("Backward");
        }
      }
    }
    else if (ps5.Left()) {
      if(ps5.R1()) {
        Serial.println("Fast Rotate Left");
      }
      else if (ps5.L1()) {
        Serial.println("Slow Rotate Left");
      }
      else {
        Serial.println("Rotate Left");
      }  
    }
    else if (ps5.Right()) {
      if(ps5.R1()) {
        Serial.println("Fast Rotate Right");
      }
      else if (ps5.L1()) {
        Serial.println("Slow Rotate Right");
      }
      else {
        Serial.println("Rotate Right");
      }
    }

    else if (ps5.Triangle()) {
      if(ps5.R1()) {
        Serial.println("Fast Hand Up");
      }
      else if (ps5.L1()) {
        Serial.println("Slow Hand Up");
      }
      else {
        Serial.println("Hand Up");
      }
    }
    else if (ps5.Cross()) {
      if(ps5.R1()) {
        Serial.println("Fast Hand Down");
      }
      else if (ps5.L1()) {
        Serial.println("Slow Hand Down");
      }
      else {
        Serial.println("Hand Down");
      }
    }
    else if (ps5.Square()) {
      Serial.println("Grip");    
    }
    else if (ps5.Circle()) {
      Serial.println("Release");
    }

    else {
      Serial.println("Stand");
    }
    
//      Serial.printf("LX: %d", ps5.LStickX());
//      Serial.printf(" --- LY: %d", ps5.LStickY());
//      Serial.printf(" --- RX: %d", ps5.RStickX());
//      Serial.printf(" --- RY: %d\n", ps5.RStickY());
  }
}

void buzz(uint8_t repeat, uint8_t duration) {
  if ((repeat == 0) || (duration == 0))
    return;
    
  for (uint8_t i = 0; i < repeat - 1; i++) {
    digitalWrite(BUZZER, HIGH);
    digitalWrite(BUILTIN_LED, HIGH);
    delay(duration);
    digitalWrite(BUZZER, LOW);
    digitalWrite(BUILTIN_LED, LOW);
    delay(duration);
  }
  digitalWrite(BUZZER, HIGH);
  digitalWrite(BUILTIN_LED, HIGH);
  delay(duration);
  digitalWrite(BUZZER, LOW);
  digitalWrite(BUILTIN_LED, LOW);
}
