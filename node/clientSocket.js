require('dotenv').config();

// do nothing if not a client
if(process.env.OFLED_OFFSET === "127") {
	console.log('server');
	while(1) {
	}
}

const WS = require('ws');
const ReconnectingWebSocket = require('reconnecting-websocket');

const ws = new ReconnectingWebSocket('ws://bluerose.local:8080', [], {
	WebSocket: WS,
	// debug: true,
	// connectionTimeout: 1000,
	// reconnectInterval: 1000
});

ws.addEventListener('open', () => {
	console.log('open');
});

ws.addEventListener('message', ({data}) => {
	console.log(data);
});

ws.addEventListener('close', () => ws._shouldReconnect && ws._connect());
