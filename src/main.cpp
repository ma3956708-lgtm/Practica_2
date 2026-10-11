// #include <Arduino.h>
// #include <Wire.h>
// #include <LiquidCrystal_I2C.h>

// // -----------------------------
// // Pines
// // -----------------------------
// #define TRIG_PIN 5
// #define ECHO_PIN 18

// #define SDA_PIN 21
// #define SCL_PIN 22


// // -----------------------------
// // LCD
// // -----------------------------
// #define LCD_ADDRESS 0x27
// #define LCD_COLUMNS 16
// #define LCD_ROWS 2

// #define bomba_1 16 //tx
// #define bomba_2 17 //rx
// #define boton_1 32
// #define boton_2 33
// #define boton_3 34
// int HL = 80; 
// int LL = 20;
// int funcion = 1;
// #define PRESSED(x) (digitalRead(x)==0) 
// //#define SUBE_HL digitalRead (HL + 10)
// //#define BAJA_HL digitalRead (HL - 10)
// #define on_bomba_1 digitalWrite (bomba_1, HIGH)
// #define off_bomba_1 digitalWrite (bomba_1, LOW)
// #define on_bomba_2 digitalWrite (bomba_2, HIGH)
// #define off_bomba_2 digitalWrite (bomba_2, LOW)

// LiquidCrystal_I2C lcd(
//     LCD_ADDRESS,
//     LCD_COLUMNS,
//     LCD_ROWS
// );

// void setup()
// {
//     Serial.begin(115200);

//     pinMode(TRIG_PIN, OUTPUT);
//     pinMode(ECHO_PIN, INPUT);

//     Wire.begin(SDA_PIN, SCL_PIN);

//     lcd.init();
//     lcd.backlight();

//     lcd.setCursor(0, 0);
//     lcd.print("Sensor HC-SR04");

//     lcd.setCursor(0, 1);
//     lcd.print("Iniciando...");

//     delay(2000);

//     lcd.clear();

//     pinMode(bomba_1, OUTPUT);
//     pinMode(bomba_2, OUTPUT);
//     pinMode(boton_1, INPUT_PULLUP);
//     pinMode(boton_2, INPUT_PULLUP);

// }

// void loop ()
// {
//     // Generar pulso ultrasónico
//     digitalWrite(TRIG_PIN, LOW);
//     delayMicroseconds(2);

//     digitalWrite(TRIG_PIN, HIGH);
//     delayMicroseconds(10);

//     digitalWrite(TRIG_PIN, LOW);

//     // Medir tiempo del eco
//     long tiempo = pulseIn(
//         ECHO_PIN,
//         HIGH,
//         30000
//     );

//     float distancia = tiempo * 0.0343 / 2.0;
//     float r = .04;
//     float pi = 3.1416;
//     float h = .14;
//     float v = (pi * (pow(r, 2))) * (h - (distancia/100));
//     float litros = v * 1000;
//     float x1 = 0;
//     float y1 = 100;
//     float x2 = 12;
//     float y2 = 0;
//     int porcentaje = ((((y2 - y1) / (x2 - x1)) * (distancia - x1)) + y1);

//     if (porcentaje >= HL) {
//         on_bomba_2;
//         off_bomba_1;

        
//     }
//     if (porcentaje <= LL) {
//         off_bomba_2;
//         on_bomba_1;
                
//     }






//     // Calcular distancia
//     if (tiempo == 0)
//     {
//         lcd.clear();

//         lcd.setCursor(0, 0);
//         lcd.print("Distancia:");

//         lcd.setCursor(0, 1);
//         lcd.print("Fuera de rango");

//         Serial.println("Fuera de rango");
//     }
//     else
//     {
//         //float distancia = tiempo * 0.0343 / 2.0;

//         // LCD
//         lcd.clear();

//         lcd.setCursor(10, 0);
//         lcd.print("AL:");

//         lcd.setCursor(12, 0);
//         lcd.print(porcentaje);
//         lcd.print(" % ");

//         // Monitor serial
//         //Serial.print("AL: ");
//         //Serial.print(porcentaje, 1);
//         //Serial.println(" %");

        
//     }

//     //int funcion = 1;   // empieza en modo 1

// if (PRESSED(boton_3)) {
//     funcion = !funcion;  // alterna entre 0 y 1
// }

// if (funcion == 1) {
//     // Control de LL
//     if (PRESSED(boton_1)) LL = min(HL + 10, 100);
//     if (PRESSED(boton_2)) LL = max(LL - 10, 0);
// }
// else {
//     // Control de HL
//     if (PRESSED(boton_2)) HL = min(HL + 10, 100);
//     if (PRESSED(boton_1)) HL = max(HL - 10, 0);
// }

//     //if (PRESSED(boton_3)) {
//         //funcion == 1;
//         //if (funcion == 1) {
//            // PRESSED(boton_1);
//            // LL = min(HL + 10, 100);
//             //if (funcion = 1) {
//               //  PRESSED(boton_2);
//                 //LL = max(LL - 10, 0);
//             //}
//         //}
//         //else
//         //{
//           //  funcion == 0;
        
//         //}

//         //if (funcion == 0) {

