#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecureRedirect.h>

char const * const ssid = "ssidName";
char const * const passwd = "ssidPassword";

char const * const dstHost = "script.google.com";
char const * const dstPath = "/macros/s/secrectKey/exec";
int const dstPort = 443;
int32_t const timeout = 5000;

char const * const dstFingerprint = "C7:4A:32:BC:A0:30:E6:A5:63:D1:8B:F4:2E:AC:19:89:81:20:96:BB";
char const * const redirFingerprint = "E6:88:19:5A:3B:53:09:43:DB:15:56:81:7C:43:30:6D:3E:9D:2F:DE";

#define DEBUG
#ifdef DEBUG
#define DPRINT(...)    Serial.print(__VA_ARGS__)
#define DPRINTLN(...)  Serial.println(__VA_ARGS__)
#else
#define DPRINT(...)
#define DPRINTLN(...)
#endif

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.begin(115200);
  delay(500);
  DPRINT("\n\nWifi ");
  WiFi.begin(ssid, passwd);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      DPRINT(".");
  }
  DPRINTLN(" done");
}

void loop() {
  DPRINT("freeing the heap .. ");
  DPRINTLN(ESP.getFreeHeap());
  bool error = true;
  WiFiClientSecureRedirect client;

  DPRINT("Connecting with google database");
  do {
    DPRINT(".");
    if (client.connect(dstHost, dstPort) != 1) {
      break;
    }
    DPRINT(".");
    while (!client.connected()) {
      client.tick();
    }
    DPRINT(".");
    if (client.request(dstPath, dstHost, 2000, dstFingerprint, redirFingerprint) != 0) {
      break;
    }
    DPRINT(".");
    while (!client.response()) {
      client.tick();
    }
    DPRINT(".\n<RESPONSE>\n");
    while (client.available()) {
      String recivedJSON = client.readStringUntil('\n');
      Serial.println("recivedJSON : " + recivedJSON);
      const size_t bufferSize = JSON_OBJECT_SIZE(3) + 111;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      const char* json = recivedJSON.c_str();
      JsonObject& root = jsonBuffer.parseObject(json);
      bool errorStatus = root["status"];
      bool ledStatus = root["ledStatus"];
      const char* msg = root["msg"];
      Serial.print("errorStatus : " );Serial.println(errorStatus);
      Serial.print("ledStatus : ");Serial.println(ledStatus);
      Serial.print("msg : ");Serial.println(msg);
      digitalWrite(LED_BUILTIN, !ledStatus);
    }
    DPRINT("</RESPONSE>");
    client.stop();
    error = false;
  } while (0);
  DPRINTLN(error ? " error" : " done");
}
