# Use the latest Ubuntu base image
FROM ubuntu:latest

# Update the package list
RUN apt-get update

# Install the GCC compiler
RUN apt-get install -y gcc

# Install the make build tool
RUN apt-get install -y make

# Install Valgrind for memory debugging
RUN apt-get install -y valgrind

# Clean up package cache to reduce image size
RUN apt-get clean && rm -rf /var/lib/apt/lists/*

# Set the working directory to /mnt
WORKDIR /mnt

# Commands to build the Docker image and run a container:
#   docker build -t ubuntu_valgrind .
#   docker run -it --name ubuntu_valgrind -v /Users/fwahl/code:/mnt ubuntu_valgrind
#   docker start ubuntu_valgrind
#   docker stop ubuntu_valgrind

# Command to run Valgrind for memory debugging:
#   valgrind --leak-check=full ./<program> <argument>
