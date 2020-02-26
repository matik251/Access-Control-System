#include <Wire.h> //
#include <PN532_I2C.h> 
#include <PN532.h> 
#include <NfcAdapter.h> 

PN532_I2C pn532(Wire); // Set PN532 runs on i2C SCL:D1 SDA:D2

int logged = 0;
String id ="";
 
NfcAdapter nfc = NfcAdapter(pn532);  
 void setup(void) {
  Serial.begin(115200);
  Serial.println("Initializing please wait.......");

  pinMode(15, OUTPUT);
  digitalWrite(15,LOW);
  delay(3000);
  nfc.begin();
}
 
void loop(void) {
  if (nfc.tagPresent())
  {
    NfcTag tag = nfc.read();
    Serial.println(tag.getTagType());
    Serial.print("UID: ");Serial.println(tag.getUidString()); 
    id = tag.getUidString();
    if(id.equals("E9 41 AD 43") && logged != 1){
      logged = 1;
      digitalWrite(15,HIGH);
      delay(100);
      digitalWrite(15,LOW);  
    }else{
      logged = 0;
      digitalWrite(15,LOW);            
    }
      digitalWrite(15,LOW); 
 
    if (tag.hasNdefMessage()) //check for data
    {
      NdefMessage message = tag.getNdefMessage();
      int recordCount = message.getRecordCount();
      for (int i = 0; i < recordCount; i++)
      {
        Serial.print("NDEFRecord ");
        Serial.println(i+1);
        NdefRecord record = message.getRecord(i);
        int payloadLength = record.getPayloadLength();
        byte payload[payloadLength];
        record.getPayload(payload);
        String valString = "";
        for (int j = 0; j < payloadLength; j++) {
          valString += (char)payload[j];
        }
        Serial.print("INFO: ");
        Serial.println(valString);
      }
    }
    delay(5000);
  }  
}
