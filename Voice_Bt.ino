String voice;
int 
m1a = 6, //Connect LED 1 To Pin #6 
m1b = 7, //Connect LED 2 To Pin #12 
m2a = 8, //Connect LED 2 To Pin #11
m2b = 9;

 void setup() {
  Serial.begin(9600);
  pinMode(m1a, OUTPUT); 
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT); 
  pinMode(m2b, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
}
//-----------------------------------------------------------------------//  
 void loop() {
  while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  }  
  if (voice.length() > 0) {
    Serial.println(voice); 
//-----------------------------------------------------------------------//    
    
if(voice == "*move forward")
{
digitalWrite(6,0);
digitalWrite(7,1);
digitalWrite(8,1);
digitalWrite(9,0);
} 
else if(voice == "*move back")
{
digitalWrite(6,1);
digitalWrite(7,0);
digitalWrite(8,0);
digitalWrite(9,1);
} 
else if(voice == "*stop")
{
  digitalWrite(6,0);
  digitalWrite(7,0);
  digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(4,0);
  digitalWrite(5,0);
  
}    
else if(voice == "*turn left")
{
  digitalWrite(6,0);
  digitalWrite(7,1);
  digitalWrite(8,0);
  digitalWrite(9,1);
  
  
}
else if(voice == "*turn right")
{
  digitalWrite(6,1);
  digitalWrite(7,0);
  digitalWrite(8,1);
  digitalWrite(9,0);
 
}
 
 else if(voice == "*hook up")
{
  digitalWrite(4,0);
  digitalWrite(5,1);
 
} 
 
  else if(voice == "*hook down")
{
  digitalWrite(4,1);
  digitalWrite(5,0);
 
} 
//-----------------------------------------------------------------------//  
voice="";}} //Reset the variable after initiating
