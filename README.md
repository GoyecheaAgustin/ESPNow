# Sistema de Detección y Aviso de Encendido de Bombas Hidrantes para Riego contra Incendios

Este repositorio contiene el código fuente en C++ para el desarrollo de un sistema de detección y aviso de encendido de bombas hidrantes para riego contra incendios. El proyecto utiliza un ESP32 para implementar el sistema, aprovechando su capacidad de conectividad WiFi para enviar notificaciones y comandos a través de mensajes de texto y un bot de Telegram.

## Características Principales

- **Detección de señales:** El sistema detecta el estado de al menos cuatro señales discretas (24 Vcc) y dos señales analógicas (0-10 Vcc) relacionadas con eventos de incendio.

- **Notificaciones:** Envía mensajes de texto y mensajes a través de un bot de Telegram para notificar los eventos detectados. Esto permite una respuesta rápida por parte del personal.

- **Control de sirenas e indicadores:** Incluye dos salidas tipo relé para controlar sirenas y/o indicadores luminosos.

- **Interfaz de usuario:** Ofrece una interfaz de usuario para configurar el sistema.

- **Construcción modular:** Utiliza componentes modulares que se pueden encontrar fácilmente en el mercado local para facilitar la construcción y mantenimiento del sistema.

## Estructura del Repositorio

- **/src:** Contiene el código fuente en C++ para el ESP32, incluyendo funciones para la detección, notificación y control de eventos. También incluye el código para interactuar con el bot de Telegram.

- **/docs:** Documentación del proyecto, incluyendo manuales de usuario y diagramas de diseño.

- **/hardware:** Archivos relacionados con los componentes de hardware y la placa ESP32.

- **/config:** Archivos de configuración para ajustar parámetros del sistema, incluyendo la configuración del bot de Telegram.

- **/tests:** Pruebas unitarias y casos de prueba para verificar el correcto funcionamiento del sistema.

## Requisitos

- **ESP32:** El proyecto utiliza un ESP32 como plataforma de hardware.

- **Compilador C++:** Asegúrate de tener un compilador de C++ compatible para compilar el código fuente.

- **Librerías y dependencias:** Consulta la documentación en la carpeta `docs` para obtener detalles sobre las librerías y dependencias necesarias, incluidas aquellas para la interacción con Telegram.

## Cómo Compilar y Ejecutar

1. **Compila el código:** Navega a la carpeta `src` y compila el código utilizando el compilador C++ para ESP32.

2. **Configura el sistema:** Personaliza los archivos de configuración en la carpeta `config`, incluyendo los parámetros de conexión WiFi y la configuración del bot de Telegram.

3. **Sube el código:** Sube el código compilado al ESP32.

4. **Ejecuta el sistema:** El ESP32 comenzará a ejecutar el sistema una vez que se haya subido el código.

## Contribuciones

Si deseas contribuir a este proyecto:

1. Haz un fork del repositorio.
2. Crea una rama con tus cambios (`git checkout -b mi-rama`).
3. Haz commit de tus cambios (`git commit -am 'Descripción de tus cambios'`).
4. Envía tus cambios a tu fork (`git push origin mi-rama`).
5. Abre un pull request para revisar tus cambios.

## Licencia

Este proyecto está bajo la licencia MIT. Consulta el archivo [LICENSE](LICENSE) para obtener más detalles.

## Contacto

Si tienes alguna pregunta o sugerencia sobre el proyecto, no dudes en contactarnos. Los detalles de contacto se encuentran en la documentación.

