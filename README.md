# jsdecodeqr

<https://www.npmjs.org/package/jsdecodeqr> Decode QR code image file using libdecodeqr (Node Addon in C++). Code tested in Ubuntu 12.04

## Install Requirements

	sudo apt-get install libdecodeqr-dev

## Building and Installing

	npm install jsdecodeqr

## Node.js Sample Usage

```js
var jsdecodeqr = require("jsdecodeqr");
jsdecodeqr.decode("/home/six519/test.png");
```