# Duinobot AVR Core

Core modificado para el robot MultiploN6 (v1.x) y MultiploN6-MAX (v2.x) de [RobotGroup](www.robotgroup.com.ar), con mapeo de pines personalizados para cada placa.

<br/> <br/>
_Este core requiere por lo menos de la version 1.6 de Arduino, siendo la v1.6.5+ recomendada._
<br/>

<br/> <br/>

##Microcontroladores soportados
* *ATmega1284*
* *ATmega32u4*

##Frecuencias de reloj soportadas
* 20 MHz oscilador externo
* 16 MHz oscilador externo (default)
* 8 MHz oscilador externo
* 8 MHz oscilador interno
* 1 MHz oscilador interno

Seleccione su microcontrolador en el menu de Herramientas -> Tarjeta, y luego seleccione la frecuencia del reloj.

##Opcion BOD
"Brown out detection", es una opcion que permite al microcontrolador sensar el voltaje y apagarse si el mismo esta por debajo del valor seleccionado. Para el 1284p existe una opcion BOD separada. Para cambiarla se debe conectar un programador ISP y grabar el bootloader nuevamente.

##Pinout
Este core tiene dos opciones de pines diferentes. Por defecto se encuentra seleccionada la "Standard", que esta basada en la configuracion de pines del AVR original. La otra se llama "Bobuino", que es basicamente la configuracion de pines del Arduino UNO. Esta opcion sirve para usar la placa con shields o codigo escrito para este ultimo Arduino, porque las funciones de los pines quedan en el mismo lugar. (MOSI en D11, MISO en D12, SCK en D13).</br> </br>
<b>Click para agrandar:</b>
</br> </br>
<img src="http://i.imgur.com/hZGMRwH.png" width="375"> <img src="http://i.imgur.com/9cpfTGl.png" width="430">
</br> </br>
<img src="http://i.imgur.com/PF1HWho.png" width="375"> <img src="http://i.imgur.com/fHC5LQK.png" width="430">

##Cómo instalar
#### Usando Boards Manager
Este método requiere de la version de Arduino IDE 1.6.4 o mayor.
* Abrir el IDE Arduino.
* Abrir el item del menu **Archivo > Ajustes**
* Ingresar la siguiente URL en **URLs adicionales**:
`https://raw.githubusercontent.com/Robots-Linti/Multiplo/master/package_SoporteLihuen_DuinobotAVRBoards_index.json`
* Abrir el menu **Herramientas > Tarjeta > Manager de tarjetas...**
* Esperar al IDE para indexar las nuevas definiciones.
* Arrastrar hacia abajo hasta encontrar la entrada **MultiploN6-Max** y clickearla.
* **Nota** En la version 1.6.6 se tiene que cerrar y volver a abrir la ventana del Administrador de tarjetas antes de que la entrada **MultiploN6-Max** aparezca.
* Click en **Instalar**
* Cuando la instalacion se complete cerrar la ventana del Administrador de tarjetas.
