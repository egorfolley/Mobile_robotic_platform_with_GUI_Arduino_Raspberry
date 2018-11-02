#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Follia-PC";
const char* password = "offthewall";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;
char incomingPacket[1];

char control_button[1];

void setup()
{
  Serial.begin(57600);
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
}

void loop()
{
  remoteIP = "192.168.137.55";
  int packetSize = Udp.parsePacket();
  if (packetSize)
  {
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 1);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);

    if (incomingPacket == "w")
    {
      control_button[0] = 'w';
      Serial.write(control_button[0]);
    }
    if (incomingPacket == "a")
    {
      control_button[0] = 'a';
      Serial.write(control_button[0]);
    }
    if (incomingPacket == "s")
    {
      control_button[0] = 's';
      Serial.write(control_button[0]);
    }
    if (incomingPacket == "d")
    {
      control_button[0] = 'd';
      Serial.write(control_button[0]);
    }
    if (incomingPacket == "v")
    {
      control_button[0] = 'v';
      Serial.write(control_button[0]);
    }
  }
}
