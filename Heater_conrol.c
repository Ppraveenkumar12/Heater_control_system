/ Pin configuration
const int tempSensorPin = A0;    // Simulated temperature sensor using potentiometer
const int heaterPin = 8;         // Heater simulated with LED

// Temperature thresholds in °C
const float idleThreshold = 25.0;
const float heatingThreshold = 35.0;
const float targetThreshold = 45.0;
const float overheatThreshold = 55.0;

enum HeaterState {
  IDLE,
  HEATING,
  STABILIZING,
  TARGET_REACHED,
  OVERHEAT
};

HeaterState currentState;

void setup() {
  pinMode(heaterPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);
  
  // Simulate temperature between 0 to 100°C
  float temperature = map(sensorValue, 0, 1023, 0, 100);
  
  updateState(temperature);
  controlHeater(currentState);
  
  logStatus(temperature, currentState);
  delay(1000);
}

void updateState(float temp) {
  if (temp < idleThreshold) {
    currentState = IDLE;
  } else if (temp < heatingThreshold) {
    currentState = HEATING;
  } else if (temp < targetThreshold) {
    currentState = STABILIZING;
  } else if (temp < overheatThreshold) {
    currentState = TARGET_REACHED;
  } else {
    currentState = OVERHEAT;
  }
}

void controlHeater(HeaterState state) {
  if (state == HEATING || state == STABILIZING) {
    digitalWrite(heaterPin, HIGH);  // Turn ON heater
  } else {
    digitalWrite(heaterPin, LOW);   // Turn OFF heater
  }
}

void logStatus(float temp, HeaterState state) {
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" C | State: ");
  
  switch(state) {
    case IDLE: Serial.println("IDLE"); break;
    case HEATING: Serial.println("HEATING"); break;
    case STABILIZING: Serial.println("STABILIZING"); break;
    case TARGET_REACHED: Serial.println("TARGET REACHED"); break;
    case OVERHEAT: Serial.println("OVERHEAT"); break;
  }
}


