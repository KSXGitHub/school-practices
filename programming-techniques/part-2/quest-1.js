
var fac = n => n ? n * fac(n - 1) : 1;

module.exports = fac;
