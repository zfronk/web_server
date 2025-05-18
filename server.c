#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // Allow socket functions calls
#include <arpa/inet.h> // Conversion of internet protocols
#include <netinet/in.h> // Allow internet structs
#include <string.h>
#include <unistd.h>


// Macro processors 
#define PORT 8080 // Bind socket to port 8080
#define BACKLOG 3 // Allow three connections



// Web server creation!
// Process

// Create socket
// Configure the struct -> address family, Port number and allowed number of addressess and port connections
// Bind the socket to the given port
// Listen for connectons
// Accept connections from other users
// Send data after accepting connections from the different IP's

int main(){
	int server_socket = socket(AF_INET, SOCK_STREAM, 0); // Create socket to the server

	// If return value is less than 0 print error to the file...
	if(server_socket < 0){
		perror("Opps error creating socket server!");  // With perror no need for new line char
		exit(EXIT_FAILURE);

	}

	printf("Great socket server created!\n");

	// Configure the structs address protocols and where they will run!

	struct sockaddr_in server_addr; // Struct to hold the server configuration

	server_addr.sin_port = htons(PORT);
	server_addr.sin_family = AF_INET; // Use IPv4
	server_addr.sin_addr.s_addr = INADDR_ANY; // Bind to the given port on all interfaces 

	// Bind socket to the given port
	if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
		perror("Opps, socket server failed to bind on given port!");
		exit(EXIT_FAILURE);
	}

	printf("Socket bound succesfully!\n");

	// Listen for incoming connections 
	if(listen(server_socket, BACKLOG) < 0){
		perror("Opps failed to listen for incoming connections");
		exit(EXIT_FAILURE);
		
	}

	printf("Server listening on port %d\n", PORT); // Debug message to show server is listening!

	struct sockaddr_in client_addr;
	socklen_t address_len = sizeof(client_addr);

	// & Give me the memory address of this...
	// Accept new client
	// while loop to keep adding new clinets one after the other
	while(1){
		int new_client = accept(server_socket, (struct sockaddr *)&client_addr, &address_len);
			
		if(new_client < 0){
			perror("Opps failed to accept client!");
			exit(EXIT_FAILURE); // Exit the loop
			
			}


		else{
				printf("New client connected succesfully\n");
				
				char *data = "Hello there zfronk here!\n";
				int data_length = strlen(data);
				
				char web_response[1024];
				
				int web_response_size = snprintf(web_response, sizeof(web_response),
															"HTTP/1.1 200 OK\r\n"
							 								"Content-Type:Text/html\r\n"
							 								"Content-Length:%d\r\n"
							 								"\r\n"
							 								"%s", // Where the content stays
							 								data_length,data); 
				
				if(send(new_client, web_response, web_response_size, 0) < 0){
						perror("Content not sent!\n");


					}							
				
				
					close(new_client);
							
				
			}
			
					
	}
		
	return 0;
}
