#include <DS3231.h>
#include <U8glib.h>
// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

 U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_DEV_0|U8G_I2C_OPT_NO_ACK|U8G_I2C_OPT_FAST);

void setup()
{
  // Setup Serial connection
  Serial.begin(115200);
  // Uncomment the next line if you are using an Arduino Leonardo
  //while (!Serial) {}
  // Initialize the rtc object
  rtc.begin();
  // The following lines can be uncommented to set the date and time

 // rtc.setDOW(FRIDAY);     // Set Day-of-Week to SUNDAY

 // rtc.setTime(22, 55, 0);     // Set the time to 12:00:00 (24hr format)

 // rtc.setDate(19, 9, 2019);   // Set the date to January 1st, 2014


  u8g.firstPage();
  do {
      u8g.setFont(u8g_font_unifont);
  } while( u8g.nextPage());
  delay(1000);

}
void loop()

{

  // Send Day-of-Week

  Serial.print(rtc.getDOWStr());

  Serial.print(" ");

  

  // Send date

  Serial.print(rtc.getDateStr());

  Serial.print(" -- ");

 

  // Send time

  Serial.println(rtc.getTimeStr());

  

  // Wait one second before repeating :)

  delay (1000);


 u8g.firstPage();
  do {
      u8g.setPrintPos(0,14);
      u8g.print(String("     ")+rtc.getDOWStr());
      u8g.setPrintPos(0,30);
      u8g.print(String("   ")+rtc.getDateStr());
      u8g.setPrintPos(0,46);
      u8g.print(String("    ")+rtc.getTimeStr());
      u8g.setPrintPos(0,62);
      u8g.print("      HQ");
  }
  while( u8g.nextPage() );

}

