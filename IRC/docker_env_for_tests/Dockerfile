FROM debian:buster AS builder
RUN apt-get update && apt-get install -y make clang vim
RUN echo 'echo -n "$ROLE: " && hostname -I' >> ~/.bashrc
RUN echo "cd /srcs" >> ~/.bashrc

FROM builder as server_target
RUN echo "alias server='make -C /srcs run'" >> ~/.bashrc

FROM builder as client_target
RUN apt-get install -y netcat
RUN echo "alias client='nc server 3490'" >> ~/.bashrc

