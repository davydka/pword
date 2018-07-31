require('dotenv').config();

const {
	PWRD_LOCAL,
	OFLED_OFFSET
} = process.env;

const isClient = OFLED_OFFSET !== "127";
const isLocal = PWRD_LOCAL === "true";
const isServer = OFLED_OFFSET === "127";

const apps = [];

if(isClient && !isLocal) {
	apps.push({
		name: 'killofLED',
		script: 'npm',
		watch: false,
		interpreter: 'none',
		args: 'run killofLed',
		autorestart: false
	});

	apps.push({
		name: 'clientSocket',
		script: 'npm',
		watch: false,
		interpreter: 'none',
		args: 'run clientSocket',
		autorestart: true
	});
}

if(isClient) {
	apps.push({
		name: 'displayApp',
		script: 'npm',
		watch: false,
		interpreter: 'none',
		args: 'run displayApp',
		autorestart: true
	});
}

if(isServer) {
	apps.push({
		name: 'serverSocket',
		script: 'npm',
		watch: false,
		interpreter: 'none',
		args: 'run serverSocket',
		autorestart: true
	});
}

module.exports = {
	apps
};
