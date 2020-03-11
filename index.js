/* const addon = require('./build/Release/greet.node');
console.log(addon.greetHello('boom shakalaka')); */

// -------------------------------------------------

/* const callback = require('bindings')('callback');
callback(function (arg) {
  console.log(arg);
}); */

// -------------------------------------------------

/* const { MyObject } = require('bindings')('object-wrap');
var obj = new MyObject(10);
console.log( obj.plusOne() ); // 11
console.log( obj.plusOne() ); // 12
console.log( obj.plusOne() ); // 13

console.log( obj.multiply().value() ); // 13
console.log( obj.multiply(10).value() ); // 130

var newobj = obj.multiply(-1);
console.log( newobj.value() ); // -13
console.log( obj === newobj ); // false */

// -------------------------------------------------

const addon = require('bindings')('aclas-sdk');

const sdk = new addon.AclasSdk();
const initialize = sdk.initialize();
const finalize = sdk.finalize();
const info = sdk.getInfo();
const exec = sdk.execTaskWithCB(function () {
  console.log(arguments);
});
console.log(initialize, finalize, info, exec);
