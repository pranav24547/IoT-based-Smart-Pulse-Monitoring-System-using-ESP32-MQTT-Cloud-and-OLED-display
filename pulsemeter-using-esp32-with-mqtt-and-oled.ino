#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ---------------- OLED ----------------
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ---------------- WIFI ----------------
const char* ssid = "PranavA34";
const char* password = "";

// ---------------- MQTT ----------------
const char* mqtt_server = "YOUR_MQTT_CLUSTER_URL";
const int mqtt_port = 8883;

const char* mqtt_user = "YOUR_USERNAME";
const char* mqtt_pass = "YOUR_PASSWORD";

// ---------------- Topics ----------------
const char* pulseTopic = "esp32/pulse/value";
const char* statusTopic = "esp32/pulse/status";

// ---------------- Pulse Input ----------------
#define PulsePin 34

WiFiClientSecure secureClient;
PubSubClient client(secureClient);

// ------------------------------------------------

void setup_wifi() {

  Serial.print("Connecting WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected");
}

// ------------------------------------------------

void reconnect() {

  while (!client.connected()) {

    Serial.print("Connecting MQTT...");

    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println(" Connected!");
    }
    else {
      Serial.print(" Failed rc=");
      Serial.println(client.state());
      delay(3000);
    }
  }
}

// ------------------------------------------------

void setup() {

  Serial.begin(115200);

  setup_wifi();

  secureClient.setInsecure();

  client.setServer(mqtt_server, mqtt_port);

  // ---------- OLED Init ----------
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED Failed");
    while (true);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(10, 10);
  display.println("PULSE");
  display.setCursor(10, 35);
  display.println("MONITOR");
  display.display();

  delay(2000);

  Serial.println("ESP32 MQTT OLED System Started");
}

// ------------------------------------------------

void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  int raw = analogRead(PulsePin);

  int bpm = map(raw, 0, 4095, 40, 140);

  String status;

  if (bpm < 60) status = "LOW";
  else if (bpm <= 100) status = "GOOD";
  else status = "HIGH";

  // ---------- MQTT Publish ----------
  client.publish(pulseTopic, String(bpm).c_str());
  client.publish(statusTopic, status.c_str());

  // ---------- OLED Display ----------
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("BPM:");

  display.setTextSize(3);
  display.setCursor(0, 20);
  display.print(bpm);

  display.setTextSize(2);
  display.setCursor(0, 50);
  display.print(status);

  display.display();

  // ---------- Serial ----------
  Serial.print("BPM: ");
  Serial.print(bpm);
  Serial.print(" | Status: ");
  Serial.println(status);

  delay(1000);
}
