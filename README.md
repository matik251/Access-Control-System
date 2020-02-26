# Access Control System
 Embedded system project on Espressif boards

|Element| Purpose|
|---|---|
|ESP-32 CAM | Esp32 with cam and SD card to take and store photos |
| PIR HC-SR501 sensor | Detects movement in environemnt of module and wakes esp from deepsleep|
| ESP8266 | Handles rfid data and sends to connected pc via USB |
| RFID PN532 sensor | Reads RFID cards and tags |


## Operation

ESP8266 sends data obtained from RFID so program running on connected PC can read it (example with putty):

Sample photo from ESP32-CAM took after high-state signal from RFID:

## Board scheme

## Board project