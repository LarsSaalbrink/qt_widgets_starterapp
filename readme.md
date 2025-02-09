# About

Convienient way to get started with dockerized Qt development.

# Build

docker build -t qt-dev .

# Allow X11 server connections

xhost +local:docker

# Run with X11 forwarding

```
docker run -it \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v $(pwd):/app \
    qt-dev bash -c "cd /app/build && cmake .. && make && ./hello_qt"
```
