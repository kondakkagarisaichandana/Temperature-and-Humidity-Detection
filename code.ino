#define BLYNK_TEMPLATE_ID "TMPL3CXHs_W9t"
#define BLYNK_TEMPLATE_NAME "temp humidity "
#define BLYNK_AUTH_TOKEN "hcvjNz5BWl4jnR5lrC-DgHqZtvN2IvdT"

#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

#define DHTPIN D2        
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);

char ssid[] = "Galaxy Tab A (8.0, 2019)8254";  
char pass[] = "saichandana"; 

#define LED_PIN D4

void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);

    WiFi.setSleepMode(WIFI_NONE_SLEEP); // Prevent Wi-Fi sleep

    // Attempt Wi-Fi connection until successful
    Serial.print("Connecting to Wi-Fi");
    WiFi.begin(ssid, pass);
    int attempt = 0;
    while (WiFi.status() != WL_CONNECTED) {
        for (int i = 0; i < 5; i++) {
            digitalWrite(LED_PIN, LOW);
            delay(250);
            digitalWrite(LED_PIN, HIGH);
            delay(250);
            Serial.print(".");
        }
        attempt++;
        if (attempt > 10) { // Give up after 10 attempts
            Serial.println("\nFailed to connect to Wi-Fi ❌");
            return;
        }
    }

    Serial.println("\nWi-Fi connected ✅");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

    // Configure and connect to Blynk
    Blynk.config(BLYNK_AUTH_TOKEN);
    if (Blynk.connect()) {
        Serial.println("Connected to Blynk ✅");
    } else {
        Serial.println("Failed to connect to Blynk ❌");
    }

    dht.begin();

    // Confirm connection with a quick LED blink
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
}

void loop() {
    Blynk.run(); 
    sendSensorData(); // Send both temperature and humidity
    delay(2000);
}

void sendSensorData() {
    float temp = dht.readTemperature(); // Read temperature in Celsius
    float hum = dht.readHumidity();     // Read humidity in percentage

    if (isnan(temp) || isnan(hum)) {
        Serial.println("Failed to read from DHT sensor!");
        Blynk.virtualWrite(V1, "Sensor Error");
        Blynk.virtualWrite(V2, "Sensor Error");
    } else {
        // Send temperature to gauge widget on V0
        Serial.print("Temperature: ");
        Serial.print(temp);
        Serial.println(" °C");
        Blynk.virtualWrite(V0, temp);
        
        // Send humidity to gauge widget on V2
        Serial.print("Humidity: ");
        Serial.print(hum);
        Serial.println(" %");
        Blynk.virtualWrite(V2, hum);
        
        // Update status message based on temperature
        if (temp > 30) {
            Blynk.virtualWrite(V1, "🔥 Too Hot!");
        } else if (temp < 18) {
            Blynk.virtualWrite(V1, "❄️ Too Cold!");
        } else {
            Blynk.virtualWrite(V1, "✅ Normal");
        }

        // Update status message based on humidity
        if (hum > 70) {
            Blynk.virtualWrite(V3, "💧 High Humidity!");
        } else if (hum < 30) {
            Blynk.virtualWrite(V3, "🌵 Low Humidity!");
        } else {
            Blynk.virtualWrite(V3, "✅ Humidity OK");
        }
    }
}


