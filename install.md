# Build OpenCV with Inference Engine

В консоли Developer Command Prompt for VS 2017 (идет вместе с VS2017)
```
cd <path_to_your_build_directory>
<path_to_openvino>\bin\setupvars.bat
cmake -DWITH_INF_ENGINE=ON -DCMAKE_BUILD_TYPE=Release <path_to_OpenCV>
cmake --build .
```
