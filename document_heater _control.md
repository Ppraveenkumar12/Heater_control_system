 Heater Control System – Embedded Project (Arduino + Wokwi)

 Project Overview

This project simulates a **basic heater control system** using an Arduino UNO on the Wokwi platform. It uses a potentiometer as a stand-in for a temperature sensor (since sensors like LM35 are not supported in Wokwi). The system transitions through different states—Idle, Heating, Stabilizing, Target Reached, and Overheat—based on the simulated temperature input. Visual feedback is provided using an LED, and the system logs all events through the serial monitor.


 System States

The system logic includes the following temperature-based states:

| State             | Description                                                                 |
|------------------|-----------------------------------------------------------------------------|
| **Idle**          | Temperature below 25°C – heater remains off                                 |
| **Heating**       | Temperature between 25°C and 39°C – heater turns ON                         |
| **Stabilizing**   | Temperature between 40°C and 44°C – heater stays ON but prepares to stop    |
| **Target Reached**| Temperature exactly at 45°C – target achieved, heater turns OFF             |
| **Overheat**      | Temperature above 45°C – heater forced OFF and buzzer alerts (if used)      |

---

 Components Used (Wokwi Simulation)

| Component         | Purpose                                      |
|------------------|----------------------------------------------|
| Arduino UNO       | Microcontroller for logic execution          |
| Potentiometer     | Simulates analog temperature sensor          |
| LED               | Visual indicator for heater ON/OFF status    |
| Serial Monitor    | Displays logs of temperature and system state|
| (Optional) Buzzer | Audio alert for Overheat state               |

 **Note**: LM35 or other physical sensors are **not supported in Wokwi**, hence a potentiometer is used to simulate varying temperatures manually.


 Working Principle:-

1. The potentiometer provides a varying analog voltage to simulate temperature.
2. The Arduino reads the analog value and maps it to a temperature range (0–100°C).
3. Based on defined temperature thresholds, the system transitions through states.
4. The heater (LED) is turned ON or OFF based on the current state.
5. Status updates are printed to the Serial Monitor for debugging and traceability.

---

 Features Implemented:-

-> Temperature monitoring using analog input  
-> 5 system states with clear transitions  
-> Heater (LED) activation and deactivation  
-> Serial logging for debugging   
->Structured and modular C++ code  
-> Fully simulated in Wokwi


 Future Roadmap:-

- Replace potentiometer with actual temperature sensor (e.g., LM35/DS18B20) on hardware
- Support multiple heating profiles for different targets
- Add EEPROM to save user preferences
- Enable BLE or IoT-based remote monitoring
- Include touch buttons or LCD display for local interaction
- Add hysteresis to avoid frequent ON/OFF toggling near thresholds

