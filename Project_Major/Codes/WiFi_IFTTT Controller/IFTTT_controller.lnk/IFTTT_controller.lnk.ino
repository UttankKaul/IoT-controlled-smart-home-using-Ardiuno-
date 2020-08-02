#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include<SoftwareSerial.h>
SoftwareSerial espSerial(2,3); 
                                                                                                                //IFTTTT_Wifi Controller//
String Connected_WiFi_SSID = "Verzeo";    
String Password_for_WiFi = "MajorProject";

void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  WiFi_AT_Commands("AT");
  if(!espSerial.find("OK"))
  {
   Serial.println("ERROR!! The AT commands are not getiing Read. Is Serial Monitor Running?");
   delay(2000);  
  }
  WiFi_AT_Commands("AT+CWMODE = 1"); // Client Mode//
  //WiFi_AT_Commands("AT+CWLAP");
  WiFi_AT_Commands("AT+CWJAP = \"" +Connected_WiFi_SSID +"\",\"" +Password_for_WiFi + "\"");
  if(!espSerial.find("OK"))
  {
   Serial.println("The WiFI Module can't connect to the Network");
   Serial.println("Please check Following Detail(s)");
   Serial.println("The WifiName(SSID) entered is:-");
   Serial.print(Connected_WiFi_SSID);
   delay(2000);
   Serial.print("The password Provided is :-");
   Serial.print(Password_for_WiFi);
   delay(2000);
  }
  else
  {
    Serial.print(Connected_WiFi_SSID);
    Serial.println("The Ardiuno is now connected to the above WiFi Module");
    delay(2000);
  }
  
  

}

void loop() {
    WiFi_AT_Commands("AT+CIPMUX = 0");
    WiFi_AT_Commands("AT+CIPSEND = \"TCP\",\"api.thingspeak.com\",80"); //protocol,
    String SendData = "Test";
    int x = 4;
    WiFi_AT_Commands("AT+CIPSEND =" +String(SendData.length()+x)); 
    WiFi_AT_Commands("AT = CIPCLOSE = 0");
}


void WiFi_AT_Commands(String AT_Command)
{
  Serial.println("Currunt AT commands =");
  Serial.print(AT_Command);
  espSerial.println(AT_Command);
  delay(1000); 
  
}
