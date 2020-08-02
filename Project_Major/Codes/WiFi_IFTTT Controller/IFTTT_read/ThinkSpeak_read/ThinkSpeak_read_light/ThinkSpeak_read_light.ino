                                                                               //ThinkSpeak Read light//
                                                                               //Use WiFi_IFTTT controller in order to connect to WiFi//


#include<String.h>
#include<SoftwareSerial.h>

SoftwareSerial espSerial(2,3);
String Value_to_be_Recived;
int relay = 8;
String Wifi_Name = "Verzeo";
String Pass_for_Wifi = "Major_Project";
String Recieved_string = "";
int latest_value_by_ThinkSpeak= 0;
 
void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  AT_Command("AT+RST");
  AT_Command("AT+CWMODE = 1");
  AT_Command("AT+CWJAP = \"" +Wifi_Name +"\",\"" +Pass_for_Wifi + "\"");
  delay(1000);
}

void loop() {
  int Data_Recived;
 
  Serial.print(Value_to_be_Recived);
  String Data_recived ="GET  https://api.thingspeak.com/channels/1091001/fields/1.json?results=1"; //Channel no:- 1091001//
 
  AT_Command("AT+CIPMUX=0");
  AT_Command("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  while(Value_to_be_Recived == 0)
  {
   Value_to_be_Recived = espSerial.readString();
   Serial.println("Reciving data ....");
   delay(2000); 
  }
int temp_index = Value_to_be_Recived.lastIndexOf("field1");
Data_Recived = Value_to_be_Recived[temp_index +9];
int Numeric_value_data = Data_recived.toInt();


if(Numeric_value_data == 1)
{
digitalWrite(relay,HIGH);
Serial.println("The bulb must now in ON state");
}
else
{
digitalWrite(relay,LOW); 
Serial.println("The bulb is now OFF!.Check ThinkSpeakChannel for more!!."); 
}
  
  AT_Command("AT = CIPCLOSE = 0");
  Serial.println("The Wifi connetion is now closed!");
  Serial.println("Exiting.......");
  delay(5000);
} 
  
void AT_Command(String AT_console)
{
 Serial.println("AT command =====> ");
 Serial.println("AT_console");
 //Serial.println("Test"); 

  delay(1000);
} 
  
    
  
  
  
