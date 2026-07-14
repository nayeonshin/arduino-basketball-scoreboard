#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int score = 0;

void setup() {
    Serial.begin(115200);
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    pinMode(8, INPUT);
    lcd.setCursor(0,0);
    lcd.print("Play Basketball!");
}

void loop() {
    if (Serial.available()) {
        String restart = Serial.readStringUntil("\n");
        if (restart == "RESTART") {
            score = 0;
            lcd.setCursor(0,1);
            lcd.print("                ");
        }
    }

    if (!digitalRead(8)) {
        score += 2;
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(0,1);
        lcd.print("Score: ");
        lcd.setCursor(7,1);
        lcd.print(score);
        delay(1000);
    }  
}
