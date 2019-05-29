
#define SPEED_VALUE 100
const int stepPin = 3;
const int dirPin = 4;
int timeDelay = 1000;//init value is 1[ms]
char buf;
void initPin();
void inputComand();
void run();

void setup() {
  Serial.begin(9600);
  initPin();
}

void loop() {
  //wait for input
  inputComand();
  //run based on input
  run();
}

void initPin() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  digitalWrite(dirPin, HIGH);
}

void inputComand() {
  // buf = "";
  // while(1) {
  //   if(Serial.available()) {
  //     char c = char(Serial.read());
  //     buf += c;
  //     if(c == '\n') {break;}
  //   }
  // }
  while(1) {
    if(Serial.available()) {
      buf = char(Serial.read());
      Serial.println(buf);
      break;
    }
  }
}

void run() {

  switch(buf) {
    case 'c':
    digitalWrite(dirPin, HIGH);
    break;
    case 'w':
    digitalWrite(dirPin, LOW);
    break;
    case 'u':
    timeDelay -= SPEED_VALUE;
    break;
    case 'd':
    timeDelay += SPEED_VALUE;
    break;
    default:
    break;
  }
  Serial.print("timeDelay: ");
  Serial.println(timeDelay);

  for(int i = 0; i < 200; i++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(timeDelay);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(timeDelay);
  }

  // switch(buf) {
  //   case "CW":
  //   digitalWrite(dirPin, HIGH);
  //   break;
  //   case "CCW":
  //   digitalWrite(dirPin, LOW);
  //   break;
  //   case "up":
  //   timeDelay -= SPEED_VALUE;
  //   break;
  //   case "down":
  //   timeDelay += SPEED_VALUE;
  //   break;
  //   case "move":
  //   for(int i = 0; i < 200; i++) {
  //     digitalWrite(dirPin, HIGH);
  //     delayMicroseconds(timeDelay);
  //     digitalWrite(dirPin, LOW);
  //     delayMicroseconds(timeDelay);
  //   }
  //   break;
  //   default:
  //   Serial.println("error");
  //   break;
  // }
}
