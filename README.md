# Calculadora Química en C++

Proyecto académico en C++ que permite realizar:

- Conversión de temperatura entre distintas unidades.
- Conversión de masa de kilogramos (kg) a miligramos (mg).
- Suma de masas atómicas de elementos de la tabla periódica.
- Registro automático del historial de operaciones realizadas.

## 🛠️ Funcionalidades principales

- **Conversión de Temperatura**: Celsius, Kelvin y Fahrenheit.
- **Conversión de Masa**: Kilogramos (kg) a Miligramos (mg).
- **Suma de Masas Atómicas**: Selección de elementos de distintas categorías químicas.
- **Historial Guardado**: Las operaciones se almacenan en un archivo `log.txt` con la hora en que se realizaron.

## 🚀 Tecnologías utilizadas

- **Lenguaje**: C++
- **Librerías estándar**:
  - `<iostream>` – Entrada y salida de datos.
  - `<fstream>` – Manejo de archivos de texto.
  - `<string>` – Manejo de cadenas de texto.
  - `<vector>` – Almacenamiento dinámico de historial.
  - `<ctime>` – Captura de hora actual.

## 📋 Estructura general

- `mostrarPortada()`: Muestra una portada animada al iniciar el programa.
- `convertirTemperatura()`: Realiza conversiones de grados.
- `convertirMasa()`: Convierte masas de kg a mg.
- `mostrarElementos()`: Muestra los elementos de una categoría química.
- `guardarLog()`: Guarda cada operación en el historial (`log.txt`).
- `HistorialDeLog()`: Muestra todas las operaciones realizadas al salir.

## 📂 Organización del Código

- **Código de Dean M Ortiz Diaz**:
  - Función de portada.
  - Definición de elementos químicos (nombres, símbolos, masas).
  - Función `mostrarElementos`.
  - Suma de masas atómicas (Case 3).
  - Salida y despliegue de historial (Case 4).

- **Código de Lewis Diaz**:
  - Conversión de temperatura (Case 1).
  - Conversión de masa (Case 2).
  - Manejo del historial de operaciones (`log.txt`).
  - Captura de hora (`ctime`).

## 📄 Uso

1. Compilar el proyecto con un compilador de C++.
2. Ejecutar el archivo compilado.
3. Seguir las instrucciones en pantalla para realizar las operaciones.
4. Al salir, revisar el historial mostrado en consola.

## 🏷️ Versión

- **Versión 1.0**

---

# 🧾 Licencia

MIT License

Copyright (c) 2025  
Dean M Ortiz Diaz, Lewis Diaz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

---
