#!/bin/bash
#env GOOS=target-OS GOARCH=target-architecture go build package-import-path
#https://www.digitalocean.com/community/tutorials/how-to-build-go-executables-for-multiple-platforms-on-ubuntu-16-04
#if [[ $1 == "" ]]
#then 
#	echo "Opps you missed to enter the file" 
#	exit 
#fi 
env GOOS=linux GOARCH=386 go tool link -linkmode external -o test_prog ./_obj/test.o 
