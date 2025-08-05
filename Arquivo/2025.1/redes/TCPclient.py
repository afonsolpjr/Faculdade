from socket import *
serverName = 'servername'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((serverName,serverPort))

while True:
    sentence = input('Input lowercase sentence:')
    if sentence == 'exit':
        break
    clientSocket.send(sentence.encode())
    modifiedSentence = clientSocket.recv(1024)
    print('From Server: ', modifiedSentence.decode())
clientSocket.close()