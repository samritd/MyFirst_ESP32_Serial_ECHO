# ESP32 Serial Echo Project

โปรเจกต์ Echo ข้อความแบบง่ายๆ สำหรับ ESP32 ที่ช่วยให้ผู้เริ่มต้นเรียนรู้การใช้งาน Serial Communication

## 📋 รายละเอียดโปรเจกต์

**หน้าที่:** รับข้อความจากผู้ใช้ผ่าน Serial Monitor และส่งข้อความเดิมกลับไป  
**เหมาะสำหรับ:** ผู้เริ่มต้นเรียนรู้ ESP32  
**ภาษา:** Arduino C++

## 🛠️ อุปกรณ์ที่ต้องใช้

- ESP32 Development Board
- สายUSB สำหรับเชื่อมต่อกับคอมพิวเตอร์
- Arduino IDE 2.x

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

## 🚀 การใช้งาน

1. อัปโหลดโค้ดลง ESP32
2. เปิด Serial Monitor (Ctrl+Shift+M)
3. ตั้ง Baud Rate เป็น 115200
4. พิมพ์ข้อความและกด Enter
5. ESP32 จะส่งข้อความเดิมกลับมา

## 📁 โครงสร้างไฟล์

```
esp32-serial-echo/
├── README.md
├── serial_echo.ino
└── docs/
    └── setup_guide.md
```

## 💡 สิ่งที่จะได้เรียนรู้

- การใช้งาน Serial Communication
- การรับส่งข้อมูลระหว่าง ESP32 และคอมพิวเตอร์
- การจัดการ String ใน Arduino C++
- การใช้งาน Serial Monitor
- โครงสร้างพื้นฐานของโปรแกรม Arduino (setup/loop)

## 🔧 Code Features

- **Serial.begin(115200):** เริ่มต้น Serial Communication
- **Serial.available():** ตรวจสอบข้อมูลที่เข้ามา
- **Serial.readStringUntil():** อ่านข้อความจนถึงตัวอักษรที่กำหนด
- **String.trim():** ลบช่องว่างข้างหน้าและข้างหลัง

## 🤝 การพัฒนาต่อ

คุณสามารถต่อยอดโปรเจกต์นี้ได้:

- เพิ่มการตอบกลับแบบอัตโนมัติ
- สร้างระบบ Command
- เพิ่มการควบคุม LED หรือเซ็นเซอร์
- เชื่อมต่อกับ WiFi และสร้าง Web Server

## 📞 การสนับสนุน

หากมีปัญหาหรือข้อสงสัย สามารถ:
- เปิด Issue ใน GitHub
- ดูเอกสารใน folder `docs/`

## 📄 License

MIT License - ใช้งานได้อย่างอิสระสำหรับการศึกษาและพัฒนา

## 🏷️ Tags

`esp32` `arduino` `serial-communication` `beginner` `iot` `embedded` `thai`

---

**Happy Coding! 🎉**
