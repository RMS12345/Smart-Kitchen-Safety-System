# Smart Kitchen Safety and Automation System (ESP32)

An ESP32-Based Multi-Hazard Detection, Automatic Response, and Smart Ventilation System. 
This project was developed as part of our Electronics Lab coursework by **Group 6**.

## 👥 Group Members & Responsibilities
1. **Nafisa Rumman (Member 1):** Gas Detection & Automatic Shut-off
2. **Rowena Mahzabin Sarah (Member 2):** Heat, Humidity & Cooking Smoke Monitoring
3. **Shuvo Naha (Member 3):** Fire Detection & Emergency SMS
4. **Yasin Arafat Piyas (Member 4):** Child Safety / Kitchen Entry Detection
5. **Amira Mahbub (Member 5):** Smart Ventilation, Smoke Direction Control & System Integration

---

## 🛠️ My Contribution (Member 2 Module)
As **Member 2**, my core responsibilities included:
- Integrating the **DHT11** (Temperature & Humidity) and **MQ-2** (Smoke) sensors with the **ESP32** microcontroller.
- Implementing smart thresholds for normal cooking vs. hazard conditions (e.g., pressure cooker optimized logic to avoid false alarms).
- Programming the automated response logic: activating the exhaust fan (**Relay Module**) and **Buzzer** when heat or smoke exceeds safe limits.

### 📄 Arduino Code Overview (`code/member2_kitchen_code.ino`)
The code reads real-time temperature and sound/smoke sensor values, processes the threshold logic, and controls the actuator outputs accordingly:
- **Normal Cooking Range (35°C - 48°C):** Activates ventilation fan without triggering the annoying buzzer.
- **Hazard Level (>48°C or High Smoke/Sound):** Triggers critical alarms (Buzzer & Fan ON).

---
*Project documentation and full reports are attached in the `docs/` folder.*
