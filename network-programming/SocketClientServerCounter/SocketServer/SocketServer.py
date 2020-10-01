from socket import *
serverPort = 12000  #Unlikely server port to interfere with other processes
serverSocket = socket(AF_INET,SOCK_STREAM)  #TCP Server
serverSocket.bind(('',serverPort))  #Binds server to system IP address for all kinds of connections
serverSocket.listen(1)  #Listens for single stream
print ('The server is ready to receive...') #Server successfully binded and waiting for connections
while True: #Keeps waiting for new connections after each count
    connectionSocket,addr = serverSocket.accept()   #Accepts connection to client
    sentence = connectionSocket.recv(1024)          #Receives message from client
    charCount = len(sentence.decode())              #Decodes string from client and saves length of it
    connectionSocket.send(str(charCount).encode())  #Encodes count and sends it back to client
    connectionSocket.close()                        #Ends connection to client
