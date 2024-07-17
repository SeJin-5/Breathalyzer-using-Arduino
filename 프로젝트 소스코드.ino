int mq3Pin = A5;    // MQ-3 센서핀을 아두이노 보드의 A5 핀으로 설정
int redPin = 7;   // LED 센서의 R 핀을 아두이노 보드의 7번 핀으로 설정
int greenPin = 6;   //LED 센서의 G 핀을 아두이노 보드의 6번 핀으로 설정
int bluePin = 5;    //LED 센서의 B 핀을 아두이노 보드의 5번 핀으로 설정

void setup() {
  Serial.begin(9600);   // 아두이노 보드와 PC간의 통신속도 설정
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);   // LED의 R, G, B 핀을 출력으로 설정
}

void loop() {
  Serial.println(analogRead(mq3Pin));   //MQ-3 센서 출력값을 시리얼 모니터로 출력
  int val = analogRead(mq3Pin);

  if(val>=400){   // 센서 값이 400 이상이면
    analogWrite(redPin,255);    // 빨간색 LED가 켜짐
    analogWrite(greenPin,0);
    analogWrite(bluePin,0);
    delay(100);
  }
  else if(val>=200 && val<400){   // 센서 값이 200 이상, 400 미만이면
    analogWrite(redPin,0);
    analogWrite(greenPin,255);    // 초록색 LED가 켜짐
    analogWrite(bluePin,0);
    delay(100);
  }
  else if(val>=200 && val<400){   // 센서 값이 200 미만이면
    analogWrite(redPin,0);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);   // 파란색 LED가 켜짐
    delay(100);
  }
}
