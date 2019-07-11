# Build OpenCV with Inference Engine
Подробная иснтсуркция [здесь](https://github.com/opencv/opencv/wiki/Intel's-Deep-Learning-Inference-Engine-backend).

В консоли Developer Command Prompt for VS 2017 (идет вместе с VS2017) проделать сделующие команды:
```
cd <путь до директории куда вы хотите собрать OpenCV>
<путь до директории с установленным OpenVino>\bin\setupvars.bat
cmake -DWITH_INF_ENGINE=ON -DCMAKE_BUILD_TYPE=RELEASE -DENABLE_CXX11=ON <путь до нужных исходников OpenCV>
cmake --build .  // сборка
```
