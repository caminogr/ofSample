const express = require('express');
const bodyParser = require('body-parser');

const app = express();

const osc = require('node-osc');
 
const oscClient = new osc.Client('127.0.0.1', 8000);
 
app.use(bodyParser.urlencoded({
  extended: true
}));
app.use(bodyParser.json());

app.use((req, res, next) => {
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Headers', 'Origin, X-Requested-With, Content-Type, Accept');
  next();
});

app.post('/api/notify-position', (req, res) => {
  // = req.position??
  const {x, y} = position;
  oscClient.send('/mouse/button', x, y, "down");
  res.send("OK")
});

app.post('/api/post-text', (req, res) => {
  const { text } = req.body;
  oscClient.send('/input/text', text);
  res.send("OK")
});

app.listen(3000, () => console.log('Example app listening on port 3000!'))
