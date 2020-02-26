# Access Control System
 Embedded system project on Espressif boards with sensors. Device consist from two modules: RFID connected to PC and supervision module that is powered by powerbank. Data obtained is transmitted to PC via USB. Additionally you can find on sd card images from camera that is triggered by PIR sensor.

|Element| Purpose|
|---|---|
|ESP-32 CAM | Esp32 with cam and SD card to take and store photos |
| PIR HC-SR501 sensor | Detects movement in environemnt of module and wakes esp from deepsleep|
| ESP8266 | Handles rfid data and sends to connected pc via USB |
| RFID PN532 sensor | Reads RFID cards and tags |


## Operation

↓↓↓ ESP8266 sends data obtained from RFID so program running on connected PC can read it (example with putty)

<img align ="left" width="70%" src="https://github.com/matik251/Access-Control-System/blob/master/rfid_putty.png"> <img align="right" width="20%" src="https://github.com/matik251/Access-Control-System/blob/master/example_photo.png">

Sample photo from ESP32-CAM took after high-state signal from RFID →→→

## Board scheme
<p align="center">
  <img width="70%" src="https://github.com/matik251/Access-Control-System/blob/master/smiw_schemat.PNG">
</p>

## Board project
<p align="center">
  <img width="70%" src="https://github.com/matik251/Access-Control-System/blob/master/smiw_plytka.PNG">
</p>
