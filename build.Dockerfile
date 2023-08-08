FROM ubuntu:23.04

## Prereqs for later steps
RUN apt-get update -y && apt-get install -y bash wget

## Setup pacman
# RUN	wget https://apt.devkitpro.org/install-devkitpro-pacman && \
# 	chmod +x ./install-devkitpro-pacman
# RUN	./install-devkitpro-pacman
# ensure apt is set up to work with https sources
RUN apt-get install apt-transport-https

# Store devkitPro gpg key locally if we don't have it already
RUN mkdir -p /usr/local/share/keyring/ && wget -O /usr/local/share/keyring/devkitpro-pub.gpg https://apt.devkitpro.org/devkitpro-pub.gpg

# Add the devkitPro apt repository if we don't have it set up already
RUN echo "deb [signed-by=/usr/local/share/keyring/devkitpro-pub.gpg] https://apt.devkitpro.org stable main" > /etc/apt/sources.list.d/devkitpro.list

# Finally install devkitPro pacman
RUN apt-get update -y && apt-get install -y devkitpro-pacman
RUN ln -s /proc/self/mounts /etc/mtab

## Install devkitARM tools
RUN dkp-pacman -Sy
RUN dkp-pacman -Sp --print-format '%n' --needed gp32-dev gp2x-dev gba-dev nds-dev 3ds-dev gamecube-dev wii-dev wiiu-dev switch-dev > pkglists.txt
RUN dkp-pacman --noconfirm -S - < pkglists.txt
ENV DEVKITPRO /opt/devkitpro
ENV DEVKITARM $DEVKITPRO/devkitARM
ENV PATH $DEVKITPRO/tools/bin:$DEVKITARM/bin:$PATH

## Create mount points for using this as a tool for compilation
RUN mkdir src && mkdir target
VOLUME ["/src", "/target"]