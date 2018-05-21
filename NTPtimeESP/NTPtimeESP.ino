
#include <NTPtimeESP32.h>

#define DEBUG_ON


NTPtime NTPch("ch.pool.ntp.org");   // Choose server pool as required
char *ssid      = "Schenck Family";               // Set you WiFi SSID
char *password  = "Ridger1990";               // Set you WiFi password


strDateTime dateTime;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booted");
  Serial.println("Connecting to Wi-Fi");

  WiFi.mode(WIFI_STA);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected");
}

void loop() {

  dateTime = NTPch.getNTPtime(1.0, 1);

  if(dateTime.valid){
    NTPch.printDateTime(dateTime);

    byte actualHour = dateTime.hour;
    byte actualMinute = dateTime.minute;
    byte actualsecond = dateTime.second;
    int actualyear = dateTime.year;
    byte actualMonth = dateTime.month;
    byte actualday =dateTime.day;
    byte actualdayofWeek = dateTime.dayofWeek;
  }
}
