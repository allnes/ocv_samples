# Build OpenCV with Inference Engine

В консоли Developer Command Prompt for VS 2017 (идет вместе с VS2017) проделать сделующие команды:
```
cd <путь до директории куда вы хотите собрать OpenCV>
<путь до директории с установленным OpenVino>\bin\setupvars.bat
cmake -DWITH_INF_ENGINE=ON -DCMAKE_BUILD_TYPE=RELEASE <путь до нужных исходников OpenCV>
cmake -DCMAKE_CXX_FLAGS=-m32 .
cmake --build .  // сборка
```
