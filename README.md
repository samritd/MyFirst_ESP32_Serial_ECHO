# MyFirst ESP32 Serial ECHO + Firebase HTTP GET

โปรเจกต์ ESP32 สำหรับผู้เริ่มต้น ประกอบด้วย 2 โปรเจกต์หลัก

## 📋 โปรเจกต์ที่ 1: Serial Echo with LED Blink
**หน้าที่:** รับข้อความจากผู้ใช้ผ่าน Serial Monitor และส่งข้อความเดิมกลับไป พร้อมไฟกระพริบ  
**ไฟล์:** `serial_echo.ino`

### Features:
- รับ-ส่งข้อความผ่าน Serial Monitor
- ไฟ LED กระพริบเมื่อรับข้อความ
- คอมเมนต์ภาษาไทยละเอียด

## 📋 โปรเจกต์ที่ 2: Firebase HTTP GET
**หน้าที่:** เชื่อมต่อ WiFi และดึงข้อมูลจาก Firebase Realtime Database  
**ไฟล์:** `firebase_http_get.ino`

### Features:
- เชื่อมต่อ WiFi อัตโนมัติ
- ส่ง HTTP GET request ทุก 2 วินาที
- แสดงข้อมูลจาก Firebase บน Serial Monitor
- การจัดการ Error และ Reconnection

## 🛠️ อุปกรณ์ที่ต้องใช้

- ESP32 Development Board
- สายUSB สำหรับเชื่อมต่อกับคอมพิวเตอร์
- Arduino IDE 2.x
- WiFi Network (สำหรับโปรเจกต์ Firebase)

## ⚙️ การติดตั้งและใช้งาน

### 1. เตรียม Arduino IDE
```bash
# สำหรับ Ubuntu 24.04
# ติดตั้ง ESP32 board package ใน Arduino IDE
```

### 2. เพิ่ม ESP32 Board URL
ใน Arduino IDE:
- ไปที่ **File → Preferences**
- เพิ่ม URL: `https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json`

### 3. ติดตั้ง ESP32 Board
- **Tools → Board → Boards Manager**
- ค้นหา "esp32" และติดตั้ง

### 4. เลือก Board และ Port
- **Board:** ESP32 Dev Module
- **Port:** /dev/ttyUSB0 (หรือ port ที่ ESP32 เชื่อมต่ออยู่)

## 🚀 การใช้งานโปรเจกต์

### โปรเจกต์ที่ 1: Serial Echo
1. อัปโหลด `serial_echo.ino` ลง ESP32
2. เปิด Serial Monitor (Ctrl+Shift+M)
3. ตั้ง Baud Rate เป็น 115200
4. พิมพ์ข้อความและกด Enter
5. สังเกตไฟ LED กระพริบและข้อความที่ส่งกลับ

### โปรเจกต์ที่ 2: Firebase HTTP GET
1. **ตั้งค่า Firebase:**
   - สร้าง Firebase Project
   - เปิดใช้งาน Realtime Database
   - สร้างข้อมูลทดสอบ เช่น `test: "123"`
   - คัดลอก Database URL

2. **แก้ไขโค้ด:**
   ```cpp
   const char* ssid = "ชื่อ_WiFi_ของคุณ";
   const char* password = "รหัสผ่าน_WiFi";
   String firebaseUrl = "https://your-project.firebaseio.com/test.json";
   ```

3. **อัปโหลดและทดสอบ:**
   - อัปโหลด `firebase_http_get.ino`
   - เปิด Serial Monitor
   - สังเกตการเชื่อมต่อ WiFi และการดึงข้อมูล

## 📁 โครงสร้างไฟล์

```
MyFirst_ESP32_Serial_ECHO/
├── README.md
├── serial_echo.ino           # โปรเจกต์ที่ 1: Serial Echo + LED
├── firebase_http_get.ino     # โปรเจกต์ที่ 2: Firebase HTTP GET
└── docs/
    ├── setup_guide.md
    └── firebase_setup.md
```

## 💡 สิ่งที่จะได้เรียนรู้

### จากโปรเจกต์ที่ 1:
- การใช้งาน Serial Communication
- การควบคุม GPIO (LED)
- การจัดการ String ใน Arduino C++
- โครงสร้างพื้นฐานของโปรแกรม Arduino

### จากโปรเจกต์ที่ 2:
- การเชื่อมต่อ WiFi บน ESP32
- การใช้งาน HTTP Client
- การเชื่อมต่อกับ Firebase
- การจัดการ JSON Response
- การ Debug และ Error Handling

## 🔧 Code Features

### Serial Echo:
- **Serial.begin(115200):** เริ่มต้น Serial Communication
- **pinMode():** ตั้งค่า GPIO mode
- **digitalWrite():** ควบคุมสถานะ LED
- **Serial.readStringUntil():** อ่านข้อความ

### Firebase HTTP GET:
- **WiFi.begin():** เชื่อมต่อ WiFi
- **HTTPClient:** สร้าง HTTP request
- **http.GET():** ส่ง GET request
- **http.getString():** รับ response data

## 🤝 การพัฒนาต่อ

คุณสามารถต่อยอดโปรเจกต์นี้ได้:

- **Serial Echo:** เพิ่มคำสั่งควบคุม, เชื่อมต่อเซ็นเซอร์
- **Firebase:** ส่งข้อมูลขึ้น Firebase (POST), สร้าง IoT Dashboard
- **รวมโปรเจกต์:** รับคำสั่งจาก Serial แล้วส่งข้อมูลขึ้น Firebase

## 🛠️ การแก้ไขปัญหา

### Serial Echo:
- ตรวจสอบ Baud Rate (115200)
- ตรวจสอบการเชื่อมต่อ USB
- ตรวจสอบ GPIO pin (LED ในตัวใช้ pin 2)

### Firebase HTTP GET:
- ตรวจสอบชื่อและรหัสผ่าน WiFi
- ตรวจสอบ Firebase URL และ Database Rules
- ตรวจสอบการเชื่อมต่ออินเทอร์เน็ต

## 📞 การสนับสนุน

หากมีปัญหาหรือข้อสงสัย สามารถ:
- เปิด Issue ใน GitHub
- ดูเอกสารใน folder `docs/`

## 📄 License

MIT License - ใช้งานได้อย่างอิสระสำหรับการศึกษาและพัฒนา

## 🏷️ Tags

`esp32` `arduino` `serial-communication` `firebase` `http-client` `wifi` `iot` `beginner` `thai`

---

**Happy Coding! 🎉**

### 🌟 ความก้าวหน้า
- ✅ โปรเจกต์ที่ 1: Serial Communication + LED Control
- ✅ โปรเจกต์ที่ 2: WiFi + Firebase Integration  
- 🔄 ต่อไป: รวมโปรเจกต์และสร้าง IoT System
