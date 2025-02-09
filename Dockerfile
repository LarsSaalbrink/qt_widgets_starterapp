FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Berlin

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qtbase5-dev \
    qt5-qmake \
    qttools5-dev

WORKDIR /app