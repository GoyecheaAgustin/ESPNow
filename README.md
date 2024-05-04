# Sistema de Detección y Aviso de Encendido de Bombas Hidrantes para Riego contra Incendios

Este repositorio contiene el código fuente en C++ para el desarrollo de un sistema de detección y aviso de encendido de bombas hidrantes para riego contra incendios. El proyecto utiliza dos dispositivos ESP32, uno en la placa principal y otro en la placa remota, que se comunican utilizando el protocolo ESPNOW para intercambiar información de forma inalámbrica.

## Diagramas

A continuación, se muestran los diagramas de la placa principal y la placa remota del sistema:

### Diagrama de la Placa Principal

![diagrama de bloques](https://github.com/GoyecheaAgustin/ESPNow/assets/104398552/bfa0c017-5ffa-47a7-a091-440a4452be63)

Este diagrama muestra el diseño de la placa principal, que incluye el ESP32, las entradas y salidas del sistema, y las conexiones para la comunicación inalámbrica.

### Diagrama de la Placa Remota

![diagrama de bloques1](https://github.com/GoyecheaAgustin/ESPNow/assets/104398552/ed7e251d-0658-4b09-b8cc-52c81ca9c1ea)


Este diagrama muestra el diseño de la placa remota, que también utiliza un ESP32. La placa remota se comunica con la placa principal mediante el protocolo ESPNOW para informar sobre el estado de las entradas digitales del sistema.

## Características Principales

- **Detección de señales:** El sistema detecta el estado de al menos cuatro señales discretas (24 Vcc) y dos señales analógicas (0-10 Vcc) relacionadas con eventos de incendio.

- **Notificaciones:** Envía mensajes de texto y mensajes a través de un bot de Telegram para notificar los eventos detectados. Esto permite una respuesta rápida por parte del personal.

- **Control de sirenas e indicadores:** Incluye dos salidas tipo relé para controlar sirenas y/o indicadores luminosos.

- **Interfaz de usuario:** Ofrece una interfaz de usuario para configurar el sistema.

- **Construcción modular:** Utiliza componentes modulares que se pueden encontrar fácilmente en el mercado local para facilitar la construcción y mantenimiento del sistema.

- **Comunicación ESPNOW:** La placa principal y la placa remota se comunican mediante el protocolo ESPNOW del ESP32, permitiendo un intercambio rápido y eficiente de datos.

