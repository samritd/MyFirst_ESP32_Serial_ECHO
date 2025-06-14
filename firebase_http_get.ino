/*
  โปรเจกต์: ESP32 HTTP GET from Firebase
  หน้าที่: 
  1. เชื่อมต่อ Wi-Fi
  2. ส่ง HTTP GET request ไปยัง Firebase Realtime Database ทุกๆ 2 วินาที
  3. นำข้อมูลที่ได้รับ (ซึ่งคือ "123") มาแสดงผลบน Serial Monitor
*/

// นำเข้าไลบรารีที่จำเป็น
#include <WiFi.h>       // ไลบรารีหลักสำหรับจัดการการเชื่อมต่อ Wi-Fi บน ESP32
#include <HTTPClient.h> // ไลบรารีสำหรับทำให้ ESP32 เป็น HTTP Client เพื่อส่ง/รับข้อมูล

// --- กรุณาแก้ไขข้อมูลในส่วนนี้ ---
const char* ssid = "YOUR_WIFI_SSID";      // parameter: ใส่ชื่อ Wi-Fi (SSID) ของคุณในเครื่องหมายคำพูดนี้
const char* password = "YOUR_WIFI_PASSWORD";  // parameter: ใส่รหัสผ่าน Wi-Fi ของคุณในเครื่องหมายคำพูดนี้
// ---------------------------------

// URL ของ Firebase ที่เราต้องการดึงข้อมูล
String firebaseUrl = "ใส่ลิ่งตัวเอง/test.json?auth=9w1FYYpcfTRHGAm9grMcFTCisi1ZdK5B4E4Mzl9M";

// ฟังก์ชัน setup() จะทำงานเพียงครั้งเดียวเมื่อบอร์ดเริ่มทำงาน
void setup() {
  // เริ่มต้นการสื่อสารผ่าน Serial ที่ความเร็ว 115200 bps
  Serial.begin(115200);
  
  // เริ่มต้นการเชื่อมต่อ Wi-Fi
  WiFi.begin(ssid, password); // parameter: ssid และ password คือชื่อและรหัสผ่านที่เรากำหนดไว้ด้านบน
  Serial.print("กำลังเชื่อมต่อ Wi-Fi ");

  // วนรอจนกว่าจะเชื่อมต่อ Wi-Fi ได้สำเร็จ
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); // หน่วงเวลา 0.5 วินาที
    Serial.print("."); // พิมพ์เครื่องหมาย . เพื่อแสดงว่ากำลังพยายามเชื่อมต่อ
  }

  // เมื่อเชื่อมต่อสำเร็จแล้ว ให้แสดงข้อความและ IP Address ที่ได้รับ
  Serial.println(""); // ขึ้นบรรทัดใหม่
  Serial.println("เชื่อมต่อ Wi-Fi สำเร็จแล้ว!");
  Serial.print("IP Address ที่ได้รับ: ");
  Serial.println(WiFi.localIP()); // พิมพ์ IP ของ ESP32 ออกมา
}

// ฟังก์ชัน loop() จะทำงานวนซ้ำไปเรื่อยๆ
void loop() {
  
  // ตรวจสอบสถานะการเชื่อมต่อ Wi-Fi ก่อนทุกครั้ง
  if (WiFi.status() == WL_CONNECTED) {
    
    HTTPClient http; // สร้างอ็อบเจกต์ (object) ของ HTTPClient ขึ้นมาใช้งาน

    // เริ่มต้นการเชื่อมต่อ HTTP ไปยัง URL ที่กำหนด
    // firebaseUrl คือ parameter ที่เป็น URL ปลายทางของเรา
    http.begin(firebaseUrl); 
    
    Serial.println("กำลังส่ง GET request...");
    // ส่งคำขอแบบ GET และรับรหัสสถานะ (HTTP Status Code) กลับมา
    // เช่น 200 = สำเร็จ, 404 = ไม่พบหน้า, -1 = เชื่อมต่อล้มเหลว
    int httpCode = http.GET(); 

    // ตรวจสอบว่าได้รับ response กลับมาจาก Server หรือไม่ (httpCode > 0)
    if (httpCode > 0) {
      // พิมพ์รหัสสถานะที่ได้รับ
      Serial.printf("ได้รับ HTTP response code: %d\n", httpCode);

      // ถ้า response code คือ 200 (HTTP_CODE_OK) แสดงว่าดึงข้อมูลสำเร็จ
      if (httpCode == HTTP_CODE_OK) {
        // อ่านข้อมูลที่ Server ส่งกลับมา (เรียกว่า payload) แล้วเก็บในตัวแปรชนิด String
        String payload = http.getString(); 
        
        Serial.print("ข้อมูลที่ได้รับจาก Firebase: ");
        Serial.println(payload); // พิมพ์ข้อมูลที่ได้ออกมาทาง Serial Monitor
      }
      
    } else {
      // หากการเชื่อมต่อล้มเหลว (httpCode < 0) ให้แสดงข้อความผิดพลาด
      // http.errorToString(httpCode).c_str() คือ parameter ที่แปลงรหัส error เป็นข้อความให้อ่านเข้าใจง่าย
      Serial.printf("GET request ล้มเหลว, error: %s\n", http.errorToString(httpCode).c_str());
    }

    // ปิดการเชื่อมต่อทุกครั้งเมื่อเสร็จสิ้น เพื่อคืนทรัพยากร (memory) ให้กับ ESP32
    http.end(); 

  } else {
    Serial.println("การเชื่อมต่อ Wi-Fi หลุด!");
  }
  
  // หน่วงเวลา 2 วินาที ก่อนที่จะเริ่มทำงานใน loop รอบถัดไป
  delay(2000); // parameter: 2000 คือจำนวนมิลลิวินาที (milliseconds) ซึ่งเท่ากับ 2 วินาที
}
