int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int Pin1 = A0; 
int Pin2 = A1;
int Pin3 = A2;
int Pin4 = A3;

int channelTime1 = 0;
int channelTime2 = 0;
int channelTime3 = 0;
int channelTime4 = 0;

int globalTime = 0;

float value1 = 0;
float value2 = 0;
float value3 = 0;
float value4 = 0;
void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(500);
}
void loop() {
if (globalTime >= 30)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
else
{
//Channel 1 ****************************************
  Serial.print("MOISTURE LEVEL 1:");
  value1 = analogRead(Pin1);
  Serial.println(value1);
  if(value1<500)  //a reading below 500 means the soil is moist enough
  {
      digitalWrite(IN1, HIGH);
      if (channelTime1 > 0){
        channelTime1--;
      }
  }
  else if (value1 >= 500 && channelTime1 < 8)
  {
    digitalWrite(IN1, LOW);
    channelTime1++;
    }
  else if (value1 >= 500 && channelTime1 >= 8)  //this would indicate that the soil is dry and the channel has tried to fill it
  {
    Serial.println("Channel 1 is dry and timed out.");
    digitalWrite(IN1, HIGH);
    globalTime++;
  }
  else 
  {
    Serial.println("How'd you get here?  --Channel 1");
  }
    
//Channel 2 ****************************************
  Serial.print("MOISTURE LEVEL 2:");
  value2 = analogRead(Pin2);
  Serial.println(value2);
  if(value2<500)  //a reading below 500 means the soil is moist enough
  {
      digitalWrite(IN2, HIGH);
      if (channelTime2 > 0){
        channelTime2--;
      }
  }
  else if (value2 >= 500 && channelTime2 < 8)
  {
    digitalWrite(IN2, LOW);
    channelTime2++;
    }
  else if (value2 >= 500 && channelTime2 >= 8)  //this would indicate that the soil is dry and the channel has tried to fill it
  {
    Serial.println("Channel 2 is dry and timed out.");
    digitalWrite(IN2, HIGH);
    globalTime++;
  }
  else 
  {
    Serial.println("How'd you get here?  --Channel 2");
  }
    
//Channel 3 ****************************************
  Serial.print("MOISTURE LEVEL 3:");
  value3 = analogRead(Pin3);
  Serial.println(value3);
  if(value3<500)  //a reading below 500 means the soil is moist enough
  {
      digitalWrite(IN3, HIGH);
      if (channelTime3 > 0){
        channelTime3--;
      }
  }
  else if (value3 >= 500 && channelTime3 < 8)
  {
    digitalWrite(IN3, LOW);
    channelTime3++;
    }
  else if (value3 >= 500 && channelTime3 >= 8)  //this would indicate that the soil is dry and the channel has tried to fill it
  {
    Serial.println("Channel 3 is dry and timed out.");
    digitalWrite(IN3, HIGH);
    globalTime++;
  }
  else 
  {
    Serial.println("How'd you get here?  --Channel 3");
  }
    
// //Channel 4 ****************************************
//   Serial.print("MOISTURE LEVEL 4:");
//   value4 = analogRead(Pin4);
//   Serial.println(value4);
//   if(value4<500)  //a reading below 500 means the soil is moist enough
//   {
//       digitalWrite(IN4, HIGH);
//       if (channelTime4 > 0){
//         channelTime4--;
//       }
//   }
//   else if (value4 >= 500 && channelTime4 < 8)
//   {
//     digitalWrite(IN4, LOW);
//     channelTime4++;
//     }
//   else if (value4 >= 500 && channelTime4 >= 8)  //this would indicate that the soil is dry and the channel has tried to fill it
//   {
//     Serial.println("Channel 4 is dry and timed out.");
//     digitalWrite(IN4, HIGH);
//     globalTime++;
//   }
//   else 
//   {
//     Serial.println("How'd you get here?  --Channel 4");
//   }
    
// //Channel 2 Original code
//   Serial.print("MOISTURE LEVEL 2:");
//   value2 = analogRead(Pin2);
//   Serial.println(value2);
//   if(value2<500)
//   {
//       digitalWrite(IN2, HIGH);
//   }
//   else
//   {
//     digitalWrite(IN2, LOW);
//   }

  Serial.println();
  delay(1000);
}
}
