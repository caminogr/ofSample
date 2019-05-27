  const osc = require('node-osc');
 
const client = new osc.Client('127.0.0.1', 8000);
 
setInterval(() => {
  client.send('/hoge', "Hello!");
  console.log("messege send");
}, 5000);
