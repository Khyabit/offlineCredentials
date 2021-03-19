#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 ssd = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

struct Credentials {
    String site;
    String username;
    String password;
};

struct Credentials passwords[] = {
    Credentials {
        .site = "Site1",
        .username = "User1",
        .password = "Password1"
    },
    Credentials {
        .site = "Site2",
        .username = "User2",
        .password = "Password2"
    }
};

void setup() {
    Serial.begin(9600);
    ssd.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    ssd.clearDisplay(); 
}

void loop() {

    int len = sizeof(passwords)/sizeof(passwords[0]);
  
    for (int i = 0; i < len; i++) {

        struct Credentials credentials = passwords[i];
        
        String site = credentials.site,
               username = credentials.username,
               password = credentials.password;

        ssd.setFont(&FreeSans9pt7b);
        ssd.clearDisplay();
        ssd.setTextSize(1);
        ssd.setTextColor(WHITE);
        ssd.setCursor(5, 20);
        ssd.println(site);
        ssd.setCursor(5, 40);
        ssd.println(username);
        ssd.setCursor(5, 60);
        ssd.println(password);
        ssd.display();
        delay(10000);
    }
}
