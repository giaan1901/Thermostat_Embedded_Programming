# 🧊 STM32 Thermostat Controller  
**Author:** Hà Gia An – *2352004*  
**MCU:** STM32F411CEU6  
**Display:** 16×2 LCD (I2C backpack)  
**Input:** 4 physical buttons (POWER, SET, UP, DOWN)

---

## 📌 Overview  
This project implements a simple **thermostat controller** using the STM32F411CEU6 microcontroller.  
It monitors room temperature (0–60 °C), allows the user to set a target temperature, and controls the cooling fan using a classic **ON/OFF control algorithm**.

---

## ✨ Features  
- 🔥 **Temperature Monitoring** every **500 ms**  
- 🎯 **1°C resolution** from 0°C → 60°C  
- 🖥️ **16×2 I2C LCD** user interface  
- 🎛️ **User-configurable temperature threshold**  
- 🌀 **ON/OFF cooling control**  
- 🔘 **Four-button control system**  
- 📡 **Fan status displayed on LCD**

---

## 📟 Hardware Used  
| Component | Description |
|----------|-------------|
| **STM32F411CEU6 (“Blackpill”)** | Main microcontroller |
| **16×2 I2C LCD** | For UI and temperature display |
| **4× Push Buttons** | Power, Set, Up, Down |
| **Cooling Fan (Relay / MOSFET output)** | ON/OFF cooling control |
| **Temperature Sensor** | Example: LM35 / DS18B20 / Analog sensor |

---

## 🎮 Button Functions  
All buttons support **short press** and some support **hold press**.

### Button Press Timing  
| Press Type | Detection Time |
|------------|----------------|
| **Short Press** | < 500 ms |
| **Long Press (Hold)** | > 1 second |

### 📘 Button Behavior  
| Button | Short Press | Long Press |
|--------|-------------|------------|
| **POWER** | Toggle system ON/OFF | — |
| **SET** | Enter/Exit temperature setting mode | — |
| **UP** | Increase temperature by +1°C | Hold to auto-increase |
| **DOWN** | Decrease temperature by −1°C | Hold to auto-decrease |

---

## 🧠 Control Algorithm — ON/OFF Logic  
The thermostat uses classic **bang-bang ON/OFF control**:

```
if (current_temp > set_temp) {
    fan = ON;
} else {
    fan = OFF;
}
```

- No PID  
- No hysteresis (unless you add it)  
- Simple and effective for slow thermal systems

---

## 📺 LCD Display Format  
**Normal Mode:**
```
Temp: 26°C
Fan: OFF
```

**Setting Mode:**
```
Set Temp: 24°C
<UP/DOWN to adjust>
```

---

## 🔧 Firmware Behavior  
- Reads temperature every **500 ms**
- Updates LCD every **500 ms**
- Button debouncing included
- Long-press auto-repeat for UP/DOWN every **200 ms**
- State machine handles:
  - **POWER_STATE**
  - **SET_TEMP_STATE**
  - **RUN_STATE**

---

## 📁 Project Structure  
```
/Core
  /Src
    main.c
    lcd_i2c.c
    buttons.c
    thermostat.c
  /Inc
    lcd_i2c.h
    buttons.h
    thermostat.h

README.md
```

---

## 🚀 How to Use  
1. Power the system using USB or 5V input.  
2. Press **POWER** to start the thermostat.  
3. View current temperature on LCD.  
4. Press **SET** to enter temperature configuration.  
5. Use **UP/DOWN** to adjust temperature.  
6. Fan automatically turns ON/OFF depending on room temperature.

---

## 🛠️ Future Improvements  
- Add **hysteresis** (±1°C) to reduce relay switching  
- Add **PID control** for smoother response  
- Add **EEPROM storage** for the last temperature set point  
- Add **Buzzer** notification

---

## 📜 License  
MIT License — feel free to use and modify.
