const net = require('net');

const serverPort = 3000;  // Porta do servidor

const server = net.createServer((socket) => {
  console.log('Cliente conectado.');

  socket.on('data', (data) => {
    console.log('Dados recebidos do cliente:');
    console.log(data.toString());
    const message = 'Mensagem recebida com sucesso!\n';
    socket.write(message);
  });

  socket.on('end', () => {
    console.log('Cliente desconectado.');
  });
});

server.on('error', (err) => {
  console.error('Erro no servidor:', err);
});

server.listen(serverPort, () => {
  console.log('Servidor aguardando conexões na porta', serverPort);
});