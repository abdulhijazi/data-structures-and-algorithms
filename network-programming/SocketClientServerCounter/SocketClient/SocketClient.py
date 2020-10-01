from socket import *
breakCheck = '1'
while breakCheck != '0': #Used to check if user would like to continue or end session
    serverName = 'localhost'   #IP Address of server, or localhost for same computer testing
    serverPort = 12000              #High socket number unlikely to interfere with other processes
    clientSocket = socket(AF_INET,SOCK_STREAM)  #TCP Client
    clientSocket.connect((serverName,serverPort))   #Connection established with server
    sentence = input('Input sentence for character count: ')    #User inputs sentence for characters to be counted on server
    clientSocket.send(sentence.encode())    #Sentence encoded before sending to server
    charCount = clientSocket.recv(1024)     #Recieves count from server
    print('Server says that the character count is:', charCount.decode())   #Count decoded and displayed
    breakCheck = input('Enter 0 to exit, or any other character to continue: ') #Asks if user would like to continue
    clientSocket.close() #Connection to server terminated
