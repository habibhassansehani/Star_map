
#include <IRremote.h>

const int IR_RECEIVER_PIN = A0;  // Change this to the pin where your IR receiver is connected

// Define the LCD screen
//LiquidCrystal lcd(8,9,10,11,12,13);
#include <LiquidCrystal.h>

//12 star pins
#define Capricorn      A2       // 1 star 
#define Sagittarius    19      // 2 star 
#define Aquarius       2      // 3 star 
#define Scorpio        3       // 4 star 
#define Taurus         4       // 5 star 
#define Leo            5       // 6 star 
#define Virgo          6      // 7 star 
#define Cancer         7       // 8 star 
#define Aries          14       //9 star 
#define Libra          15      // 10 star 
#define Pisces         16      // 11 star 
#define Gemini         17       //12 star


// Create an LCD object
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

IRrecv irrecv(IR_RECEIVER_PIN);

decode_results results;

int day = 0;
int month = 0;
int year = 1950;
String star;
int day_max=31;
int month_max=12;
int year_max=2024;

void setup() {
  Serial.begin(19200);
  irrecv.enableIRIn();  // Start the IR receiver
  pinMode(Gemini, OUTPUT);
  pinMode(Leo, OUTPUT);
  pinMode(Aquarius, OUTPUT);
   pinMode(Libra, OUTPUT);
  pinMode(Capricorn, OUTPUT);
  pinMode(Pisces, OUTPUT);
   pinMode(Aries, OUTPUT);
  pinMode(Cancer, OUTPUT);
  pinMode(Taurus, OUTPUT);
   pinMode(Virgo, OUTPUT);
  pinMode(Sagittarius, OUTPUT);
  pinMode(Scorpio, OUTPUT);
}

void loop(){  

  lcd.clear();

  lcd.setCursor(0, 0); // Set cursor to the first row
  lcd.print("Star Map Project");

  // lcd.setCursor(0, 1); // Set cursor to the second row
  //lcd.print("Day/Month/Year: ");
  lcd.setCursor(6, 0); // Set cursor to the first row
  lcd.clear();
  lcd.print(day);
  lcd.print("/");
  lcd.print(month);
  lcd.print("/");
  lcd.print(year);
  delay(150);

   
    if(day>day_max)
  day=0;
  if(month>month_max)
  month=0;
  if(year>year_max)
  year=1950;
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0xFFA25D:  // Replace this with the hexadecimal value for your specific button 1
        day++;
        break;
      case 0xFF629D:  // Replace this with the hexadecimal value for another button 2
        month++;
        break;
      case 0xFFE21D:  // Replace this with the hexadecimal value for another button 3
        year++;
        break;
      
        case 0xFF22DD://button 4
        day=10;
        break;
        case 0xFFE01F:
        day=20;
        break;
      case 0xFFC23D://button 6
      year=1970;
      break;
      case 0xFF906F: //button 9
      year=1990;
      break;
      case 0xFFA857: //button 8
      year=1980;
      break;
      case 0xFF9867: //button 0
      year=1950;
      day=0;
      month=0;
         digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
      break;
      case 0xFF38C7: // button ok
       check_zodic(day,month);
      break; 
      case 0xFFB04F:// button #
      year=2000;
      break;
      
    }

    irrecv.resume();  // Receive the next value
  
  }
}

