#include <Wire.h>                   //include wire library for I2C
#include <LiquidCrystal_I2C.h>      //include LCD I2C library
#include <Servo.h>                  //include servo library

LiquidCrystal_I2C lcd(0x27, 16, 2); //determine the rows and cols of LCD
Servo myServoX;                     // define servo motor for X-axis 
Servo myServoY;                     // define servo motor for Y-axis 

int ServoXPin = 9;                  // define  X-axis pin
int ServoYPin = 10;                 // define  Y-axis pin
int pb = 2;                         // define push button pin
int sensor = 13;                     // define ir sensor pin

int ServoXHomePos = 0;             // set home position for servo for X-axis
int ServoYHomePos = 0;             // set home position for servo for Y-axis
int ServoXPos;                      // define integer for Servo X position
int ServoYPos;                      // define integer for Servo Y position
int XAxlePin = A0;                  // define  X-axis pin control for joystick A0
int YAxlePin = A1;                  // define  Y-axis pin control for joystick A1
int XAxleValue = 0;                 // set start up X-axis value for joystick
int YAxleValue = 0;                 // set start up Y-axis value for joystick
//int range = 12;                     // output range of X or Y movement
/*int center = range/2;               // resting position value
int threshold = range/4;            // resting threshold
*/
int range;                          // output range of X or Y movement
int level = 1;                      // define level of the game

int pbstate;                        // define state of push button as integer
int prevpb = LOW;                   // define state of previous push button pin as integer

int game = LOW;                     // define status of game as integer

unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

void setup()
{   
    lcd.init();                     // initialize lcd
    lcd.backlight();                // backlight the lcd
    lcd.clear();                    // clear the lcd

    pinMode(sensor, INPUT);         //set sensor as an input
    
    myServoX.attach(ServoXPin);     // attaching servo X 
    myServoY.attach(ServoYPin);     // attaching servo Y
    ServoXPos = ServoXHomePos;      // update ServoXPos with home position as startup (90 degree)
    ServoYPos = ServoYHomePos;      // update ServoYPos with home position as startup (90 degree)
    myServoX.write(ServoXPos);      // write angle of servo X -axis (start at home position)
    myServoY.write(ServoYPos);      // write angle of servo Y -axis (start at home position)
    
    Serial.begin(9600);             // initialize serial monitor baud rate
    Serial.println("Press button to PLAY.");  // display the sentence at serial monitor
    lcd.setCursor(0,0);             // set cursor position at row 0 col 0
    lcd.print("Press button");      // display the sentence at LCD
    lcd.setCursor(2,1);             // set cursor position at row 1 col 2
    lcd.print("to PLAY.");          // display the sentence at LCD
}

void loop()
{   
    lcd.setCursor(0,0);             // set cursor position at row 0 col 0
      
    int reading = digitalRead(pb);  // read push button input and store to reading
    if (reading != prevpb)          // check if push button is not pressed
    {
        lastDebounceTime = millis();// reset the debouncing timer
        lcd.clear();                // clear the lcd
        Serial.println("Press button to PLAY."); // display the sentence at serial monitor
        lcd.setCursor(0,0);         // set cursor position at row 0 col 0
        lcd.print("Press button");  // ask user to start the game
        lcd.setCursor(2,1);         // set cursor position at row 1 col 2
        delay(100);                 // delay 100ms
        lcd.print("to PLAY.");      // display the sentence at LCD
        delay(500);                 // delay 100ms
    }
    
    if ((millis() - lastDebounceTime) > debounceDelay)  //if debounce is done
    {
        if (reading != pbstate)     //check if current pushbutton equal with the reading value
        {
              pbstate = reading;    // store reading to current state of push button
              if (pbstate == HIGH)  // if push button is HIGH
              {
                game = !game;       // game status is OFF
              }
        }
    }
    if(game == HIGH)                // check if game status is ON
    {   
        lcd.clear();                // clear the LCD
        Serial.println("Game start"); // display the sentence at serial monitor
        lcd.setCursor(0,0);         // set cursor position at row 0 col 0
        lcd.print("---Game start---");  // indicates game has start at LCD
        
        Serial.print("Level: ");    // display the sentence at serial monitor
        lcd.setCursor(2,1);         // set cursor position at row 1 col 2
        lcd.print("---Level: ");    // show the level at LCD
               
        Serial.println(level);      // display the current level at serial monitor
        lcd.setCursor(11,1);        // set cursor position at row 1 col 11
        lcd.print(level);           // display the current level at LCD
        lcd.setCursor(12,1);        // set cursor position at row 1 col 12
        lcd.print("---");           // show the symbol at LCD
                
        switch(level)               // check case of the switch based on the level of the game
        {
             case 1: range = 25; break;  // level 1, range is 
             case 2: range = 30; break;  // level 2, range is 
             case 3: range = 20; break;  // level 3, range is 
             case 4: range = 25; break;  // level 4, range is 
             default:
             {
                Serial.println("You have achieved the highest level. Congratulations.");  // display the sentence at serial monitor
                game = !game;       // change status of game as OFF
                lcd.clear();        // clear the LCD
                lcd.setCursor(0,0); // set cursor position at row 0 col 0
                lcd.print("You have achieved");
                lcd.setCursor(0,1); // set cursor position at row 1 col 0
                delay(1000);        // delay 1000ms
                lcd.print("the highest level");
                delay(3000);        // delay 3000ms
                lcd.clear();        // clear the LCD
                lcd.setCursor(0,1); // set cursor position at row 1 col 0
                lcd.print("Congratulations.");  // congrats the winner passing all stages of the game
                break;              // break the switch loop
             }
        }
        if(game == HIGH)  // if game status is still ON
        {
          gamestart();    // start the game
        }
        
        delay(10);        // delay 10 ms
    }
    prevpb = reading;     // store reading at prev push button state
}

void gamestart()          // game starts
{   
    XAxleValue = readAxis(XAxlePin);  // store X-Axis value after read in readAxis loop
    YAxleValue = readAxis(YAxlePin);  // store Y-Axis value after read in readAxis loop

    Serial.print(XAxleValue);       // display the X Axis value
    Serial.print(" - ");            // display -
    Serial.println(YAxleValue);     // display the Y Axis value

    myServoX.write(XAxleValue);     // rotate the servo to the X Axis value 
    myServoY.write(YAxleValue);     // rotate the servo to the Y Axis value 

    int goal = digitalRead(sensor); // read the status of the level (done or incomplete)
    if(goal == LOW)                 // if the goal at the current level is completed
    {
      level++;                      // increase the level of the game
      delay(3000);                  // delay 3000 ms
    }
}

int readAxis(int thisAxis)          // function to determine the value of X-Axis
{  
    int reading = analogRead(thisAxis); // read the analog input
    reading = map(reading, 0, 1023, 0, range); // map the reading from the analog input range to the output range:
 
    return reading; //distance;                  // send distance value to the call function
}
