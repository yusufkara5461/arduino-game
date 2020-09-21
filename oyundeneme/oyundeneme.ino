//ALL CODE HAS BEEN WRITED BY YUSUF KARAMEHMETOGLU.
//IT'S NOT ALLOWED TO SHARE THE SAME CODE WITHOUT INDICATING THE AUTHOR.
#include <LiquidCrystal.h>
byte oyuncu[] = {
  B10000,
  B11000,
  B11100,
  B11111,
  B11111,
  B11100,
  B11000,
  B10000
};
byte dusman[] = {
  B00000,
  B00000,
  B00110,
  B11110,
  B11110,
  B00110,
  B00000,
  B00000
};
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
Serial.begin(9600);
lcd.createChar(0,oyuncu);
lcd.createChar(1,dusman);
lcd.begin(16, 2);
pinMode(13, INPUT);
}
int Kaybettin(){
  for(int i=0;i<2;i++){
  lcd.clear();
  delay(500);
  lcd.setCursor(3,0);
  lcd.print("YOU LOST");
  delay(500);
  }
  return 0;
}




int z[4];
int n=0;
int val=0;

void loop() {
  a:
  while(Kaybettin){
  val=val+digitalRead(13);
  for(int i=0;i<2;i++){
     lcd.clear();
     lcd.setCursor(4,val%2);
     lcd.write(byte(0));
     for(int j=0;j<4;j++){
      
      if((n-j*4)%16==0){        
            z[j]=rand()%2;  
        }
        if(15-(n-j*4)%16==4&&z[j]==val%2){
          Kaybettin();
          goto a;
        }
        lcd.setCursor(15-((n-j*4)%16),z[j]);
        lcd.write(byte(1)); 
     }
  }
  n++;
  delay(250); 
  }
}
