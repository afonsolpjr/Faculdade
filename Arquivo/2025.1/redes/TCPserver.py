from socket import *
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_STREAM)
serverSocket.bind(('',serverPort))
serverSocket.listen(1)
print('The server is ready to receive')
connectionSocket, addr = serverSocket.accept()

while True:
    sentence = connectionSocket.recv(1024).decode()
    if not sentence:
        print("connection closed Server is shutting down.")
        break
    print(f"Received message from {addr}  : {sentence}")
    capitalizedSentence = sentence.upper()
    resposta = input("Digite a resposta: ")
    connectionSocket.send(resposta.encode())
    

connectionSocket.close()