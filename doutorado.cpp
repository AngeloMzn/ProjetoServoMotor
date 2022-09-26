#include <IRremote.h>

#include <Servo.h>

IRrecv sensorIR (6); // instanciar IRrecv em sensorIR

decode_results comando; // declarar variavel comando que guarda os dados vindos do controle remoto

Servo myServo; // instancia do objeto myServo para chamar as funções

int verifica;

int pos = 0;

void setup() {
  
  Serial.begin(9600);
  
  sensorIR.enableIRIn();// metodo que habilita sensor do controle 
  
  myServo.attach(9); // escolher o pino que o servo motor sera controlado
   
}

void loop() {
  if(sensorIR.decode(&comando)){

    Serial.println(comando.value, HEX);
    
    switch(comando.value){

      case(0xFF30CF):{

        verifica = 1;
       
        break;
      
      }
      case(0xFF18E7):{
        
        verifica = 0;
     
        break;
       
        }   
    }

    sensorIR.resume();
    
  }

  if(verifica == 1){
    for(pos = 0; pos <=90; pos++){

      myServo.write(pos); //controla a movimentação
  
    }
 
    delay(10000);
  
    for(pos = 90; pos >= 0; pos--){
    
      myServo.write(pos);   
    
    }
   
    delay(10000);

  }
  else{
    
     pos = 0;
       
     myServo.write(pos);
    
    }
 
}
  
   
   
   
   
   
   
   
   
   
   
   
   
