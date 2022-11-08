let shapeFraction = 0; // tracks the new shape fraction off serial
let colors = 0; // tracks the new color mode off serial
let serial; // the Serial object
let serialOptions = { baudRate:9600 };
let buttonConnect,buttonDisconnect;
let color1, color2;

function setup() {
  createCanvas(400, 400);
  background(0);
  // Setup Web Serial using serial.js
  serial = new Serial();
  serial.on(SerialEvents.CONNECTION_OPENED, onSerialConnectionOpened);
  serial.on(SerialEvents.CONNECTION_CLOSED, onSerialConnectionClosed);
  serial.on(SerialEvents.DATA_RECEIVED, onSerialDataReceived);
  serial.on(SerialEvents.ERROR_OCCURRED, onSerialErrorOccurred);
 
  // Add in a lil <p> element to provide messages. This is optional
  msg = createP("");
  
  buttonConnect = createButton('Connect Port');
  buttonConnect.position(20,20);
  buttonConnect.mousePressed(connectPort);
  
  buttonDisconnect = createButton('Disonnect Port');
  buttonDisconnect.position(150,20);
  buttonDisconnect.mousePressed(disconnectPort);
  
  color1 = color(255,156,0);
  color2 = color(175,238,238);
}

async function connectPort() {
  if (!serial.isOpen()) {
    await serial.connectAndOpen(null, serialOptions);
  } else {
    serial.autoConnectAndOpenPreviouslyApprovedPort(serialOptions);
  }
}

async function disconnectPort() {
  if (serial.isOpen()) {
    serial.close();
  }
}

function draw() {
  noStroke();
  // set color mode
  if (colors == 0){
    background(255);
    fill(0);
  } else {
    background(0);
    fill(255);
  }
  
  let potCol = lerpColor(color1, color2, shapeFraction); //what we're getting from the arduino, value betw 0 and 1
  fill(potCol);
  // Set the diameter based on mouseX position
  const maxDiameter = min(width, height);
  let circleDiameter = maxDiameter * shapeFraction;
  circle(width / 2, height/2, circleDiameter, 0, width);
}

function onSerialErrorOccurred(eventSender, error) {
  console.log("onSerialErrorOccurred", error);
}

function onSerialConnectionOpened(eventSender) {
  console.log("onSerialConnectionOpened");
}

function onSerialConnectionClosed(eventSender) {
  console.log("onSerialConnectionClosed");
}

function onSerialDataReceived(eventSender, newData) {
  msg.html("onSerialDataReceived: " + newData);
  shapeFraction = parseFloat(newData);
 
  // split incoming String by comma
  if (newData.length != 0) {
    
    // returns the index of comma
    const indexOfComma = newData.indexOf(",");
    console.log(indexOfComma);
     
    // if comma is present in the string
    if (indexOfComma != -1) {
      let strDiameter = newData.substring(0, indexOfComma).trim();
      let strOutline = newData.substring(indexOfComma + 1, newData.length).trim();
      shapeFraction = parseFloat(strDiameter);
      colors = parseInt(strOutline);
    }
  }
}
