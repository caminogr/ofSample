const express = require('express');
const app = express();

const osc = require('node-osc');
 
const oscClient = new osc.Client('127.0.0.1', 8000);
 

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
  next();
});

app.post('/api/notify-position', (req, res) => {
  // send (address, x, y, eventType);
  oscClient.send('/mouse/button', 50, 90, "down");
  res.send("OK")
});

app.listen(3000, () => console.log('Example app listening on port 3000!'))
