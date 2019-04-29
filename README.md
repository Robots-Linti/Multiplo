# Duinobot AVR Core

Este paquete permite programar los robots MultiploN6 (v1.2) y MultiploN6-MAX
(v2.3) de [RobotGroup](www.robotgroup.com.ar) usando versiones modernas del IDE
Arduino en cualquier sistema operativo.

Microcontroladores soportados

* *ATmega1284* - Duinobot v2.3
* *ATmega32u4* - Duinobot v1.2

##Instalación

La instalación requiere de la version de Arduino IDE 1.6.4 o mayor.
* Abrir el IDE Arduino.
* Abrir el item del menu **Archivo > Ajustes**
* Ingresar la siguiente URL en **URLs adicionales**:
`https://raw.githubusercontent.com/Robots-Linti/Multiplo/master/package_SoporteLihuen_DuinobotAVRBoards_index.json`
* Abrir el menu **Herramientas > Placa > Gestor de tarjetas...**
* Esperar al IDE a que descargue las nuevas definiciones de tarjetas.
* Arrastrar hacia abajo hasta encontrar la entrada **Duinobot AVR Boards** y clickearla.
* **Nota** A partir de la versión 1.6.6 se tiene que cerrar y volver a abrir la ventana del Administrador de tarjetas antes de que la entrada **Duinobot AVR Boards** aparezca.
* Click en **Instalar**
* Cuando la instalación se complete cerrar la ventana del Administrador de tarjetas.

## Multiplo N6 (Duinobot v1.2)

Hasta la versión 1.1.2 es posible usar este paquete sin modificar el
bootloader original de la placa. Desde la versión 1.1.3 es necesario grabar
el bootloader incluído con el paquete (es el mismo de Arduino Leonardo) en la
placa para su funcionamiento, esto debe hacerse una sola vez.

### Actualización del bootloader

Este paso solo es necesario la primera vez que se va a usar la placa
con este paquete.

Para grabar el nuevo bootloader es necesaria otra placa Arduino (se
recomienda un Arduino Uno o un Arduino Nano como programador usando
el sketch "ArduinoISP" como se describe en la página oficial de
Arduino https://www.arduino.cc/en/tutorial/arduinoISP.

1. Programar el Arduino Uno o Nano con el sketch ArduinoISP. De ahora
en más llamaremos a esta placa la "programadora".
2. Conectar la placa programadora a la placa DuinoBot v1.2 como
se indica en la tabla de abajo.
3. Dar alimentación a ambas placas por USB (observar que puerto se asigna
a cada placa al conectarlas a la PC).
4. Seleccionar Herramientas->Placas->Duinobot v1.2 (Caterina).
5. Seleccionar el puerto donde se encuentra conectada la placa programadora.
6. Hacer clic en Herramientas->Quemar bootloader

Conexión entre la placa programadora y la placa Duinobot v1.2:

Programadora | Duinobot v1.2
-------------|--------------
GND          | GND
MISO         | MISO
MOSI         | MOSI
SCK          | SCK
Pin 10       | Reset

### Pinout

Si bien Duinobot v1.2 usa el mismo microcontrolador que Arduino Leonardo
y Arduino Micro la numeración de los pines es muy diferente. Además 3 pines
digitales se encuentran internamente conectados al puente H que controla
los motores M0 y M1.

<img title="Pinout Duinobot v1.2" width="500" src="https://github.com/Robots-Linti/pinouts/raw/master/duinobot_1.2/duinobot_1.2.png">


## Multiplo N6 MAX (Duinobot v2.3)

### Pinout

Este core tiene dos opciones de pines diferentes. Por defecto se encuentra
seleccionada la "Standard", que esta basada en la configuracion de pines del
AVR original. "Bobuino" es una configuración de pines muy similar a la del
Arduino UNO. Esta opcion sirve para usar la placa con shields hechos para esta
última, porque las funciones de los pines quedan en el mismo lugar. (MOSI en
D11, MISO en D12, SCK en D13).

<img src="http://i.imgur.com/9cpfTGl.png" width="500">

<img src="http://i.imgur.com/fHC5LQK.png" width="500">


## Configuraciones avanzadas (Duinobot v2.3)

### Frecuencias de reloj soportadas

* 20 MHz oscilador externo
* 16 MHz oscilador externo (default)
* 8 MHz oscilador externo
* 8 MHz oscilador interno
* 1 MHz oscilador interno

Seleccione su microcontrolador en el menu de Herramientas -> Tarjeta, y luego seleccione la frecuencia del reloj.

### Opcion BOD

"Brown out detection", es una opción que permite al microcontrolador medir el voltaje y apagarse si el mismo esta por debajo del valor seleccionado. Para el 1284p existe una opcion BOD separada. Para cambiarla se debe conectar un programador ISP y grabar el bootloader nuevamente.

