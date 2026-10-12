# Práctica 2: Control de nivel con ESP32

## Descripción
Sistema de control de nivel de líquido con un ESP32. Un sensor ultrasónico HC-SR04 mide la distancia a la superficie del líquido, el programa la convierte en porcentaje de nivel y activa o desactiva dos bombas según los límites alto (HL) y bajo (LL). El nivel y los límites se muestran en una pantalla LCD I2C, y los límites se ajustan con tres botones.

## Objetivo
Controlar automáticamente el nivel de un tanque con límites ajustables, usando un sensor ultrasónico, una pantalla LCD y salidas para dos bombas.

## Integrantes
- Miguel Angel Ramirez Elias
- Francisco Emmanuel Hernandez Camacho
- Diego Gomez Muñis
- Yessenia Medrano Castillo
- Fernanda Jaqueline Ibarra Romero

## Componentes
- ESP32
- Sensor ultrasónico HC-SR04
- Pantalla LCD I2C 16x2 (dirección 0x27)
- 2 relevadores
- 2 bombas de 12 V
- 3 botones
- Librería: `LiquidCrystal_I2C`

## Conexiones
| Componente | Pin del ESP32 |
|------------|---------------|
| HC-SR04 TRIG | GPIO 5 |
| HC-SR04 ECHO | GPIO 18 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |
| Bomba 1 (relay) | GPIO 16 |
| Bomba 2 (relay) | GPIO 17 |
| Botón 1 | GPIO 32 |
| Botón 2 | GPIO 33 |
| Botón 3 | GPIO 34 |

## Funcionamiento
1. **Medición:** cada 500 ms el HC-SR04 mide la distancia. El programa la convierte a porcentaje de nivel: 0 cm equivale a 100 % y 12 cm a 0 %. Si el sensor no recibe eco, la LCD muestra "Fuera de rango".
2. **Control de bombas:**
   - Si el nivel es **mayor o igual a HL**, se enciende la bomba 2 y se apaga la bomba 1.
   - Si el nivel es **menor o igual a LL**, se enciende la bomba 1 y se apaga la bomba 2.
   - Entre LL y HL las bombas conservan su último estado.
3. **Ajuste de límites con botones:**
   - **Botón 3:** alterna entre modo LL (inicial) y modo HL.
   - En modo LL: botón 1 sube el límite y botón 2 lo baja.
   - En modo HL: botón 2 sube el límite y botón 1 lo baja.
   - Cada pulsación cambia el valor en pasos de 10 %, entre 0 y 100 %. Valores iniciales: HL = 80 % y LL = 20 %.
4. **Pantalla LCD:** muestra HL y LL a la izquierda, y el nivel actual ("AL") a la derecha de la primera fila.

## Estructura del repositorio
```
Practica_2
├── img/            # Esquemáticos y fotos del prototipo
├── src/
│   └── main.cpp
├── docs/
│   └── reporte.pdf
├── diagram.json
├── platformio.ini
├── wokwi.toml
└── README.md
```

## Cómo ejecutarlo
1. Clona el repositorio.
2. Ábrelo en VS Code con PlatformIO.
3. Compila y sube el código al ESP32, o simula con Wokwi usando `diagram.json`.
