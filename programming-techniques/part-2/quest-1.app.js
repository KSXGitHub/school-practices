#! /usr/bin/env node

var fac = require('./quest-1.js')
var n = parseInt(require('process').argv[2]) || 0

console.log('n! = ', fac(n))
