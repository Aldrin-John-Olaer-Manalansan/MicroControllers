Installation:

1) Download a Clone of [this](https://github.com/Aldrin-John-Olaer-Manalansan/MicroControllers/tree/master/ESP32%20CAM/WebSocketWebServerOnePort "this") Repository.
2) Install [Links2004's arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets "Links2004's arduinoWebSockets").
3) go to your [WebSocketWebServerOnePort/Libraries/arduinoWebSockets-master/](https://github.com/Aldrin-John-Olaer-Manalansan/MicroControllers/tree/master/ESP32%20CAM/WebSocketWebServerOnePort/Libraries/arduinoWebSockets-master "WebSocketWebServerOnePort/Libraries/arduinoWebSockets-master/").
4) "MOVE" the [WebSocketsServer.h](https://github.com/Aldrin-John-Olaer-Manalansan/MicroControllers/blob/master/ESP32%20CAM/WebSocketWebServerOnePort/Libraries/arduinoWebSockets-master/WebSocketsServer.h "WebSocketsServer.h") and Replace Links2004's WebSocketsServer.h(commonly found at "Documents\Arduino\Libraries\arduinoWebSockets-master\src\WebSocketsServer.h").
5) Open Arduino IDE and upload this sketch(.ino file) using ESP32 Wrover board.

  When ESP32 Successfully Connected to the defined Wi-Fi, you can access it using aaa.bbb.ccc.184 where "aaa.bbb.ccc" is the first,second, and third octet of your router's default gateway(commonly will become 192.168.1.184 for routers with default gateway of 192.168.1.1)
  
  When ESP32 fails to connect to the defined Wi-Fi, it creates an ACCESSPOINT with credentials(you can change it at the ino sketch if you like):
  
SSID: IP Camera: Qa!e6

Password: Ba0!*sL8
