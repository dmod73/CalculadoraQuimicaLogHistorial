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

- **Código de Dean**:
  - Definición de elementos químicos.
  - Función de portada.
  - Conversión de masa.
  - Suma de masas atómicas.
  - Manejo del menú de opciones 2, 3 y 4.
  
- **Código de Lewis**:
  - Funciones de conversión de temperatura.
  - Manejo del historial (`log.txt`).

## 📄 Uso

1. Compilar el proyecto con un compilador de C++.
2. Ejecutar el archivo compilado.
3. Seguir las instrucciones en pantalla para realizar las operaciones.
4. Al salir, revisar el archivo `log.txt` para ver el historial completo.

## 👨‍💻 Creado por

- Dean M Ortiz Diaz
- Lewis Diaz

---

