  const osc = require('node-osc');
 
const client = new osc.Client('127.0.0.1', 8000);
 
setInterval(() => {
  // send (address, x, y, eventType);
  client.send('/mouse/button', 50, 90, "down");
  console.log("messege send");
}, 5000);
