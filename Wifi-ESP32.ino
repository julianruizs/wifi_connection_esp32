#include <WiFi.h> // Include wifi library
//--------------------------------------------
#define WLAN  ""  // Include WLAN name
#define PASSWD "" // Include PASSWD of WLAN
#define TIME_OUT 15000 //Modify connection timeot in miliseconds
//--------------------------------------------

void wifi_connection(){
  Serial.println("Start WiFi connection"); // Print initial message
  Serial.println("---------------------");
  WiFi.mode(WIFI_STA); // Select WiFi mode
  WiFi.begin(WLAN,PASSWD); // Initialize WiFi connection
 //-----------------------------------------------------------------//
 
 unsigned long start_time = millis(); //Save the initial time of connection

 while(WiFi.status() != WL_CONNECTED && millis()- start_time < TIME_OUT){ // While the connection is not made it will print "."
 Serial.print(".");                                                    // and the time does not exceed 15 seconds
 delay(100); 
 }

 if(WiFi.status() == WL_CONNECTED){ // it checks if the connection is successful
  Serial.println(" ");              // if the connection is successfull it prints your device local IP 
  Serial.println("Successfull connection");
  Serial.print("Your IP direction is: ");
  Serial.println(WiFi.localIP()); 
 }
 else
 {Serial.println(" "); // If the device does not connect it will reboot after 15 seconds
  Serial.println("Connection error, this device will be restart...");
  delay(500);
  ESP.restart();
 }

}

void setup() {  
Serial.begin(115200); // Initialize serial communication
wifi_connection();
}

void loop() {

// Your code goes here
}
