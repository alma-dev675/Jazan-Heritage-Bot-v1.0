#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// إعداد شاشة الـ LCD (تأكدي من توصيلها كما في المخطط)
// 16x2 تعني 16 عمود و صفين
LiquidCrystal_I2C lcd(0x27, 16, 2);

// تعريف دبابيس (Pins) الأزرار والسماعة بناءً على تصميمك في IMG_2787.jpeg
const int btnMango = 2;   // زر المانجو
const int btnCoffee = 3;  // زر البن
const int btnJasmine = 4; // زر الفل
const int speaker = 5;    // السماعة (Buzzer)

void setup() {
  // تشغيل الشاشة
  lcd.init();
  lcd.backlight();
  
  // إعداد الأزرار كمداخل والسماعة كمخرج
  pinMode(btnMango, INPUT_PULLUP);
  pinMode(btnCoffee, INPUT_PULLUP);
  pinMode(btnJasmine, INPUT_PULLUP);
  pinMode(speaker, OUTPUT);

  // نغمة ترحيبية عند تشغيل "بوت سفير جازان"
  lcd.setCursor(0, 0);
  lcd.print("Welcome to Jazan");
  lcd.setCursor(0, 1);
  lcd.print("Digital Envoy");
  
  tone(speaker, 1000, 500); // صوت ترحيبي
  delay(3000);
  lcd.clear();
  lcd.print("Select Heritage:");
}

void loop() {
  // تفاعل زر المانجو
  if (digitalRead(btnMango) == LOW) {
    displayMessage("Mango Jazan", "The King of Fruits");
    playInteractionTone(600);
  }

  // تفاعل زر البن الخولاني
  if (digitalRead(btnCoffee) == LOW) {
    displayMessage("Khoulani Coffee", "Our Heritage");
    playInteractionTone(800);
  }

  // تفاعل زر الفل الجيزاني
  if (digitalRead(btnJasmine) == LOW) {
    displayMessage("Jazan Jasmine", "The Iconic Scent");
    playInteractionTone(1200);
  }
}

// وظيفة لعرض النص على الشاشة بشكل مرتب
void displayMessage(String title, String info) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(title);
  lcd.setCursor(0, 1);
  lcd.print(info);
  delay(2000); // بقاء النص لمدة ثانيتين
}

// وظيفة لإصدار صوت عند الضغط على الأزرار
void playInteractionTone(int frequency) {
  tone(speaker, frequency, 200);
}
