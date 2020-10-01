#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[] = "";

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

void onWindowChange();

CloudSwitch window;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(window, READWRITE, ON_CHANGE, onWindowChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
