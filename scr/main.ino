/**************************************************************
  ESP32-CAM IoT 4-LED Control with Switch Priority and PWM
  Author: Tejas Vane
  Hardware: ESP32-CAM (AI Thinker), 4 LEDs
  Connection: LEDs → GPIO13, GPIO12, GPIO14, GPIO15
**************************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3xQgpYQ-1"
#define BLYNK_TEMPLATE_NAME "Esp32 Cam LED Control"
#define BLYNK_AUTH_TOKEN "5p9CQzjHhfL-gx1JapieGZaDmkag2Y6X"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// ---------- Wi-Fi Credentials ----------
char ssid1[] = "NARZO 70 5G";
char pass1[] = "0100100010001";

char ssid2[] = "C73 5G b377";
char pass2[] = "12345678";

char ssid3[] = "TECNO SPARK 8";
char pass3[] = "123123123";

// ---------- LED Pin Definitions ----------
#define LED1 13
#define LED2 12
#define LED3 14
#define LED4 15

#define LED_ON  HIGH
#define LED_OFF LOW

// ---------- Variables ----------
int led1Value = 0; // Stores slider value
bool led1Switch = false; // Stores switch state

// ---------- Wi-Fi Connection Function ----------
void connectWiFi() {
  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid1, pass1);
  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) delay(500);

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid2, pass2);
    startTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) delay(500);
  }

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid3, pass3);
    startTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected! IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to Wi-Fi.");
  }
}

// ---------- Blynk Virtual Pin Handlers ----------
// Switch ON/OFF (priority)
BLYNK_WRITE(V0) {
  led1Switch = param.asInt(); // Store switch state (0 or 1)
  if(led1Switch) digitalWrite(LED1, LED_ON); // Immediate priority
  else analogWrite(LED1, led1Value); // Back to slider control
}

// PWM Slider
BLYNK_WRITE(V1) {
  led1Value = param.asInt(); // Store slider value (0–255)
  if(!led1Switch) analogWrite(LED1, led1Value); // Only affect LED when switch is OFF
}

// Repeat above for other LEDs
BLYNK_WRITE(V2) { led1Switch = param.asInt(); if(led1Switch) digitalWrite(LED2, LED_ON); else analogWrite(LED2, led1Value); }
BLYNK_WRITE(V3) { led1Value = param.asInt(); if(!led1Switch) analogWrite(LED2, led1Value); }

BLYNK_WRITE(V4) { led1Switch = param.asInt(); if(led1Switch) digitalWrite(LED3, LED_ON); else analogWrite(LED3, led1Value); }
BLYNK_WRITE(V5) { led1Value = param.asInt(); if(!led1Switch) analogWrite(LED3, led1Value); }

BLYNK_WRITE(V6) { led1Switch = param.asInt(); if(led1Switch) digitalWrite(LED4, LED_ON); else analogWrite(LED4, led1Value); }
BLYNK_WRITE(V7) { led1Value = param.asInt(); if(!led1Switch) analogWrite(LED4, led1Value); }

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  delay(100);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // Initialize all LEDs OFF
  digitalWrite(LED1, LED_OFF);
  digitalWrite(LED2, LED_OFF);
  digitalWrite(LED3, LED_OFF);
  digitalWrite(LED4, LED_OFF);

  connectWiFi();

  // Connect to Blynk Cloud
  Blynk.config(BLYNK_AUTH_TOKEN);
  Blynk.connect();
  Serial.println("Connected to Blynk Cloud!");
}

// ---------- Main Loop ----------
void loop() {
  Blynk.run();
}	      delay(500);
	      Serial.print(".");
	    }
	  }
	
	  // Final check
	  if (WiFi.status() == WL_CONNECTED) {
	    Serial.print("\nConnected to Wi-Fi! IP Address: ");
	    Serial.println(WiFi.localIP());
	  } else {
	    Serial.println("\nFailed to connect to any Wi-Fi network.");
	  }
	}
	
	// ---------- Blynk Virtual Pin Handlers ----------
	BLYNK_WRITE(V0) { digitalWrite(LED1, param.asInt() ? LED_ON : LED_OFF); }
	BLYNK_WRITE(V1) { digitalWrite(LED2, param.asInt() ? LED_ON : LED_OFF); }
	BLYNK_WRITE(V2) { digitalWrite(LED3, param.asInt() ? LED_ON : LED_OFF); }
	BLYNK_WRITE(V3) { digitalWrite(LED4, param.asInt() ? LED_ON : LED_OFF); }
	
	// ---------- Setup ----------
	void setup() {
	  Serial.begin(115200);
	  delay(100);
	
	  pinMode(LED1, OUTPUT);
	  pinMode(LED2, OUTPUT);
	  pinMode(LED3, OUTPUT);
	  pinMode(LED4, OUTPUT);
	
	  // Initialize all LEDs OFF
	  digitalWrite(LED1, LED_OFF);
	  digitalWrite(LED2, LED_OFF);
	  digitalWrite(LED3, LED_OFF);
	  digitalWrite(LED4, LED_OFF);
	
	  connectWiFi();
	
	  // Connect to Blynk cloud
	  Blynk.config(BLYNK_AUTH_TOKEN);
	  Blynk.connect();
	  Serial.println("Connected to Blynk Cloud!");
	}
	
	// ---------- Main Loop ----------
	void loop() {
	  Blynk.run();
	}
