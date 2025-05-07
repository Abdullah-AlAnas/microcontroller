const int led1 = 3;
const int led2 = 6;
const int buzzer = 13;
const int led_end = 2;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_end, OUTPUT);
}

void loop() {
  blinkEffect();
  buzz();

  dimEffect();
  buzz();

  alternateBlink();
  buzz();

  waveEffect();


  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);


  digitalWrite(led_end, HIGH);
  delay(2000);
  digitalWrite(led_end, LOW);


  delay(2000);
}


void blinkEffect() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    delay(400);
  }
}


void dimEffect() {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i <= 255; i += 3) {
      analogWrite(led1, i);
      analogWrite(led2, i);
      delay(15);
    }
    for (int i = 255; i >= 0; i -= 3) {
      analogWrite(led1, i);
      analogWrite(led2, i);
      delay(15);
    }
  }
}

void alternateBlink() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(300);
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    delay(300);
  }
  digitalWrite(led2, LOW);
}


void waveEffect() {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i <= 255; i += 3) {
      analogWrite(led1, i);
      analogWrite(led2, 255 - i);
      delay(15);
    }
    for (int i = 255; i >= 0; i -= 3) {
      analogWrite(led1, i);
      analogWrite(led2, 255 - i);
      delay(15);
    }
  }
}



void buzz() {
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(600);
}

