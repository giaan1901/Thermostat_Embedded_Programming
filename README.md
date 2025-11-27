Thermostat Controller – STM32F411CEU6

Author: Hà Gia An – 2352004

📌 Overview

This project implements a simple thermostat controller using an STM32F411CEU6 microcontroller.
The system periodically measures room temperature, allows the user to configure a temperature setpoint, and controls an air-conditioner fan using an ON/OFF control algorithm.

✨ Features

Temperature measurement every 500 ms

Temperature resolution: 1 °C

User interface with 4 buttons:

POWER

SET

UP

DOWN

LCD 16×2 with I2C interface

ON/OFF fan control based on setpoint

Display of:

Current temperature

Fan state (ON/OFF)

System state (ON/OFF)

Setpoint value

🧰 Hardware Used

STM32F411CEU6 (Black Pill)

LCD 16x2 I2C (PCF8574 backpack)

Temperature sensor (LM35, DS18B20, or equivalent)

4 push buttons

Fan output driver (Relay or MOSFET)

5V / 3.3V power supply

🔌 Pin Configuration (Example)
Component	Pin
I2C LCD – SCL	PB8
I2C LCD – SDA	PB9
Button – POWER	PA0
Button – SET	PA1
Button – UP	PA2
Button – DOWN	PA3
Temperature Sensor (ADC)	PA4
Fan Control Output	PA5

Pin assignments may be modified as needed.

🧠 Software Architecture
1. Temperature Sampling Task

Runs every 500 ms

Reads from ADC or digital sensor

Converts raw value to °C

Updates global temperature variable

2. Control Algorithm (ON/OFF)
if (temperature > setpoint)
    fan = ON;
else
    fan = OFF;

3. User Interface

Button scanning + debouncing (10–20 ms)

Supports short press & long press

Updates display and internal states

4. LCD Display Task

Runs periodically or event-based

Shows real-time temperature, fan state, and setpoint

📺 LCD Display Format
Normal Operation:
Temp: 27C  Fan:ON
Setpoint: 25C

Setpoint Adjustment Mode:
Adjust Setpoint:
       26C

🕹 User Manual (with Specific Button Hold Times)

All buttons include debouncing and hold detection.

1. POWER Button

Short Press ( < 500 ms )
Toggle system ON → OFF → ON

Long Press ( > 1.5 seconds )
Reserved for future features (e.g., reset or calibration)

Behavior:

When OFF, the fan is forced OFF.

LCD shows:

System OFF

2. SET Button

Short Press ( < 500 ms )
Enter or exit Setpoint Adjustment Mode.

Long Press ( > 1.5 seconds )
Reset setpoint to default 25 °C.

3. UP Button

Short Press ( < 300 ms )
Increase setpoint by +1 °C.

Long Press ( > 700 ms )
Auto-increment continuously at +1 °C every 150 ms.

Max setpoint: 60 °C

4. DOWN Button

Short Press ( < 300 ms )
Decrease setpoint by –1 °C.

Long Press ( > 700 ms )
Auto-decrement continuously at –1 °C every 150 ms.

Min setpoint: 0 °C

🧊 Temperature Control Logic (ON/OFF)

If temperature > setpoint → Fan ON

If temperature ≤ setpoint → Fan OFF

Optional (not required but recommended)

You may add hysteresis to avoid rapid fan toggling:

Fan ON   if temperature >= setpoint + 1
Fan OFF  if temperature <= setpoint - 1

📦 Recommended Folder Structure
/Core
   /Inc
   /Src
/Drivers
README.md
LICENSE

⚙️ Development Environment

STM32CubeIDE

STM32 HAL drivers

I2C LCD driver (HD44780 + PCF8574)

FreeRTOS (optional, but not required)

📝 Future Improvements

Add hysteresis control

Use PID instead of ON/OFF

Add EEPROM saving for setpoint value

Add buzzer for notifications

Use encoder instead of buttons

📄 License

This project is released under the MIT License.
You are free to modify, share, and use it for learning or development purposes.
