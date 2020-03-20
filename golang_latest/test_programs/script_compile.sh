#!/bin/bash
#env GOOS=target-OS GOARCH=target-architecture go build package-import-path
#https://www.digitalocean.com/community/tutorials/how-to-build-go-executables-for-multiple-platforms-on-ubuntu-16-04
env GOOS=linux GOARCH=386 go build .
