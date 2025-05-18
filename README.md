# Simple C Web Server

A minimalist web server written in C using raw sockets. This project demonstrates the basics of how web servers operate at the socket level by:

- Creating and binding a TCP socket to a port (default: 8080)
- Listening for and accepting incoming client connections
- Parsing basic HTTP GET requests
- Sending HTTP responses with headers and static content
- Closing connections after response delivery

This server serves static HTTP responses with minimal parsing to keep the implementation straightforward and educational. It’s an excellent foundation for anyone wanting to understand the low-level workings of HTTP and TCP communication without relying on external libraries or frameworks.

### Future improvements
- Serving actual files (e.g., HTML, CSS, images)
- Handling multiple HTTP methods (GET, POST, etc.)
- Supporting concurrent connections with threading or non-blocking sockets

Built with a focus on traditional socket programming principles — perfect for learning, experimentation, and expanding into more complex network applications.

---

Feel free to clone, experiment, and build upon this simple foundation!