//         //if (PRESSED(boton_2)){
//           //   HL = min(HL + 10, 100);
        

//         //}
//         //if (PRESSED(boton_1)) {
//         //HL = max(HL - 10, 0);
//         //}
//         //}
//     //}
    
//     //if (PRESSED(boton_3 )) {

//         //if (PRESSED(boton_2)){
//             //LL = min(LL + 10, 100);
      
//         //}
//     //if (PRESSED(boton_3)){
//         //if (PRESSED(boton_1)){
//             ///LL = max(LL - 10, 0);
//         //}
//     //}    


//     //}
//         lcd.setCursor(0, 0);
//         lcd.print("HL:");

//         lcd.setCursor(4, 0);
//         lcd.print(HL);
//         lcd.print(" % ");


//         lcd.setCursor(0, 1);
//         lcd.print("LL:");

//         lcd.setCursor(4, 1);
//         lcd.print(LL);
//         lcd.print(" % ");


        
    
    





//     delay(500);

// }

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ---------- Pines ----------
#define TRIG_PIN 5
#define ECHO_PIN 18      // ¡usar divisor de voltaje 5V -> 3.3V!
#define SDA_PIN 21
#define SCL_PIN 22

#define bomba_1 16
#define bomba_2 17
#define boton_1 32
#define boton_2 33
#define boton_3 34       // GPIO34 NO tiene pull-up interno: necesita resistencia externa de 10k a 3.3V

// Si tu módulo relay es activo en BAJO (lo más común), pon true
#define RELAY_ACTIVO_BAJO true

#if RELAY_ACTIVO_BAJO
  #define RELE_ON  LOW
  #define RELE_OFF HIGH
#else
  #define RELE_ON  HIGH
  #define RELE_OFF LOW
#endif

#define on_bomba_1  digitalWrite(bomba_1, RELE_ON)
#define off_bomba_1 digitalWrite(bomba_1, RELE_OFF)
#define on_bomba_2  digitalWrite(bomba_2, RELE_ON)
#define off_bomba_2 digitalWrite(bomba_2, RELE_OFF)

#define PRESSED(x) (digitalRead(x) == 0)

LiquidCrystal_I2C lcd(0x27, 16, 2);

int HL = 80;
int LL = 20;
bool modoLL = true;               // true: botones cambian LL, false: cambian HL

// Para detectar solo el "flanco" de cada botón (una pulsación = un cambio)
bool prev1 = false, prev2 = false, prev3 = false;

void setup()
{
    // Primero los relays en estado apagado, antes de cualquier otra cosa
    pinMode(bomba_1, OUTPUT);
    pinMode(bomba_2, OUTPUT);
    off_bomba_1;
    off_bomba_2;

    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(boton_1, INPUT_PULLUP);
    pinMode(boton_2, INPUT_PULLUP);
    pinMode(boton_3, INPUT);      // con resistencia pull-up externa

    Wire.begin(SDA_PIN, SCL_PIN);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Sensor HC-SR04");
    lcd.setCursor(0, 1);
    lcd.print("Iniciando...");
    delay(2000);
    lcd.clear();
}

void loop()
{
    // ---------- Medición ----------
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long tiempo = pulseIn(ECHO_PIN, HIGH, 30000);
    bool lecturaValida = (tiempo != 0);

    int porcentaje = 0;
    if (lecturaValida) {
        float distancia = tiempo * 0.0343 / 2.0;               // cm
        porcentaje = (int)(100.0 - (distancia * 100.0 / 12.0)); // 0 cm = 100 %, 12 cm = 0 %
        porcentaje = constrain(porcentaje, 0, 100);

        // Solo se controlan las bombas con lecturas válidas
        if (porcentaje >= HL) {
            on_bomba_2;
            off_bomba_1;
        }
        if (porcentaje <= LL) {
            off_bomba_2;
            on_bomba_1;
        }
    }

    // ---------- Botones (detección de flanco) ----------
    bool p1 = PRESSED(boton_1);
    bool p2 = PRESSED(boton_2);
    bool p3 = PRESSED(boton_3);

    if (p3 && !prev3) modoLL = !modoLL;

    if (modoLL) {
        if (p1 && !prev1) LL = min(LL + 10, HL - 10);   // LL siempre menor que HL
        if (p2 && !prev2) LL = max(LL - 10, 0);
    } else {
        if (p2 && !prev2) HL = min(HL + 10, 100);
        if (p1 && !prev1) HL = max(HL - 10, LL + 10);   // HL siempre mayor que LL
    }
    prev1 = p1; prev2 = p2; prev3 = p3;

    // ---------- LCD (sin clear, con espacios para borrar restos) ----------
    char l0[17], l1[17];
    if (lecturaValida) {
        snprintf(l0, sizeof(l0), "HL:%3d%% AL:%3d%%", HL, porcentaje);
    } else {
        snprintf(l0, sizeof(l0), "HL:%3d%% AL:---", HL);
    }
    snprintf(l1, sizeof(l1), "LL:%3d%% %s", LL, modoLL ? "<LL>" : "<HL>");

    lcd.setCursor(0, 0);
    lcd.print(l0);
    lcd.setCursor(0, 1);
    lcd.print(l1);

    delay(100);
}
