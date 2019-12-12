FROM ubuntu
COPY . /csapp-labs
WORKDIR /csapp-labs
RUN apt-get update
RUN apt-get install -y gcc make vim