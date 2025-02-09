#!/bin/bash

xhost +local:docker

docker build -t qt-dev .

mkdir build

docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v $(pwd):/app \
    qt-dev bash -c "cd /app/build && cmake .. && make && ./hello_qt"
