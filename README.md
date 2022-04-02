![Badge tracking project size](https://img.shields.io/github/repo-size/Preffet/CPP-Remote-enumeration?color=%232b4fc4)![Badge tracking code size](https://img.shields.io/github/languages/code-size/Preffet/CPP-Remote-enumeration?color=%23472bc4)![Badge tracking last commit](https://img.shields.io/github/last-commit/Preffet/CPP-Remote-enumeration?color=%23782bc4)

-----------------------------------------------------------------------------

![banner](https://user-images.githubusercontent.com/84241003/161380249-1415587e-a8ac-4750-80e4-bd373ed06667.png)

-----------------------------------------------------------------------------
### Description

The code reads the content of the files in the home directory of the victim and sends it to the attacker machine via a TCP connection using 5555 port.

### How to build and run the project
The user has to set up a listener (for example, using netcat) on port 5555. 
This can be done via terminal:
```
nc -lvp 5555
```
And then update the ip address and run the compiled code on the remote machine in order to receive the information. 
