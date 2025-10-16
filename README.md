# 🤖 Wall Avoiding Robot

A simple **autonomous wall-avoiding robot** built using **Arduino** and **ultrasonic sensors** to detect and navigate around obstacles.

---

## 📘 Overview
This project demonstrates how an Arduino microcontroller can be used with an **ultrasonic sensor** and **motor driver** to create a robot that intelligently avoids walls. The system measures distances in real-time and changes direction when an obstacle is detected.

---

## ⚙️ Components Used
- Arduino Uno  
- Ultrasonic Sensor (HC-SR04)  
- L293D Motor Driver Module  
- DC Motors (x2)  
- Robot Chassis  
- Jumper Wires  
- Battery Pack  

---

## 🧠 Working Principle
1. The **ultrasonic sensor** measures the distance to nearby objects.  
2. If the distance is less than a set threshold, the Arduino signals the **motor driver** to turn the robot.  
3. This allows continuous forward movement while avoiding collisions.  

---

## 📂 Project Files
- `wall_avoiding_bot.ino` → Arduino code  
- `Project_Report.pdf` → Contains full description, circuit diagram, and implementation details  

---

## 🚀 How to Run
1. Open the `.ino` file in **Arduino IDE**  
2. Connect your **Arduino Uno** board  
3. Select the correct **board** and **port**  
4. Upload the code  
5. Power on the robot and observe it avoiding walls autonomously!  

---

## 📸 Preview
*(You can add images or videos of your robot here later)*  

---

## 🧾 License
This project is open-source and available under the [MIT License](LICENSE).

---

## 👤 Author
**Aman Dagar**  
GitHub: [@JulmiBhaiPM](https://github.com/JulmiBhaiPM)
