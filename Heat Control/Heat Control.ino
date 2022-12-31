// blynk info
#define BLYNK_TEMPLATE_ID "TMPLTe61Jcwc"
#define BLYNK_DEVICE_NAME "test"
char auth[] = "bhUqmnYKKQfgoGBaSMOv-ImhK4zETrjQ";

// library
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// wifi name&password
char ssid[] = "onpoj1F_2.4G";
char pass[] = "0000000009";

// relay D pin
const int relay1 = 33;
const int relay2 = 25;
const int relay3 = 26;
const int relay4 = 27;

void setup() {
  Serial.begin(9600);

  // Set pin OUTPUT
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  pinMode(relay4, OUTPUT);

  // set relay off at start
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);

  // connect to WiFi and Blynk
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(WiFi.status());
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk connected");
}

void loop() {
  Blynk.run();
}

// button in blynk apps
BLYNK_WRITE(V1) {
  int butValue = param.asInt();

  if (butValue == 0) {
    digitalWrite(relay1, HIGH);
  } else {
    digitalWrite(relay1, LOW);
  }
}

BLYNK_WRITE(V2) {
  int butValue = param.asInt();
  if (butValue == 0) {
    digitalWrite(relay2, HIGH);
  } else {
    digitalWrite(relay2, LOW);
  }
}

BLYNK_WRITE(V3) {
  int butValue = param.asInt();
  if (butValue == 0) {
    digitalWrite(relay3, HIGH);
  } else {
    digitalWrite(relay3, LOW);
  }
}

BLYNK_WRITE(V4) {
  int butValue = param.asInt();
  if (butValue == 0) {
    digitalWrite(relay4, HIGH);
  } else {
    digitalWrite(relay4, LOW);
  }
}
