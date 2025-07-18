#define ldrSensor A0     
#define kirmiziLed 8      
#define  yesilLed 13   
#define  maviLed 10   
#define  buzzer 7  
#define  buton 5    
int butonDurum = 0;

void setup() {
  pinMode(kirmiziLed, OUTPUT);    
  pinMode(yesilLed, OUTPUT);   
  pinMode(maviLed, OUTPUT);    
  pinMode(buzzer, OUTPUT);   
  pinMode(buton, INPUT);  
  Serial.begin(9600);             
}

void loop() {
  
  int isikSeviyesi = analogRead(ldrSensor);
  Serial.print("Işık Seviyesi: ");
  Serial.println(isikSeviyesi);

 
  digitalWrite(kirmiziLed, LOW);
  digitalWrite(yesilLed, LOW);
  digitalWrite(maviLed, LOW);
  digitalWrite(buzzer, LOW);

  butonDurum = digitalRead(buton);


  if (isikSeviyesi >= 100 && isikSeviyesi < 300) {

    digitalWrite(kirmiziLed, HIGH);  
    digitalWrite(yesilLed, LOW); 
    digitalWrite(maviLed, LOW);  
    digitalWrite(buzzer, HIGH);  

    if(butonDurum == HIGH){
      digitalWrite(buzzer,LOW);
      digitalWrite(kirmiziLed,LOW);
    }

  } else if (isikSeviyesi >= 300 && isikSeviyesi < 500) {

    digitalWrite(yesilLed, HIGH);
    digitalWrite(kirmiziLed, LOW);
    digitalWrite(maviLed, LOW);
    

  } else if (isikSeviyesi >= 500) {

    digitalWrite(maviLed, HIGH); 
    digitalWrite(kirmiziLed, LOW); 
    digitalWrite(yesilLed, LOW); 
     

  }

  delay(1000); 
}
