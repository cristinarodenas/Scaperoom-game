const int buttonPin1 = 2;      //entered connection button 1 with pin 2
const int buttonPin2 = 4;      //entered connection button 2 with pin 4
const int buttonPin3 = 7;      //entered connection button 3 with pin 7
const int ledPin = 13;         //entered connection led with pin 13

int buttonState1 = 0;         // defined button's state
int buttonState2 = 0;         // defined button's state
int buttonState3 = 0;         // defined button's state

String preguntes[3] = {"pre1", "pre2", "pre3"};  //entered question's variables
int respostes[3] = {0, 1, 2};                    //entered round as answers


int rnd = 0;    //defined variable rnd at 0
int i = 0;      //defined variable i at 0

void setup() {
  // put your setup code here, to run once:

  pinMode (buttonPin1, INPUT);    //defined button 1 as an input
  pinMode (buttonPin2, INPUT);    //defined button 2 as an input
  pinMode (buttonPin3, INPUT);    //defined button 3 as an input

  pinMode (ledPin, OUTPUT);       //defined led as an output

  Serial.begin(9600);            //begin serial communication
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(preguntes[rnd]);       //print round of the question in the monitor serie

  while (digitalRead(buttonPin1) == HIGH && digitalRead(buttonPin2) == HIGH && digitalRead(buttonPin3) == HIGH) {   //defined what happens while all the buttons are high
  }

  int res;          //defined variable res
  int parpadeig;    //defined variable parpadeig

  if (digitalRead(buttonPin1) == LOW) {          //defined what happens if the button 1 is low
    res = 0;                                     // defined the value res
    parpadeig = 3;                               //defined how many times the led has to switch on
  }
  else if (digitalRead(buttonPin2) == LOW) {     //defined what happens if the button 2 is low
    res = 1;          // defined the value res
    parpadeig = 5;    //defined how many times the led has to open
  } else {            //defined what happens if the button 3 is low
    res = 2;          // defined the value res
    parpadeig = 1;    //defined how many times the led has to open
  }

  if (res == respostes[rnd]) {             //defined what happens if res value's is the same as rnd's value
    Serial.println("resposta correcta");   //print "resposta correcta" in the monitor serie
    Serial.println (rnd);                  //print rnd value in the monitor serie
    rnd = rnd + 1;                         //increase 1 at the value's round

    Serial.println (parpadeig);               //print how many times the led has to switch on
    for ( int i = 0; i <= parpadeig; i++) {   //defined loop for the flicker of the led
      digitalWrite(ledPin, HIGH);             //led switch on
      delay (500);                            //defined time which the led has to be on
      digitalWrite(ledPin, LOW);              //led switch off
      delay(500);                             //defined time which the led has to be off
    }

  }
  else {
    Serial.println("resposta incorrecta");    //print "resposta incorrecta" in the serial monitor if the answer is incorrect
    delay(500);

  }

}
