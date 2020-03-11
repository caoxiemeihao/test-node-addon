// const addon = require('./build/Release/greet.node');
const callback = require('bindings')('callback');

// console.log(addon.greetHello('boom shakalaka'));

callback(function (arg) {
  console.log(arg);
});
