# Lab4 — PersonSystem

Ієрархія класів `Person → Worker / Electrician` з системою управління персоналом.

## Структура проєкту

```
lab4/
├── include/
│   ├── Person.h
│   ├── Worker.h
│   ├── Electrician.h
│   └── PersonSystem.h
├── src/
│   ├── Person.cpp
│   ├── Worker.cpp
│   ├── Electrician.cpp
│   ├── PersonSystem.cpp
│   └── main.cpp
├── CMakeLists.txt
└── README.md
```

## Збірка та запуск

### VS Code (рекомендовано)

1. Встановіть розширення **CMake Tools** (`ms-vscode.cmake-tools`).
2. Відкрийте папку проєкту: `File → Open Folder`.
3. VS Code автоматично виявить `CMakeLists.txt` та запропонує налаштувати проєкт.
4. Оберіть компілятор (GCC / Clang / MSVC).
5. Натисніть **Build** (Ctrl+Shift+P → `CMake: Build`) або кнопку ▶ внизу.

### Термінал (Linux / macOS)

```bash
cmake -S . -B build
cmake --build build
./build/Lab4
```

### Термінал (Windows)

```cmd
cmake -S . -B build
cmake --build build --config Release
build\Release\Lab4.exe
```

## Вимоги

- C++17 або новіший
- CMake ≥ 3.10
- GCC ≥ 7 / Clang ≥ 5 / MSVC 2017+
