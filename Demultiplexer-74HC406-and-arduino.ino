 
/*
<><><><><><><><><><><><><><><><><>
----------------------------------
    Demultiplexer 74HC4067
    
by frmurgia © 2018-19 MIT License
      sgtmurgia@gmail.com
----------------------------------
<><><><><><><><><><><><><><><><><>

collegare S0 al pin D4
collegare S1 al pin D5
collegare S2 al pin D6
collegare S3 al pin D7

collegare z al pin +5V
collegare EN al pin GND

*/



//Digital pinOut
int s0 = 4;
int s1 = 5;
int s2 = 6;
int s3 = 7;


void setup(){



  //Demux
  pinMode(s0, OUTPUT); 
  pinMode(s1, OUTPUT); 
  pinMode(s2, OUTPUT); 
  pinMode(s3, OUTPUT); 
 

  digitalWrite(s0, LOW);
  digitalWrite(s1, LOW);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
    Serial.begin(9600);
}

int writeMux(int channel){
  int controlPin[] = {s0, s1, s2, s3};

//tabella verità
  int muxChannel[16][4]={
    {0,0,0,0}, //channel 0
    {1,0,0,0}, //channel 1
    {0,1,0,0}, //channel 2
    {1,1,0,0}, //channel 3
    {0,0,1,0}, //channel 4
    {1,0,1,0}, //channel 5
    {0,1,1,0}, //channel 6
    {1,1,1,0}, //channel 7
    {0,0,0,1}, //channel 8
    {1,0,0,1}, //channel 9
    {0,1,0,1}, //channel 10
    {1,1,0,1}, //channel 11
    {0,0,1,1}, //channel 12
    {1,0,1,1}, //channel 13
    {0,1,1,1}, //channel 14
    {1,1,1,1}  //channel 15
  };

  //loop attraversoi 4 pin di segnale
  for(int i = 0; i < 4; i ++){
    digitalWrite(controlPin[i], muxChannel[channel][i]);
  }
 
}
 


void loop(){
  
for(int i=0;i<15;i++){
  writeMux(i);// chiama la funzione che attiva ogni pin  
  delay(160);
  }

}
 
