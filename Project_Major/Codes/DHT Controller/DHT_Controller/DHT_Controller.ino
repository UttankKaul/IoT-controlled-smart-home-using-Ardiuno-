                                                                                     DHT_Controller 
                                                           //Use wifi_IFTTT Controller in order to Connect to the WiFi//
                                                           //Thinkspeak Channel id :- 1091001. Refer to the this channel after conpiling the Below Code//

                                                          
#include <dht.h>
#define dht_apin A0

dht DHT_Command;
double Value_to_be_Send;

SoftwareSerial espSerial(2,3);

String Wifi_Name = "Verzeo";
String Pass_for_Wifi = "Major_project";
 
void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);
  AT_Command("AT+RST");
  AT_Command("AT+CWMODE = 1");
  AT_Command("AT+CWJAP = \"" +Wifi_Name +"\",\"" +Pass_for_Wifi + "\"");
  delay(1000);
}

void loop() {
  DHT_Command.read(dht_apin);
  Value_to_be_send = DHT.temprature;
  Serial.println("the Data that will be send is:-");
  Serial.print(Value_to_be_sent);
  String Data_sent "GET  update?api_key=CG2R0KFHH52JIKSV&field1=" +String(Value_to_be_send); //Channel no:- 1091001//
  AT_Command("AT+CIPMUX=0");
  AT_Command("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80");
  AT_Commmand("AT+CIPSEND=" +String(Data_sent.length()+2));
  Serial.println("The value has been sent to the IFTTT.Check it?");
  AT_Command("AT = CIPCLOSE = 0");
  delay(5000);
} 
  
void AT_Command(String AT_console)
{
 Serial.println("AT command =====> ");
 Serial.println(AT_console);
 //Serial.println("Test"); 
  espSerial.println(AT_cosole);
  delay(1000);
} 
  
    
  
  
  

}
