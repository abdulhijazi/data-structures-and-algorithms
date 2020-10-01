from html.parser import HTMLParser
class parseIndex(HTMLParser):
    def handle_starttag(self, tag, attrs):
        if tag=="img":                      #loops until all links are found and downloaded
            imgName=(dict(attrs)['src'])    #returns sources of images
            imgRequest ='GET /'+imgName+' HTTP/1.1\r\nHost:%s\r\n\r\n' % serverName
            imgNameindx=imgName.rfind("/")  #finds last slash in path name so that
            imgName=imgName[(imgNameindx+1)::]  #last slash until end of line should be the file name
            clientSocket = socket(AF_INET,SOCK_STREAM)     #connection to be restablished
            clientSocket.connect((serverName, serverPort))
            clientSocket.send(imgRequest.encode())      #decodes first reply, which is the header, to find content-length
            imgReply = clientSocket.recv(1024).decode()
            print(imgReply)                             #shows headers from host on screen
            indexnum=imgReply.find("Content-Length")    #searches for content length just like in the first instance
            spacenum=imgReply.find(" ",indexnum)
            endlinenum=imgReply.find("\r\n",indexnum)
            scontlen1=imgReply[(spacenum+1):endlinenum]
            contlen1=int(scontlen1)
            imgfile=open("%s" % imgName,"wb")       #creates file with same name from host, binary because it is an image
            imgfile.close()
            while len(imgReply) > 0:                #continues to download until no reply from host 
                imgReply = clientSocket.recv(contlen1)
                imgfile=open("%s" % imgName,"ab")   #append so that program only adds to end of file
                imgfile.write(imgReply)
                imgfile.close()
            clientSocket.close()                    #connection terminated for each image



from socket import *
breakCheck = '1'
while breakCheck != '0': #Used to check if user would like to continue or end session
    serverName = input('Input the host name of the webpage you would like to download: ')
    getRequest ="GET / HTTP/1.1\r\nHost:%s\r\n\r\n" % serverName    #standard HTTP 1.1 Get request, host name is added in
    serverPort = 80              #HTTP Socket Number
    clientSocket = socket(AF_INET,SOCK_STREAM)  #TCP Client
    clientSocket.connect((serverName, serverPort))  #Establishes connection with host
    clientSocket.send(getRequest.encode())  #encodes request and sends it to host
    getReply = clientSocket.recv(1024).decode() #decodes first response, which is the header that contains the content-length
    indexnum=getReply.find("Content-Length") #searches for content length index
    spacenum=getReply.find(" ",indexnum) #first space after content length
    endlinenum=getReply.find("\r\n",indexnum) #finding end of line
    scontlen=getReply[(spacenum+1):endlinenum] #content length should be between these values
    contlen=int(scontlen)   #convert content length to integer
    basefile=open("%s-index.html" % serverName,"w") #creates file then closes it, deletes existing one with same name
    basefile.close()
    while len(getReply) > 0 :   #continues to decode replies from host until there is no reply
        getReply = clientSocket.recv(contlen).decode()
        basefile=open("%s-index.html" % serverName,"a") #appends file so that it adds to the bottom of file
        basefile.write(getReply)    #writes html code to index file
    basefile.close() 
    clientSocket.close()    #ends this connection with host
    basefile=open("%s-index.html" % serverName,"r")     #opens the same html file for reading, for parsing
    checkImg=parseIndex()
    checkImg.feed(basefile.read())  #html code sent for parsing to find images
    print("Webpage downloaded!")
    breakCheck = input('Enter 0 to exit, or any other character to continue: ')