void check_zodic(int day, int month)
{
  String horoscope, trait1,trait2,trait3;


  if ((month == 3 && day >= 21) || (month == 4 && day <= 19)) 
  {
     digitalWrite(Aries,HIGH);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
    horoscope = "Aries";
    trait1="Bold";
    trait2="courageous";
    trait3="Hope to Bet";
  }


   else if ((month == 4 && day >= 20) || (month == 5 && day <= 20))
    {
    digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,HIGH);
    horoscope = "Taurus";
    trait1="Attractive";
    trait2="Luxury lover";
    trait3="Musically talented";
   
  } 


  else if ((month == 5 && day >= 21) || (month == 6 && day <= 20)) 
  {
     digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,HIGH);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
    horoscope = "Gemini";
    trait1="Restless nature";
    trait2="Bright";
    trait3="Outgoing";


   
  }


   else if ((month == 6 && day >= 21) || (month == 7 && day <= 22))
    {
       digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,HIGH);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
      horoscope = "Cancer";
    trait1="Earth lover";
    trait2="Personal life";
    trait3="Loyal";
  
 
  } 


  else if ((month == 7 && day >= 23) || (month == 8 && day <= 22)) {
     digitalWrite(Aries,LOW);
         digitalWrite(Leo,HIGH);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
      horoscope = "Leo";
    trait1="Warm";
    trait2="Generous";
    trait3="Strong leader";
    
  
  } 


  else if ((month == 8 && day >= 23) || (month == 9 && day <= 22)) {
    digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,HIGH);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
   horoscope = "Virgo";
    trait1="Delicate nervous system";
    trait2="Happy as single";
    trait3="Good organizer";

  }


  else if ((month == 9 && day >= 23) || (month == 10 && day <= 22)) {
     digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,HIGH);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
    horoscope = "Libra";
    trait1="Desires peace";
    trait2="Social";
    trait3="Avoids conflict";
 
  } 


  else if ((month == 10 && day >= 23) || (month == 11 && day <= 21)) {
    digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,HIGH);
         digitalWrite(Taurus,LOW);
  horoscope = "Scorpio";
    trait1="Hatred of injustice";
    trait2="Secrecy";
    trait3="Religious";
    
   
  } 


  else if ((month == 11 && day >= 22) || (month == 12 && day <= 21)) {
  digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,HIGH);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
    horoscope = "Sagittarius";
    trait1="Restless nature";
    trait2="Love to travel";
    trait3="Risk taker";
    
   
  } 
  
  else if ((month == 12 && day >= 22) || (month == 1 && day <= 19))
   { digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,HIGH);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
    horoscope = "Capricorn";
    trait1="Strong leader";
    trait2="Not lazy";
    trait3="Distant";
   
  } 
  
  else if ((month == 1 && day >= 20) || (month == 2 && day <= 18)) 
  
  {
    digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,LOW);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,HIGH);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,HIGH);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
   horoscope = "Aquarius";
    trait1="Theoretical";
    trait2="Generous";
    trait3="Idealistic";

  } 
  
  else if ((month == 2 && day >= 19) || (month == 3 && day <= 20)) 
  
  { digitalWrite(Aries,LOW);
         digitalWrite(Leo,LOW);
         digitalWrite(Gemini,LOW);
         digitalWrite(Pisces,HIGH);
         digitalWrite(Libra,LOW);
         digitalWrite(Cancer,LOW);
         digitalWrite(Virgo,LOW);
         digitalWrite(Capricorn,LOW);
         digitalWrite(Sagittarius,LOW);
         digitalWrite(Aquarius,LOW);
         digitalWrite(Scorpio,LOW);
         digitalWrite(Taurus,LOW);
     horoscope = "Pisces";
    trait1="Emotional";
    trait2="Artistic";
    trait3="Musical";

  } else {
    horoscope = "Invalid Date";
  }
    Serial.print("You are ");
    Serial.print(horoscope);
    Serial.print("\n");
    Serial.print("Your traits are ");
    Serial.print(trait1);
     Serial.print("   ");
      Serial.print(trait2);
       Serial.print("    ");
        Serial.print(trait3);
    Serial.print("\n");
        lcd.clear();
lcd.print("star=         ");
 lcd.setCursor(8,0);
lcd.print(horoscope);
delay(2000);
    lcd.clear();
    lcd.print(" TRAITS");
 lcd.setCursor(0,1);
    lcd.print(trait1);
    delay(1000);

lcd.clear();
      lcd.print(" TRAITS");
    //setCursor(0,1);
    lcd.setCursor(0,1);
    lcd.print(trait2);
    delay(1000);
      lcd.clear();
      lcd.print(" TRAITS");
    lcd.setCursor(1,1);
    lcd.print(trait3);
    delay(1000);
 
    
}

